#include "problem.h"
#include "rand_R_I.h"

void check_feasible(individual& ind) {
    // 检查是否满足所有约束条件
    ind.is_feasible = true;
    ind.total_violation = 0;
    for (int i = 0; i < Gnum; ++i) {
        if (ind.gvalue[i] > 0) {
            ind.is_feasible = false;
        }
        ind.total_violation += ind.gvalue[i];
    }
}

//注：用正数代表约束条件违反程度，用负数代表约束条件满足程度，故此处公式为反的
void CONSTR_count(individual& ind) {
    // 计算目标函数值
    ind.fvalue[0] = ind.value[0];
    ind.fvalue[1] = (1 + ind.value[1]) / ind.value[0];

    // 计算约束条件值
    ind.gvalue[0] = 6 - ind.value[1] - 9 * ind.value[0];
    ind.gvalue[1] = 1 + ind.value[1] - 9 * ind.value[0];

    check_feasible(ind);
}


void SRN_count(individual& ind) {
    // 计算目标函数值
    ind.fvalue[0] = pow(ind.value[0] - 2, 2) + pow(ind.value[1] - 1, 2) + 2;
    ind.fvalue[1] = 9 * ind.value[0] - pow(ind.value[1] - 1, 2);

    // 计算约束条件值
    ind.gvalue[0] = pow(ind.value[0], 2) + pow(ind.value[1], 2) - 225;
    ind.gvalue[1] = ind.value[0] - 3 * ind.value[1] + 10;

    check_feasible(ind);
}

// 计算TNK问题的目标函数值和约束条件值
void TNK_count(individual& ind) {
    // 计算目标函数值
    ind.fvalue[0] = ind.value[0];
    ind.fvalue[1] = ind.value[1];

    // 计算约束条件值
    ind.gvalue[0] = -pow(ind.value[0], 2) - pow(ind.value[1], 2) + 1 + 0.1 * cos(16 * atan2(ind.value[0], ind.value[1]));
    ind.gvalue[1] = pow(ind.value[0] - 0.5, 2) + pow(ind.value[1] - 0.5, 2) - 0.5;

    check_feasible(ind);
}

//***需要检查看有没有问题
void WATER_count(individual& ind) {
    // 计算目标函数值
    ind.fvalue[0] = 106780.37 * (ind.value[1] + ind.value[2]) + 61704.67;
    ind.fvalue[1] = 3000 * ind.value[0];
    ind.fvalue[2] = (305700 * 2289 * ind.value[1]) / pow(0.06 * 2289, 0.65);
    ind.fvalue[3] = (250 * 2289) * exp(-39.75 * ind.value[1] + 9.9 * ind.value[2] + 2.74);
    ind.fvalue[4] = 25 * (1.39 / (ind.value[0] * ind.value[1]) + 4940 * ind.value[2] - 80);

    // 计算约束条件值
    ind.gvalue[0] = 0.00139 / (ind.value[0] * ind.value[1]) + 4.94 * ind.value[2] - 0.08 - 1;
    ind.gvalue[1] = 0.000306 / (ind.value[0] * ind.value[1]) + 1.082 * ind.value[2] - 0.0986 - 1;
    ind.gvalue[2] = 12.307 / (ind.value[0] * ind.value[1]) + 49408.24 * ind.value[2] + 4051.02 - 50000;
    ind.gvalue[3] = 2.098 / (ind.value[0] * ind.value[1]) + 8046.33 * ind.value[2] - 696.71 - 16000;
    ind.gvalue[4] = 2.138 / (ind.value[0] * ind.value[1]) + 7883.39 * ind.value[2] - 705.04 - 10000;
    ind.gvalue[5] = 0.417 / (ind.value[0] * ind.value[1]) + 1721.26 * ind.value[2] - 136.54 - 2000;
    ind.gvalue[6] = 0.164 / (ind.value[0] * ind.value[1]) + 631.13 * ind.value[2] - 54.48 - 550;

    check_feasible(ind);
}



void ZDT1236_init(individual& ind) {
    for (int i = 0; i < Dimension; i++)//ZDT1,2,3,6通用
        ind.value[i] = rand_real(0.0, 1.0);
}

void CONSTR_init(individual& ind) {
    ind.value[0]= rand_real(0.1, 1.0);
    ind.value[1] = rand_real(0.0, 5.0);
}

void SRN_init(individual& ind) {
    for (int i = 0; i < Dimension; i++)//ZDT1,2,3,6通用
        ind.value[i] = rand_real(-20.0, 20.0);
}

void TNK_init(individual& ind) {
    for (int i = 0; i < Dimension; i++)//ZDT1,2,3,6通用
        ind.value[i] = rand_real(0.0, M_PI);
}

void WATER_init(individual& ind) {
    ind.value[0] = rand_real(0.01, 0.45);
    ind.value[1] = rand_real(0.01, 0.10);
    ind.value[2] = rand_real(0.01, 0.10);
}