#define _CRT_SECURE_NO_WARNINGS 1
#include"record.h"
#include<iostream>
using namespace std;
// ��ӭ����
void showWelcome()
{
	cout << ("\n\n");
	cout << ("\t\t*************************************************************\n");
	cout << ("\t\t*             �� ӭ ʹ ��                                   *\n");
	cout << ("\t\t*             ***********                                   *\n");
	cout << ("\t\t*           ***************                                 *\n");
	cout << ("\t\t*         ********************                              *\n");
	cout << ("\t\t*       ************************                            *\n");
	cout << ("\t\t*       *                      *                            *\n");
	cout << ("\t\t*       *  �˶������ͳ��ϵͳ  *                            *\n");
	cout << ("\t\t*       *                      *                            *\n");
	cout << ("\t\t*       ************************                            *\n");
	cout << ("\t\t*         ********************                              *\n");
	cout << ("\t\t*           ***************                                 *\n");
	cout << ("\t\t*             ***********          ���ߣ����Ӻ� ������      *\n");
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