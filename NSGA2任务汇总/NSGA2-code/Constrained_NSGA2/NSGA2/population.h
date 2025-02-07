#pragma once
#include"individual.h"
#include "common.h"
#include "rand_R_I.h"
#include "all_cmp.h"


//群体的类声明：
class population
{
public:
    population();//类初始化
    individual P[popsize];
    individual Q[popsize];
    individual R[2 * popsize];
    void set_p_q();
    //随机产生一个初始父代P，在此基础上采用二元锦标赛选择、
    //交叉和变异操作产生子代Q。P和Q群体规模均为popsize
    //将Pt和Qt并入到Rt中（初始时t=0），对Rt进行快速非支配解排序，
    //构造其所有不同等级的非支配解集F1、F2........
    int Rnum;
    int Pnum;
    int Qnum;
    //P,Q,R中元素的个数
    void make_new_pop();//产生新的子代
    void fast_nondominated_sort();//快速非支配排序
    void calu_crowding_distance(int i);//拥挤距离计算
    void f_sort(int i);//对拥挤距离降序排列
    void maincal();//主要操作
    int choice(int a, int b);
    void variable_bound_correct(double &x, int i);//变量边界处理
    //两个个体属于不同等级的非支配解集，优先考虑等级序号较小的
    //若两个个体属于同一等级的非支配解集，优先考虑拥挤距离较大的
    int len[2 * popsize];//各个变异交叉后的群体Fi的长度的集合，len[i]表示ranki的长度
    int len_f;//整个群体rank值
};