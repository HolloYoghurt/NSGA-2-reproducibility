#include "all_cmp.h"

//关于排序函数qsort:
int cmp1(const void* a, const void* b)
//目标函数f1的升序排序
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
//目标函数f2的升序排序
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
//目标函数f3的升序排序
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
//目标函数f4的升序排序
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
//目标函数f4的升序排序
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

    // 按拥挤距离降序排序
    if (e->crowding_distance != f->crowding_distance) {
        return (e->crowding_distance < f->crowding_distance) ? 1 : -1;
    }

    // 如果所有条件都相同，返回0
    return 0;
}

int cmp_v_c_d(const void* a, const void* b)
{
    const individual* e = (const individual*)a;
    const individual* f = (const individual*)b;

    // 按总体约束违反程度升序排序
    if (e->total_violation != f->total_violation) {
        return (e->total_violation < f->total_violation) ? -1 : 1;
    }

    // 如果总体约束违反程度相同,按拥挤距离降序排序
    if (e->crowding_distance != f->crowding_distance) {
        return (e->crowding_distance < f->crowding_distance) ? 1 : -1;
    }

    // 如果所有条件都相同，返回0
    return 0;
}