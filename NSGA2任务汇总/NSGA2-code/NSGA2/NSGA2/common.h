#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<math.h>
#include<time.h>
#include<iostream>
#define Dimension 3//基因维数
#define popsize 100//种群大小
#define generation 500 //繁衍代数
#define URAND (rand()/(RAND_MAX+1.0))//产生随机数
#define M_PI 3.14159265358979323846
#define Crossover 0.9//交叉概率
#define Mutation (1.0/Dimension)//变异概率
//#define Mutation 0.2//变异概率
#define eta_c 20 //SBX的交叉参数
#define eta_m 20 //PM的变异参数
#define lower_bound -5.0//基因下界
#define upper_bound 5.0//基因上界

//以上两个数组用于产生新的子代
using namespace std;
