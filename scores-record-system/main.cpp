#define _CRT_SECURE_NO_WARNINGS 1
#include"record.h"

using namespace std;
// ��ӭ����
void showWelcome()
{
	cout << ("\n\n");
	printf("\033[47;36m");
	cout << ("\t\t***************************************************************\n");
	cout << ("\t\t***************************************************************\n");
	cout << ("\t\t**             �� ӭ ʹ ��                                   **\n");
	cout << ("\t\t**             ***********                                   **\n");
	cout << ("\t\t**           ***************                                 **\n");
	cout << ("\t\t**         ********************                              **\n");
	cout << ("\t\t**       ************************                            **\n");
	cout << ("\t\t**       *                      *                            **\n");
	cout << ("\t\t**       *  �˶������ͳ��ϵͳ  *                            **\n");
	cout << ("\t\t**       *                      *                            **\n");
	cout << ("\t\t**       ************************                            **\n");
	cout << ("\t\t**         ********************                              **\n");
	cout << ("\t\t**           ***************                                 **\n");
	cout << ("\t\t**             ***********          ���ߣ����Ӻ� ������      **\n");
	cout << ("\t\t***************************************************************\n");
	cout << ("\t\t***************************************************************\n");
	cout << ("\n\n");
	printf("\033[0m");
	system("pause");

	system("cls");
}
//ģ�������
void printProgressBar(int progress, int total) {
	int barWidth = 50;  // �������Ŀ��
	// ��̬�ַ�Ч��
	//const char* characters = "#*=";  // ��̬Ч�����ַ�����
	int charIndex = (progress / 5) % 3;  // ���ݽ������仯�ַ�

	printf("\t\t\t[");
	int pos = barWidth * progress / total;
	printf("\033[42m");
	for (int i = 0; i < barWidth; i++) {
		if (i < pos) {
			//printf("%c", characters[charIndex]);  // ʹ�ö�̬�ַ�
			printf(" ");
		}
		else {
			printf("\033[47m");
			printf(" ");
		}
		
	}
	printf("\033[0m");
	printf("] %d%%\r", progress * 100 / total);
	// ˢ�������������ȷ��������ʾ
	fflush(stdout);  
}
void firstDisplay()
{
	printf("\n\n");
	printf("\033[46;37m");
	printf("\t\t================================================================================\n");
	printf("\t\t|  #######        #######       #######      #######    #########    #######   |\n");
	printf("\t\t| #       #       #      #     #       #    #       #       #       #       #  |\n");
	printf("\t\t| #       #       #      #     #       #    #       #       #       #       #  |\n");
	printf("\t\t| #               #      #     #       #    #       #       #       #          |\n");
	printf("\t\t|  #######        #######      #       #    ########        #        #######   |\n");
	printf("\t\t|         #       #            #       #    #    #          #               #  |\n");
	printf("\t\t|         #       #            #       #    #     #         #               #  |\n");
	printf("\t\t| #       #       #            #       #    #      #        #       #       #  |\n");
	printf("\t\t|  #######        #             #######     #       #       #        #######   |\n");
	printf("\t\t================================================================================\n");
	printf("\033[0m");
	printf("\n\n\n\n\n\n");
	// ���ع��
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	cursorInfo.bVisible = FALSE;  // ���ù�겻�ɼ�
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	int total = 100;  // ���������ܽ���
	printf("\t\t\t\t\tϵͳ���ڼ�����...\n\n");
	for (int i = 0; i <= total; i++) {
		printProgressBar(i, total);
		Sleep(80);  // ��ͣ0.1�룬ģ����ȵĸ���
	}
	// ��ʾ���
	cursorInfo.bVisible = TRUE;  // �ָ����ɼ�
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	printf("\n");
	Sleep(100);
	system("cls");
}
int main()
{

	firstDisplay();
	showWelcome();
    initialization();
    menu();
    return 0;
}