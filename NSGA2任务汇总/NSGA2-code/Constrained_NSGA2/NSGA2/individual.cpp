#include "individual.h"
#include "problem.h"
#include "rand_R_I.h"


//问题函数值的计算：
void individual::f_count()
{
    //CONSTR_count(*this);
    //SRN_count(*this);
    TNK_count(*this);
    //WATER_count(*this);
}

//个体初始化：
void individual::init()
{

    //CONSTR_init(*this);
    //SRN_init(*this);
    TNK_init(*this);
    //WATER_init(*this);
}