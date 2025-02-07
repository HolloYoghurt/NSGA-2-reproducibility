#include "common.h"
#include "individual.h"
#include "population.h"
#include "rand_R_I.h"
#include "all_cmp.h"


//更改问题需要更改：
//变量【main.cpp】file; 改变文件名
//变量【common.h】Dimension; 改变维度
//变量【common.h】upper_bound; 改变上界 lower_bound; 改变下界
//变量【common.h】Gnum; //约束条件的个数
//变量【common.h】objective_number; //目标函数的个数; //约束条件
//变量【common.h】eta_m//PM的变异参数
//函数【individual.cpp】f_count(); 改变目标函数
//函数【individual.cpp】init(); 改变初始化范围
//对于WATER问题，需要更改46行的输出，对于(i,j)进行输出

//设置读取命名
string file = "TNK";
//设置读取路径
string path = "D:\\Desktop\\postgraduate_study\\work\\10.15\\code\\Constrained_data\\";

void water_file_pushback(vector<FILE*> &v) {
    v.push_back(fopen((path + file + "_f1_f2" + "_plot.txt").c_str(), "w+"));
    v.push_back(fopen((path + file + "_f1_f3" + "_plot.txt").c_str(), "w+"));
    v.push_back(fopen((path + file + "_f1_f4" + "_plot.txt").c_str(), "w+"));
    v.push_back(fopen((path + file + "_f1_f5" + "_plot.txt").c_str(), "w+"));
    v.push_back(fopen((path + file + "_f2_f3" + "_plot.txt").c_str(), "w+"));
    v.push_back(fopen((path + file + "_f2_f4" + "_plot.txt").c_str(), "w+"));
    v.push_back(fopen((path + file + "_f2_f5" + "_plot.txt").c_str(), "w+"));
    v.push_back(fopen((path + file + "_f3_f4" + "_plot.txt").c_str(), "w+"));
    v.push_back(fopen((path + file + "_f3_f5" + "_plot.txt").c_str(), "w+"));
    v.push_back(fopen((path + file + "_f4_f5" + "_plot.txt").c_str(), "w+"));
}

void water_file_write(vector<FILE*>& v, population& pop, int i) {
    int idx = 0;
    for (int k = 1; k <= 4; ++k) {
        for (int l = k + 1; l <= 5; ++l) {
            fprintf(v[idx], "f%d(x)=%f   f%d(x)=%f\n", k, pop.P[i].fvalue[k - 1], l, pop.P[i].fvalue[l - 1]);
            ++idx;
        }
    }
}

//void water_normalized(population &pop,int i) {
//    for (int j = 0; j < 5; j++) {
//        pop.P[i].fvalue[j] /= Water_normalized[j];
//    }
//}

//主函数：
int main()
{
    FILE* p, * p1;
    string filename = path + file + ".txt";
    string filename1 =path + file + "_plot.txt";//通用问题输出专用

    //vector<FILE*> v;//WATER问题输出专用
    //water_file_pushback(v);

    p = fopen(filename.c_str(), "w+");
    p1= fopen(filename1.c_str(), "w+");//通用问题输出专用
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
        fprintf(p, "f1(x)=%f   f2(x)=%f\n", pop.P[i].fvalue[0], pop.P[i].fvalue[1]); //普通问题输出全部专用
        fprintf(p1, "f1(x)=%f   f2(x)=%f\n", pop.P[i].fvalue[0], pop.P[i].fvalue[1]); //普通问题输出局部专用
        
        //WATER问题输出全部专用
        //water_normalized(pop, i);
        //fprintf(p, "f1(x)=%f   f2(x)=%f   f3(x)=%f   f4(x)=%f   f5(x)=%f\n", pop.P[i].fvalue[0], pop.P[i].fvalue[1], pop.P[i].fvalue[2], pop.P[i].fvalue[3], pop.P[i].fvalue[4]);
        //water_file_write(v, pop, i); //WATER问题输出局部专用

        
    }
    fclose(p);
    return 1;
}