#define _CRT_SECURE_NO_WARNINGS 1
#include"record.h"
#include<iostream>
using namespace std;
// 欢迎界面
void showWelcome()
{
	cout << ("\n\n");
	cout << ("\t\t*************************************************************\n");
	cout << ("\t\t*             欢 迎 使 用                                   *\n");
	cout << ("\t\t*             ***********                                   *\n");
	cout << ("\t\t*           ***************                                 *\n");
	cout << ("\t\t*         ********************                              *\n");
	cout << ("\t\t*       ************************                            *\n");
	cout << ("\t\t*       *                      *                            *\n");
	cout << ("\t\t*       *  运动会分数统计系统  *                            *\n");
	cout << ("\t\t*       *                      *                            *\n");
	cout << ("\t\t*       ************************                            *\n");
	cout << ("\t\t*         ********************                              *\n");
	cout << ("\t\t*           ***************                                 *\n");
	cout << ("\t\t*             ***********          作者：王子涵 李欣怡      *\n");
	cout << ("\t\t*************************************************************\n");
	cout << ("\n\n");

	system("pause");

	system("cls");
}
int main()
{
	showWelcome();
    initialization();
    menu();
    return 0;
}