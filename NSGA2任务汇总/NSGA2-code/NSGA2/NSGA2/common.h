#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<math.h>
#include<time.h>
#include<iostream>
#define Dimension 3//����ά��
#define popsize 100//��Ⱥ��С
#define generation 500 //���ܴ���
#define URAND (rand()/(RAND_MAX+1.0))//���������
#define M_PI 3.14159265358979323846
#define Crossover 0.9//�������
#define Mutation (1.0/Dimension)//�������
//#define Mutation 0.2//�������
#define eta_c 20 //SBX�Ľ������
#define eta_m 20 //PM�ı������
#define lower_bound -5.0//�����½�
#define upper_bound 5.0//�����Ͻ�

//���������������ڲ����µ��Ӵ�
using namespace std;
