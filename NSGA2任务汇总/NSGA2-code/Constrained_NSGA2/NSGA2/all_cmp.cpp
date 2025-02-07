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

int cmp3(const void* a, const void* b)
//Ŀ�꺯��f3����������
{
    const individual* e = (const individual*)a;
    const individual* f = (const individual*)b;
    if (e->fvalue[2] == f->fvalue[2])
        return 0;
    else if (e->fvalue[2] < f->fvalue[2])
        return -1;
    else return 1;
}

int cmp4(const void* a, const void* b)
//Ŀ�꺯��f4����������
{
    const individual* e = (const individual*)a;
    const individual* f = (const individual*)b;
    if (e->fvalue[3] == f->fvalue[3])
        return 0;
    else if (e->fvalue[3] < f->fvalue[3])
        return -1;
    else return 1;
}

int cmp5(const void* a, const void* b)
//Ŀ�꺯��f4����������
{
    const individual* e = (const individual*)a;
    const individual* f = (const individual*)b;
    if (e->fvalue[4] == f->fvalue[4])
        return 0;
    else if (e->fvalue[4] < f->fvalue[4])
        return -1;
    else return 1;
}

int cmp_c_d(const void* a, const void* b)
{
    const individual* e = (const individual*)a;
    const individual* f = (const individual*)b;

    // ��ӵ�����뽵������
    if (e->crowding_distance != f->crowding_distance) {
        return (e->crowding_distance < f->crowding_distance) ? 1 : -1;
    }

    // ���������������ͬ������0
    return 0;
}

int cmp_v_c_d(const void* a, const void* b)
{
    const individual* e = (const individual*)a;
    const individual* f = (const individual*)b;

    // ������Լ��Υ���̶���������
    if (e->total_violation != f->total_violation) {
        return (e->total_violation < f->total_violation) ? -1 : 1;
    }

    // �������Լ��Υ���̶���ͬ,��ӵ�����뽵������
    if (e->crowding_distance != f->crowding_distance) {
        return (e->crowding_distance < f->crowding_distance) ? 1 : -1;
    }

    // ���������������ͬ������0
    return 0;
}