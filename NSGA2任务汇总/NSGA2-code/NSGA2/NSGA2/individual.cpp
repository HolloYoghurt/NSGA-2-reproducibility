#include "individual.h"
#include "problem.h"
#include "rand_R_I.h"


//ZDT1问题函数值的计算：
void individual::f_count()
{
    //ZDT1_count(*this);
    //ZDT2_count(*this);
    //ZDT3_count(*this);
    //ZDT4_count(*this);
    //ZDT6_count(*this);
    
    //SCH_count(*this);
    
    //FON_count(*this);

    //POL_count(*this);

    KUR_count(*this);
}

//个体初始化：
void individual::init()
{
    //ZDT1236_init(*this);
    //ZDT4_init(*this);

    //SCH_init(*this);

    //FON_init(*this);

    //POL_init(*this);

    KUR_init(*this);

}