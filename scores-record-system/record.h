#pragma once
#include <stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define default_num 3  ///Ĭ�ϻ�������Ŀ��ȡ3��5
typedef struct Sport
{
    char name[20];       //��Ŀ����
    int win_school[5];   //��ǰ����ǰ��ѧУ�ı��
    int award_num;       //����˶���Ŀȡ���ε���Ŀ��ȡ3��5
} Sport;                 //�����Ŀ��Ϣ
typedef struct School
{
    int total_score[3];//�±�0��ʾѧУ�ܷ֣�1��ʾ�����ܷ֣�2��ʾŮ���ܷ֣�����֮����������������������
    char name[20];   //ѧУ����
    int scores[50];  //������Ŀ�÷�
    int number; //ѧУ���
} School;

//������������
void firstUsed();
//��ʼ���������ڴ��ļ����������д򿪳���Ķ�ȡ��ʼ������
void initialization();
//�����ļ�
void saveToFile();
//���ļ�
void readFromFile();
///���ղ�ͬ�Ĳ�����ѧУ�����������
void merge_sort(School temp[], int st, int en, int option, School temp1[]);
//����ѧУ�ɼ���ͳ��
void schoolInput(int schoolnum, int award_num, int i, int pos);
///������Ŀ�ɼ��˵�
void inputScores();
//���ѧУ�˵�
void showSchool();
//���������Ŀ�˵�
void showSports();
//���ò˵�
void setting();
//����ѧУ����Ŀ���Ʋ˵�
void InputName();
//���˵��Ĳ���
void menu();
