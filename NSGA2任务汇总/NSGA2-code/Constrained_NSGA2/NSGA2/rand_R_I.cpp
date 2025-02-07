#include "rand_R_I.h"

//部分函数声明：
double rand_real(double low, double high)
//产生随机实数
{
    double h;
    h = (high - low) * URAND + low + 0.001;
    if (h >= high)
        h = high - 0.001;
    return h;
}

int rand_int(int low, int high)
//产生随机整数
{
    return int((high - low + 1) * URAND) + low;
}