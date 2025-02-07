#include "common.h"
#include "individual.h"
#include "population.h"
#include "rand_R_I.h"
#include "all_cmp.h"


//����������Ҫ���ģ�
//������main.cpp��file; �ı��ļ���
//������common.h��Dimension; �ı�ά��
//������common.h��upper_bound; �ı��Ͻ� lower_bound; �ı��½�
//������individual.cpp��f_count(); �ı�Ŀ�꺯��
//������individual.cpp��init(); �ı��ʼ����Χ


//���ö�ȡ����
string file = "KUR";
//���ö�ȡ·��
string path = "D:\\Desktop\\postgraduate_study\\work\\10.15\\code\\data\\";

//��������
int main()
{
    FILE* p, * p1;
    string filename = path + file + ".txt";
    string filename1 =path + file + "_plot.txt";

    p = fopen(filename.c_str(), "w+");
    p1= fopen(filename1.c_str(), "w+");
    srand((unsigned int)(time(0)));
    population pop;
    pop.maincal();
    int i, j;

    for (i = 0; i < popsize; i++)
    {
        fprintf(p, "The %d generation situation:\n", i);
        for (j = 1; j <= Dimension; j++)
        {
            fprintf(p, "x%d=%e  ", j, pop.P[i].value[j]);
        }
        fprintf(p, "\n");
        fprintf(p, "f1(x)=%f   f2(x)=%f\n", pop.P[i].fvalue[0], pop.P[i].fvalue[1]);
        fprintf(p1, "f1(x)=%f   f2(x)=%f\n", pop.P[i].fvalue[0], pop.P[i].fvalue[1]);
    }
    fclose(p);
    return 1;
}