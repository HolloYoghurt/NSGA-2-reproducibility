#include "common.h"
#include "individual.h"
#include "population.h"
#include "rand_R_I.h"
#include "all_cmp.h"


//����������Ҫ���ģ�
//������main.cpp��file; �ı��ļ���
//������common.h��Dimension; �ı�ά��
//������common.h��upper_bound; �ı��Ͻ� lower_bound; �ı��½�
//������common.h��Gnum; //Լ�������ĸ���
//������common.h��objective_number; //Ŀ�꺯���ĸ���; //Լ������
//������common.h��eta_m//PM�ı������
//������individual.cpp��f_count(); �ı�Ŀ�꺯��
//������individual.cpp��init(); �ı��ʼ����Χ
//����WATER���⣬��Ҫ����46�е����������(i,j)�������

//���ö�ȡ����
string file = "TNK";
//���ö�ȡ·��
string path = "D:\\Desktop\\postgraduate_study\\work\\10.15\\code\\Constrained_data\\";

void water_file_pushback(vector<FILE*> &v) {
    v.push_back(fopen((path + file + "_f1_f2" + "_plot.txt").c_str(), "w+"));
    v.push_back(fopen((path + file + "_f1_f3" + "_plot.txt").c_str(), "w+"));
    v.push_back(fopen((path + file + "_f1_f4" + "_plot.txt").c_str(), "w+"));
    v.push_back(fopen((path + file + "_f1_f5" + "_plot.txt").c_str(), "w+"));
    v.push_back(fopen((path + file + "_f2_f3" + "_plot.txt").c_str(), "w+"));
    v.push_back(fopen((path + file + "_f2_f4" + "_plot.txt").c_str(), "w+"));
    v.push_back(fopen((path + file + "_f2_f5" + "_plot.txt").c_str(), "w+"));
    v.push_back(fopen((path + file + "_f3_f4" + "_plot.txt").c_str(), "w+"));
    v.push_back(fopen((path + file + "_f3_f5" + "_plot.txt").c_str(), "w+"));
    v.push_back(fopen((path + file + "_f4_f5" + "_plot.txt").c_str(), "w+"));
}

void water_file_write(vector<FILE*>& v, population& pop, int i) {
    int idx = 0;
    for (int k = 1; k <= 4; ++k) {
        for (int l = k + 1; l <= 5; ++l) {
            fprintf(v[idx], "f%d(x)=%f   f%d(x)=%f\n", k, pop.P[i].fvalue[k - 1], l, pop.P[i].fvalue[l - 1]);
            ++idx;
        }
    }
}

//void water_normalized(population &pop,int i) {
//    for (int j = 0; j < 5; j++) {
//        pop.P[i].fvalue[j] /= Water_normalized[j];
//    }
//}

//��������
int main()
{
    FILE* p, * p1;
    string filename = path + file + ".txt";
    string filename1 =path + file + "_plot.txt";//ͨ���������ר��

    //vector<FILE*> v;//WATER�������ר��
    //water_file_pushback(v);

    p = fopen(filename.c_str(), "w+");
    p1= fopen(filename1.c_str(), "w+");//ͨ���������ר��
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
        fprintf(p, "f1(x)=%f   f2(x)=%f\n", pop.P[i].fvalue[0], pop.P[i].fvalue[1]); //��ͨ�������ȫ��ר��
        fprintf(p1, "f1(x)=%f   f2(x)=%f\n", pop.P[i].fvalue[0], pop.P[i].fvalue[1]); //��ͨ��������ֲ�ר��
        
        //WATER�������ȫ��ר��
        //water_normalized(pop, i);
        //fprintf(p, "f1(x)=%f   f2(x)=%f   f3(x)=%f   f4(x)=%f   f5(x)=%f\n", pop.P[i].fvalue[0], pop.P[i].fvalue[1], pop.P[i].fvalue[2], pop.P[i].fvalue[3], pop.P[i].fvalue[4]);
        //water_file_write(v, pop, i); //WATER��������ֲ�ר��

        
    }
    fclose(p);
    return 1;
}