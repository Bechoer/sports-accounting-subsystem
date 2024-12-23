#pragma once
#include <stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define default_num 3  ///默认获奖名次数目，取3或5
typedef struct Sport
{
    char name[100];       //项目名称
    int number;         //项目编号
    int win_school[5];   //获奖前三或前五学校的编号
    int award_num;       //这个运动项目取名次的数目，取3或5
} Sport;                 //存放项目信息
typedef struct School
{
    int total_score[3];//下标0表示学校总分，1表示男子总分，2表示女子总分，方便之后的排序输出而存在数组中
    char name[20];   //学校名称
    int scores[50];  //各个项目得分
    int number; //学校编号
} School;

//程序数据清零
void firstUsed();
//初始化操作，在此文件操作，进行打开程序的读取初始化操作
void initialization();
//保存文件
void saveToFile();
//读文件
void readFromFile();
///按照不同的参数对学校数组进行排序
void merge_sort(School temp[], int st, int en, int option, School temp1[]);
//输入学校成绩并统计
void schoolInput(int schoolnum, int award_num, int i, int pos);
///输入项目成绩菜单
void inputScores();
//输出学校菜单
void showSchool();
//输出查找项目菜单
void showSports();
//设置菜单
void setting();
//输入学校和项目名称菜单
void InputName();
//主菜单的操作
void menu();
