#pragma once
#include "common.h"
//�������������
class individual
{
public:
    double value[Dimension];//xi��ֵ
    int sp[2 * popsize];
    //��֧����弯��SP�������ǿ��н�ռ������б�����p֧��ĸ�����ɵļ��ϡ�
    int np;
    //֧�����np���������ڿ��н�ռ��п���֧�����p�����Ը����������
    int is_dominated;//����sp�ĸ���
    void init();//��ʼ������
    int rank;//���ȼ���Pareto����Ϊ��ǰ��߼�
    double crowding_distance;//ӵ������
    double fvalue[2];//ZDT1����Ŀ�꺯����ֵ
    void f_count();//����fvalue��ֵ
};
