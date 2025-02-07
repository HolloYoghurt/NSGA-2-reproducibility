#include "globals.h"

int temp1[popsize];//临时数组
int mark[popsize];//标记数组,用来标记进行二进制锦标赛的个体是否被访问过

individual F[2 * popsize][2 * popsize];//F[i][j]表示rank为i的第j个个体，用来存储非支配排序后的个体