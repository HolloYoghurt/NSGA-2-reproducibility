#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<math.h>
#include<time.h>
#include<vector>
#include<iostream>

#define Dimension 2//����ά��
#define popsize 100//��Ⱥ��С
#define generation 500 //���ܴ���
#define URAND (rand()/(RAND_MAX+1.0))//���������
#define M_PI 3.14159265358979323846
#define Crossover 0.9//�������
#define Mutation (1.0/Dimension)//�������
#define eta_c 20 //SBX�Ľ������
#define eta_m 20 //PM�ı������
#define Gnum 2//Լ����������
#define Objective_number 2//Ŀ�꺯������

const double Lower_bound[Dimension] = { 0.0 , 0.0 }; // ÿ���������½�
const double Upper_bound[Dimension] = { M_PI , M_PI }; // ÿ���������Ͻ�
//const double Water_normalized[Objective_number] = {8e4,1500.0,3e6,6e6,8e3}; // ˮ�Ĺ�һ��

//���������������ڲ����µ��Ӵ�
using namespace std;
