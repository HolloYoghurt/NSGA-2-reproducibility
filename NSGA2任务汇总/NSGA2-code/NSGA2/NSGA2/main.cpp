#include "common.h"
#include "individual.h"
#include "population.h"
#include "rand_R_I.h"
#include "all_cmp.h"


//更改问题需要更改：
//变量【main.cpp】file; 改变文件名
//变量【common.h】Dimension; 改变维度
//变量【common.h】upper_bound; 改变上界 lower_bound; 改变下界
//函数【individual.cpp】f_count(); 改变目标函数
//函数【individual.cpp】init(); 改变初始化范围


//设置读取命名
string file = "KUR";
//设置读取路径
string path = "D:\\Desktop\\postgraduate_study\\work\\10.15\\code\\data\\";

//主函数：
int main()
{
    FILE* p, * p1;
    string filename = path + file + ".txt";
    string filename1 =path + file + "_plot.txt";

    p = fopen(filename.c_str(), "w+");
    p1= fopen(filename1.c_str(), "w+");
    srand((unsigned int)(time(0)));
    population pop;
    pop.maincal();
    int i, j;

    for (i = 0; i < popsize; i++)
    {
        fprintf(p, "The %d generation situation:\n", i);
        for (j = 1; j <= Dimension; j++)
        {
            fprintf(p, "x%d=%e  ", j, pop.P[i].value[j]);
        }
        fprintf(p, "\n");
        fprintf(p, "f1(x)=%f   f2(x)=%f\n", pop.P[i].fvalue[0], pop.P[i].fvalue[1]);
        fprintf(p1, "f1(x)=%f   f2(x)=%f\n", pop.P[i].fvalue[0], pop.P[i].fvalue[1]);
    }
    fclose(p);
    return 1;
}