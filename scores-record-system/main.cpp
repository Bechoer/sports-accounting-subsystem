#define _CRT_SECURE_NO_WARNINGS 1
#include"record.h"

using namespace std;
// 欢迎界面
void showWelcome()
{
	cout << ("\n\n");
	printf("\033[47;36m");
	cout << ("\t\t***************************************************************\n");
	cout << ("\t\t***************************************************************\n");
	cout << ("\t\t**             欢 迎 使 用                                   **\n");
	cout << ("\t\t**             ***********                                   **\n");
	cout << ("\t\t**           ***************                                 **\n");
	cout << ("\t\t**         ********************                              **\n");
	cout << ("\t\t**       ************************                            **\n");
	cout << ("\t\t**       *                      *                            **\n");
	cout << ("\t\t**       *  运动会分数统计系统    *                            **\n");
	cout << ("\t\t**       *                      *                            **\n");
	cout << ("\t\t**       ************************                            **\n");
	cout << ("\t\t**         ********************                              **\n");
	cout << ("\t\t**           ***************                                 **\n");
	cout << ("\t\t**             ***********          作者：xxx                 **\n");
	cout << ("\t\t***************************************************************\n");
	cout << ("\t\t***************************************************************\n");
	cout << ("\n\n");
	printf("\033[0m");
	system("pause");

	system("cls");
}
//模拟进度条
void printProgressBar(int progress, int total) {
	int barWidth = 50;  // 进度条的宽度
	// 动态字符效果
	//const char* characters = "#*=";  // 动态效果的字符集合
	int charIndex = (progress / 5) % 3;  // 根据进度来变化字符

	printf("\t\t\t[");
	int pos = barWidth * progress / total;
	printf("\033[42m");
	for (int i = 0; i < barWidth; i++) {
		if (i < pos) {
			//printf("%c", characters[charIndex]);  // 使用动态字符
			printf(" ");
		}
		else {
			printf("\033[47m");
			printf(" ");
		}
		
	}
	printf("\033[0m");
	printf("] %d%%\r", progress * 100 / total);
	// 刷新输出缓冲区，确保立即显示
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
	// 隐藏光标
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	cursorInfo.bVisible = FALSE;  // 设置光标不可见
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	int total = 100;  // 进度条的总进度
	printf("\t\t\t\t\t系统正在加载中...\n\n");
	for (int i = 0; i <= total; i++) {
		printProgressBar(i, total);
		Sleep(80);  // 暂停0.1秒，模拟进度的更新
	}
	// 显示光标
	cursorInfo.bVisible = TRUE;  // 恢复光标可见
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
