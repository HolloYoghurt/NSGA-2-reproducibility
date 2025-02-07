#include "all_cmp.h"

//����������qsort:
int cmp1(const void* a, const void* b)
//Ŀ�꺯��f1����������
{
    const individual* e = (const individual*)a;
    const individual* f = (const individual*)b;
    if (e->fvalue[0] == f->fvalue[0])
        return 0;
    else if (e->fvalue[0] < f->fvalue[0])
        return -1;
    else return 1;
}

int cmp2(const void* a, const void* b)
//Ŀ�꺯��f2����������
{
    const individual* e = (const individual*)a;
    const individual* f = (const individual*)b;
    if (e->fvalue[1] == f->fvalue[1])
        return 0;
    else if (e->fvalue[1] < f->fvalue[1])
        return -1;
    else return 1;
}

int cmp_c_d(const void* a, const void* b)
//��ӵ�����뽵������
{
    const individual* e = (const individual*)a;
    const individual* f = (const individual*)b;
    if (e->crowding_distance == f->crowding_distance)
        return 0;
    else if (e->crowding_distance < f->crowding_distance)
        return 1;
    else
        return -1;
}
