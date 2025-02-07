#include "population.h"
#include "globals.h"

void population::f_sort(int i)
{
    int n;
    n = len[i];
    qsort(F[i], n, sizeof(individual), cmp_c_d);
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

void population::variable_bound_correct(double& x) {
    if(x>upper_bound)
        x=upper_bound-(1e-6);
    if(x<lower_bound)
        x=lower_bound+(1e-6);
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
                
                variable_bound_correct(Q[i].value[j]);

                if (i + 1 < popsize)
                {
                    Q[i + 1].value[j] = 1.0 / 2 * ((1 + b) * P[temp1[x]].value[j] + (1 - b) * P[temp1[y]].value[j]);
                    variable_bound_correct(Q[i + 1].value[j]);
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
                Q[i].value[j] = P[temp1[x]].value[j] + (upper_bound - lower_bound) * u;
                variable_bound_correct(Q[i].value[j]);
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
bool e_is_dominated(const individual& a, const individual& b)
{
    if ((a.fvalue[0] <= b.fvalue[0]) && (a.fvalue[1] <= b.fvalue[1]))
    {
        if ((a.fvalue[0] == b.fvalue[0]) && a.fvalue[1] == b.fvalue[1])
            return false;
        else
            return true;
    }
    else
        return false;
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
    F[i][0].crowding_distance = F[i][n - 1].crowding_distance = 0xffffff;
    qsort(F[i], n, sizeof(individual), cmp1);
    m_max = -0xfffff;
    m_min = 0xfffff;
    for (j = 0; j < n; j++)
    {
        if (m_max < F[i][j].fvalue[0])
            m_max = F[i][j].fvalue[0];
        if (m_min > F[i][j].fvalue[0])
            m_min = F[i][j].fvalue[0];
    }
    for (j = 1; j < n - 1; j++)
        F[i][j].crowding_distance += (F[i][j + 1].fvalue[0] - F[i][j - 1].fvalue[0]) / (m_max - m_min);
    F[i][0].crowding_distance = F[i][n - 1].crowding_distance = 0xffffff;
    qsort(F[i], n, sizeof(individual), cmp2);
    m_max = -0xfffff;
    m_min = 0xfffff;
    for (j = 0; j < n; j++)
    {
        if (m_max < F[i][j].fvalue[1])
            m_max = F[i][j].fvalue[1];
        if (m_min > F[i][j].fvalue[1])
            m_min = F[i][j].fvalue[1];
    }
    for (j = 1; j < n - 1; j++)
        F[i][j].crowding_distance += (F[i][j + 1].fvalue[1] - F[i][j - 1].fvalue[1]) / (m_max - m_min);
}


//采集多样性的选择：
int population::choice(int a, int b)
{
    if (P[a].rank < P[b].rank)
        return a;
    else if (P[a].rank == P[b].rank)
    {
        if (P[a].crowding_distance > P[b].crowding_distance)
            return a;
        else
            return b;
    }
    else
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
