#include "problem.h"
#include "rand_R_I.h"

void ZDT1_count(individual &ind) {
    ind.fvalue[0] = ind.value[0];
    int i;
    double g = 1, sum = 0;
    for (i = 1; i < Dimension; i++)
    {
        sum += ind.value[i];
    }
    sum += 9 * (sum / (Dimension - 1));
    g += sum;
    ind.fvalue[1] = g * (1 - sqrt(ind.value[0] / g));
}

void ZDT2_count(individual& ind) {
    ind.fvalue[0] = ind.value[0];
    double g = 1.0, sum = 0.0;
    for (int i = 1; i < Dimension; i++) {
        sum += ind.value[i];
    }
    g += 9.0 * sum / (Dimension - 1);
    ind.fvalue[1] = g * (1 - pow(ind.value[0] / g, 2));
}

void ZDT3_count(individual& ind) {
    ind.fvalue[0] = ind.value[0];
    double g = 1.0, sum = 0.0;
    for (int i = 1; i < Dimension; i++) {
        sum += ind.value[i];
    }
    g += 9.0 * sum / (Dimension - 1);
    ind.fvalue[1] = g * (1 - sqrt(ind.value[0] / g) - ind.value[0] / g * sin(10 * M_PI * ind.value[0]));
}

void ZDT4_count(individual& ind) {
    ind.fvalue[0] = ind.value[0];
    double g = 1 + 10 * (Dimension - 1);
    for (int i = 1; i < Dimension; i++) {
        g += ind.value[i] * ind.value[i] - 10*cos(4 * M_PI * ind.value[i]);
    }
    ind.fvalue[1] = g * (1 - sqrt(ind.value[0] / g));
}

void ZDT6_count(individual& ind) {
    ind.fvalue[0] = 1 - exp( - 4 * ind.value[0]) * pow(sin(6 * M_PI * ind.value[0]), 6);
    double sum = 0;
    for (int i = 1; i < Dimension; i++) {
        sum += ind.value[i];
    }
    double g = 1 + 9 * pow(sum / (Dimension - 1), 0.25);
    ind.fvalue[1] = g*(1 - pow(ind.fvalue[0] / g, 2));
}

void SCH_count(individual& ind) {
    double x = ind.value[0];

    ind.fvalue[0] = pow(x, 2);
    ind.fvalue[1] = pow((x - 2), 2);
}

void FON_count(individual& ind) {
    int n = Dimension; // 决策变量的维度
    double sum1 = 0.0, sum2 = 0.0;

    for (int i = 0; i < n; ++i) {
        sum1 += pow(ind.value[i] - 1.0 / sqrt(n), 2);
        sum2 += pow(ind.value[i] + 1.0 / sqrt(n), 2);
    }

    ind.fvalue[0] = 1 - exp(-sum1);
    ind.fvalue[1] = 1 - exp(-sum2);
}

void POL_count(individual& ind) {
    // 定义常量
    const double A1 = 0.5 * sin(1) - 2 * cos(1) + sin(2) - 1.5 * cos(2);
    const double A2 = 1.5 * sin(1)- cos(1) + 2 * sin(2) - 0.5 * cos(2);

    // 计算 B1 和 B2
    double B1 = 0.5 * sin(ind.value[0]) - 2 * cos(ind.value[0]) + sin(ind.value[1]) - 1.5 * cos(ind.value[1]);
    double B2 = 1.5 * sin(ind.value[0]) - cos(ind.value[0]) + 2 * sin(ind.value[1]) - 0.5 * cos(ind.value[1]);

    // 计算第一个目标函数值
    ind.fvalue[0] = 1 + pow(A1 - B1, 2) + pow(A2 - B2, 2);

    // 计算第二个目标函数值
    ind.fvalue[1] = pow(ind.value[0] + 3, 2) + pow(ind.value[1] + 1, 2);
}

void KUR_count(individual& ind) {
    int n = Dimension; // 决策变量的维度
    double sum1 = 0.0, sum2 = 0.0;

    // 计算第一个目标函数值
    for (int i = 0; i < n - 1; ++i) {
        double term = -10 * exp(-0.2 * sqrt(pow(ind.value[i], 2) + pow(ind.value[i + 1], 2)));
        sum1 += term;
    }
    ind.fvalue[0] = sum1;

    // 计算第二个目标函数值
    for (int i = 0; i < n; ++i) {
        double term = pow(fabs(ind.value[i]), 0.8) + 5 * sin(pow(ind.value[i], 3));
        sum2 += term;
    }
    ind.fvalue[1] = sum2;
}




void ZDT1236_init(individual& ind) {
    for (int i = 0; i < Dimension; i++)//ZDT1,2,3,6通用
        ind.value[i] = rand_real(0.0, 1.0);
}

void ZDT4_init(individual& ind) {
    ind.value[0] = rand_real(0.0, 1.0);
    for (int i = 1; i < Dimension; i++)
        ind.value[i] = rand_real(-5.0, 5.0);
}

void SCH_init(individual& ind) {
    for (int i = 0; i < Dimension; i++) {
        ind.value[i] = rand_real(-1000.0, 1000.0);
    }
}

void FON_init(individual& ind) {
    for (int i = 0; i < Dimension; i++) {
        ind.value[i] = rand_real(-4.0, 4.0);
    }
}

void POL_init(individual& ind) {
    for (int i = 0; i < Dimension; i++) {
        ind.value[i] = rand_real(-M_PI, M_PI);
    }
}

void KUR_init(individual& ind) {
    for (int i = 0; i < Dimension; i++) {
        ind.value[i] = rand_real(-5.0, 5.0);
    }
}
