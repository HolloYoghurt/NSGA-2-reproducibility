#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<math.h>
#include<time.h>
#include<vector>
#include<iostream>

#define Dimension 2//基因维数
#define popsize 100//种群大小
#define generation 500 //繁衍代数
#define URAND (rand()/(RAND_MAX+1.0))//产生随机数
#define M_PI 3.14159265358979323846
#define Crossover 0.9//交叉概率
#define Mutation (1.0/Dimension)//变异概率
#define eta_c 20 //SBX的交叉参数
#define eta_m 20 //PM的变异参数
#define Gnum 2//约束条件个数
#define Objective_number 2//目标函数个数

const double Lower_bound[Dimension] = { 0.0 , 0.0 }; // 每个变量的下界
const double Upper_bound[Dimension] = { M_PI , M_PI }; // 每个变量的上界
//const double Water_normalized[Objective_number] = {8e4,1500.0,3e6,6e6,8e3}; // 水的归一化

//以上两个数组用于产生新的子代
using namespace std;
