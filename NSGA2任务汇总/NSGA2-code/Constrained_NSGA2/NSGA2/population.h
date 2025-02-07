#pragma once
#include"individual.h"
#include "common.h"
#include "rand_R_I.h"
#include "all_cmp.h"


//Ⱥ�����������
class population
{
public:
    population();//���ʼ��
    individual P[popsize];
    individual Q[popsize];
    individual R[2 * popsize];
    void set_p_q();
    //�������һ����ʼ����P���ڴ˻����ϲ��ö�Ԫ������ѡ��
    //����ͱ�����������Ӵ�Q��P��QȺ���ģ��Ϊpopsize
    //��Pt��Qt���뵽Rt�У���ʼʱt=0������Rt���п��ٷ�֧�������
    //���������в�ͬ�ȼ��ķ�֧��⼯F1��F2........
    int Rnum;
    int Pnum;
    int Qnum;
    //P,Q,R��Ԫ�صĸ���
    void make_new_pop();//�����µ��Ӵ�
    void fast_nondominated_sort();//���ٷ�֧������
    void calu_crowding_distance(int i);//ӵ���������
    void f_sort(int i);//��ӵ�����뽵������
    void maincal();//��Ҫ����
    int choice(int a, int b);
    void variable_bound_correct(double &x, int i);//�����߽紦��
    //�����������ڲ�ͬ�ȼ��ķ�֧��⼯�����ȿ��ǵȼ���Ž�С��
    //��������������ͬһ�ȼ��ķ�֧��⼯�����ȿ���ӵ������ϴ��
    int len[2 * popsize];//�������콻����Ⱥ��Fi�ĳ��ȵļ��ϣ�len[i]��ʾranki�ĳ���
    int len_f;//����Ⱥ��rankֵ
};