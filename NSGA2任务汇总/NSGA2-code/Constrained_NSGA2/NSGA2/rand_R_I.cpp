#include "rand_R_I.h"

//���ֺ���������
double rand_real(double low, double high)
//�������ʵ��
{
    double h;
    h = (high - low) * URAND + low + 0.001;
    if (h >= high)
        h = high - 0.001;
    return h;
}

int rand_int(int low, int high)
//�����������
{
    return int((high - low + 1) * URAND) + low;
}