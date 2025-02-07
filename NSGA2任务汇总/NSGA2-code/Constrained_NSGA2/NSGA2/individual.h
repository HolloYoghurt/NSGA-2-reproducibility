#pragma once
#include "common.h"
//个体的类声明：
class individual
{
public:
    double value[Dimension];//xi的值
    int sp[2 * popsize];
    //被支配个体集合SP。该量是可行解空间中所有被个体p支配的个体组成的集合。
    int np;
    //支配个数np。该量是在可行解空间中可以支配个体p的所以个体的数量。
    int is_dominated;//集合sp的个数
    void init();//初始化个体
    int rank;//优先级，Pareto级别为当前最高级
    double crowding_distance;//拥挤距离
    double fvalue[Objective_number];//问题目标函数的值
    void f_count();//计算fvalue的值

    double gvalue[Gnum];//g函数的值
    bool is_feasible;
    double total_violation;
};
