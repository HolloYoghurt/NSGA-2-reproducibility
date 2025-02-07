#include "all_cmp.h"

//¹ØÓÚÅÅÐòº¯Êýqsort:
int cmp1(const void* a, const void* b)
//Ä¿±êº¯Êýf1µÄÉýÐòÅÅÐò
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
//Ä¿±êº¯Êýf2µÄÉýÐòÅÅÐò
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
//¶ÔÓµ¼·¾àÀë½µÐòÅÅÐò
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
