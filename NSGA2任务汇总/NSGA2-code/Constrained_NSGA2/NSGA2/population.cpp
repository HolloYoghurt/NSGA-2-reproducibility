#include "population.h"
#include "globals.h"

void population::f_sort(int i)
{
    int n;
    n = len[i];
    
    if(F[i][0].is_feasible) qsort(F[i], n, sizeof(individual), cmp_c_d);
    else qsort(F[i], n, sizeof(individual), cmp_v_c_d);
    
}


//群的初始化：
population::population()
{
    int i;
    for (i = 0; i < popsize; i++)
    {
        P[i].init();
    }
    for (i = 0; i < popsize; i++)
    {
        P[i].f_count();
    }
    Pnum = popsize;
    Qnum = 0;
    Rnum = 0;
}

void population::variable_bound_correct(double& x, int i) {
    if(x>Upper_bound[i])
        x=Upper_bound[i] - (1e-6);
    if(x<Lower_bound[i])
        x=Lower_bound[i] + (1e-6);
}

//利用二进制锦标赛产生子代：
void population::make_new_pop()
{
    int i, j, x, y, t1, t2, t3;
    double s, u, b;
    memset(mark, 0, sizeof(mark));
    t3 = 0;
    while (t3 < popsize / 2)//二进制锦标赛产生种群大小一半的子代
    {
        while (t1 = t2 = rand_int(0, popsize - 1), mark[t1]);
        while (t1 == t2 || mark[t2])
        {
            t2 = rand_int(0, popsize - 1);
        }
        t1 = choice(t1, t2);
        temp1[t3++] = t1;
        mark[t1] = 1;
    }
    for (i = 0; i < popsize;)//在锦标赛中的胜者中随机选择两个个体进行交叉、变异，直到产生种群大小个个体
    {
        s = rand_real(0.0, 1.0);
        if (s <= Crossover)//交叉操作
        {
            for (j = 0; j < Dimension; j++)
            {
                u = rand_real((0.0 + 1e-6), (1.0 - 1e-6));
                if (u <= 0.5)
                    b = pow(2 * u, 1.0 / (eta_c+1));
                else
                    b = 1.0 / pow(2 * (1 - u), 1.0 / (eta_c + 1));
                x = y = rand_int(0, popsize / 2 - 1);
                while (x == y)
                    y = rand_int(0, popsize / 2 - 1);
                Q[i].value[j] = 1.0 / 2 * ((1 - b) * P[temp1[x]].value[j] + (1 + b) * P[temp1[y]].value[j]);
                
                variable_bound_correct(Q[i].value[j],j);

                if (i + 1 < popsize)
                {
                    Q[i + 1].value[j] = 1.0 / 2 * ((1 + b) * P[temp1[x]].value[j] + (1 - b) * P[temp1[y]].value[j]);
                    variable_bound_correct(Q[i + 1].value[j],j);
                }
            }
            i+=2;
        }
        s = rand_real(0.0, 1.0);
        if(s <= Mutation)//变异操作
        {
            for (j = 0; j < Dimension; j++)
            {
                x = rand_int(0, popsize / 2 - 1);
                u = rand_real(0.0 + (1e-6), 1.0 - (1e-6));
                if (u < 0.5)
                    u = pow(2 * u, 1.0 / (eta_m+1)) - 1;
                else
                    u = 1 - pow(2 * (1 - u), 1.0 / (eta_m+1));

                Q[i].value[j] = P[temp1[x]].value[j] + (Upper_bound[j] - Lower_bound[j]) * u;
                variable_bound_correct(Q[i].value[j],j);
            }
            i++;
        }
    }
    Qnum = popsize;
    for (i = 0; i < popsize; i++)
        Q[i].f_count();
}


void population::set_p_q()
{
    Rnum = 0;
    Qnum = popsize;
    int i;
    for (i = 0; i < Pnum; i++)
        R[Rnum++] = P[i];
    for (i = 0; i < Qnum; i++)
        R[Rnum++] = Q[i];
    for (i = 0; i < 2 * popsize; i++)
        R[i].f_count();
}


//判断目标函数值是否被支配：
bool e_is_dominated(const individual& a, const individual& b) {
    // 检查约束条件
    if (a.is_feasible && !b.is_feasible) {
        return true; // a 满足约束条件，b 不满足，a 支配 b
    }
    else if (!a.is_feasible && b.is_feasible) {
        return false; // a 不满足约束条件，b 满足，a 被支配
    }
    else if (a.is_feasible && b.is_feasible) {
        // 两个个体都满足约束条件，按目标函数值进行比较
        bool a_better = false;
        for (int i = 0; i < Objective_number; ++i) {
            if (a.fvalue[i] > b.fvalue[i]) {
                return false; // a 的某个目标函数值不如 b，a 不能支配b
            }
            if (a.fvalue[i] < b.fvalue[i]) {
                a_better = true;// a 的某个目标函数值优于 b
            }
        }
        return a_better; // a 的目标函数值优于 b，a 支配 b
    }
    else {
        // 两个个体都不满足约束条件，按总体约束违反程度进行比较
        if (a.total_violation < b.total_violation) {
            return true; // a 的总体约束违反程度较小，a 支配 b
        }
        else if (a.total_violation > b.total_violation) {
            return false; // a 的总体约束违反程度较大，a 被支配
        }
        else {
            // 总体约束违反程度相同，按目标函数值进行比较
            bool a_better = false;
            for (int i = 0; i < Objective_number; ++i) {
                if (a.fvalue[i] > b.fvalue[i]) {
                    return false; // a 的某个目标函数值不如 b，a不能 支配b
                }
                if (a.fvalue[i] < b.fvalue[i]) {
                    a_better = true;// a 的某个目标函数值优于 b
                }
            }
            return a_better; // a 的目标函数值优于 b，a 支配 b
        }
    }
}


//快速非支配排序法：
void population::fast_nondominated_sort()
{
    int i, j, k;
    individual H[2 * popsize];//用来临时存储非支配层
    int h_len = 0;
    for (i = 0; i < 2 * popsize; i++)
    {
        R[i].np = 0;
        R[i].is_dominated = 0;
        len[i] = 0;
    }
    for (i = 0; i < 2 * popsize; i++)
    {
        for (j = 0; j < 2 * popsize; j++)
        {
            if (i != j)
            {
                if (e_is_dominated(R[i], R[j]))
                    R[i].sp[R[i].is_dominated++] = j;
                else if (e_is_dominated(R[j], R[i]))
                    R[i].np += 1;
            }
        }
        if (R[i].np == 0)
        {
            len_f = 1;
            R[i].rank = 1;
            F[0][len[0]++] = R[i];
        }
    }
    i = 0;
    while (len[i] != 0)
    {
        h_len = 0;
        for (j = 0; j < len[i]; j++)
        {
            for (k = 0; k < F[i][j].is_dominated; k++)
            {
                R[F[i][j].sp[k]].np--;
                if (R[F[i][j].sp[k]].np == 0)
                {
                    R[F[i][j].sp[k]].rank = i + 2;
                    H[h_len++] = R[F[i][j].sp[k]];
                }
            }
        }
        i++;
        len[i] = h_len;
        if (h_len != 0)
        {
            len_f++;
            for (j = 0; j < len[i]; j++)
                F[i][j] = H[j];
        }
    }
}


//计算拥挤距离：
void population::calu_crowding_distance(int i)
{
    int n = len[i];
    double m_max, m_min;
    int j;

    for (j = 0; j < n; j++)
        F[i][j].crowding_distance = 0;

    for (int objective_index = 0; objective_index < Objective_number; ++objective_index)
    {
        F[i][0].crowding_distance = F[i][n - 1].crowding_distance = 0xffffff;

        if(objective_index==0) qsort(F[i], n, sizeof(individual), cmp1);
        else if(objective_index==1) qsort(F[i], n, sizeof(individual), cmp2);
        else if(objective_index==2) qsort(F[i], n, sizeof(individual), cmp3);
        else if(objective_index==3) qsort(F[i], n, sizeof(individual), cmp4);
        else if(objective_index==4) qsort(F[i], n, sizeof(individual), cmp5);

        m_max = -0xfffff;
        m_min = 0xfffff;
        for (j = 0; j < n; j++)
        {
            if (m_max < F[i][j].fvalue[objective_index])
                m_max = F[i][j].fvalue[objective_index];
            if (m_min > F[i][j].fvalue[objective_index])
                m_min = F[i][j].fvalue[objective_index];
        }
        for (j = 1; j < n - 1; j++)
            F[i][j].crowding_distance += (F[i][j + 1].fvalue[objective_index] - F[i][j - 1].fvalue[objective_index]) / (m_max - m_min);
    }

}


//采集多样性的选择：
int population::choice(int a, int b)
{
    // 检查可行性
    if (P[a].is_feasible && !P[b].is_feasible) {
        return a; // a 是可行解，b 是不可行解，选择 a
    }
    else if (!P[a].is_feasible && P[b].is_feasible) {
        return b; // a 是不可行解，b 是可行解，选择 b
    }
    else if (!P[a].is_feasible && !P[b].is_feasible) {
        // 如果两个解都不满足约束条件，按总体约束违反程度进行比较
        if (P[a].total_violation < P[b].total_violation) {
            return a; // a 的总体约束违反程度较小，选择 a
        }
        else if (P[a].total_violation > P[b].total_violation) {
            return b; // b 的总体约束违反程度较小，选择 b
        }
    }

    // 如果两个解都满足约束条件或总体约束违反程度相同，按秩进行比较
    if (P[a].rank < P[b].rank) {
        return a; // a 的秩较低，选择 a
    }
    else if (P[a].rank == P[b].rank) {
        // 如果秩相同，按拥挤距离进行比较
        if (P[a].crowding_distance > P[b].crowding_distance) {
            return a; // a 的拥挤距离较大，选择 a
        }
    }

    // 其他情况下选择 b
    return b;
}


//主要操作函数：
void population::maincal()
{
    int s, i, j;
    s = generation;
    make_new_pop();
    while (s--)
    {
        if (s % 100 == 0) printf("The %d generation\n", s);
        set_p_q();
        fast_nondominated_sort();
        Pnum = 0;
        i = 0;
        while (Pnum + len[i] <= popsize)//选择一层，直到P无法选完一层
        {
            calu_crowding_distance(i);
            for (j = 0; j < len[i]; j++)
                P[Pnum++] = F[i][j];
            i++;
            if (i >= len_f)break;
        }
        if (i < len_f)
        {
            calu_crowding_distance(i);
            f_sort(i);
        }
        int PPnum = Pnum;
        for (j = 0; j < popsize - PPnum; j++)//选择一层中的个体，直到P选完
            P[Pnum++] = F[i][j];
        make_new_pop();
    }
}
