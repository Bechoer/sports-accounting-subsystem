#define _CRT_SECURE_NO_WARNINGS 1
#include"record.h"

#define default_num 3  ///默认获奖名次数目，取3或5

//初始化默认值
int n = 20;  //最大学校数目
int m = 10;  //最大男子项目数目
int w = 10;  //最大女子项目数目
School schools[25];  //学校结构体数组
School temp[25];  //用来缓存排序列表学校数据
School temp1[25];  //排序缓存数组
Sport sports[50];  //比赛项目结构体数组
int three[3] = { 5,3,2 };   //获得前三名的学校积分
int five[5] = { 7,5,3,2,1 };  //获得前五名的学校积分

void readFromFile();//从数据文件读取存有的运动会成绩信息

void firstUsed()//程序数据清零
{
    //遍历所有学校和项目，清空分数数组。
    //将学校总分（0）、男子总分（1）、女子总分（2）及对应的各个项目得分设置为0
    for (int i = 0; i < n; i++)
    {
        schools[i].total_score[0] = 0;
        schools[i].total_score[1] = 0;
        schools[i].total_score[2] = 0;
        for (int j = 0; j < m + w; j++) {
            schools[i].scores[j] = 0;
        }
    }
    //将男子、女子项目的前三或前五设置为0
    for (int i = 0; i < m + w; i++)
    {
        for (int j = 0; j < 5; j++)
            sports[i].win_school[j] = 0;
    }
    //printf("程序数据清零");
    //从文件中读取各个运动项目取的名次，3或5
    FILE* fp = fopen("setting.txt", "r");
    if (fp == NULL) {
        // 文件不存在的处理逻辑
        printf("当前设置不存在，载入默认设置.\n");
        fp = fopen("setting.txt", "w");
        for (int i = 0; i < 50; i++) {
            sports[i].award_num = default_num; // 默认值3
            fprintf(fp, "%d\n", default_num);
            fprintf(fp, "%d\n%d\n%d",20 ,10 ,10);
        }
        return;
    }
    for (int i = 0; i < 50; i++)
    {
        fscanf(fp, "%d", &sports[i].award_num);
    }
    fclose(fp);
}
void readFromFile()
{
    FILE* fp1 = fopen("schools.txt", "r");
    if (fp1 == NULL)
    {
        firstUsed();
    }
    for (int i = 0; i < n; i++)
    {
        fscanf(fp1, "%s", schools[i].name);
        fscanf(fp1, "%d %d %d %d",
            &schools[i].number,&schools[i].total_score[0], &schools[i].total_score[1], &schools[i].total_score[2]);
        for (int j = 0; j < m + w; j++)
        {
            fscanf(fp1, "%d", &schools[i].scores[j]);
        }
    }
    fclose(fp1);

    FILE* fp2 = fopen("sports.txt", "r");
    if (fp2 == NULL)
    {
        firstUsed();
    }
    for (int i = 0; i < m + w; i++)
    {
        fscanf(fp2, "%d %s",&sports[i].number,&sports[i].name);
        fscanf(fp2, "%d", &sports[i].award_num);
        for (int j = 0; j < sports[i].award_num; j++)
        {
            fscanf(fp2, "%d", &sports[i].win_school[j]);
        }
    }
    fclose(fp2);
}
void initialization()//初始化操作，在此文件操作，进行打开程序的读取初始化操作
{
    readFromFile();

    FILE* fp = fopen("setting.txt", "r");
    if (fp == NULL)
    {
        firstUsed();
    }
    for (int i = 0; i < 50; i++)
    {
        fscanf(fp, "%d", &sports[i].award_num);
    }
    fscanf(fp, "%d%d%d", &n, &m, &w);
    fclose(fp);
}

void saveToFile()//将输入到内存中的数据存到文件中
{
    FILE* fp1 = fopen("schools.txt", "w");
    if (fp1 == NULL)
    {
        printf("文件未成功打开！！！\n");
    }
    for (int i = 0; i < n; i++)
    {
        fprintf(fp1, "%s\n", schools[i].name);
        //number学校序号
        //0学校总分   1男子总分  2女子总分
        fprintf(fp1, "%d %d %d %d \n", 
            schools[i].number,schools[i].total_score[0], schools[i].total_score[1], schools[i].total_score[2]);
        for (int j = 0; j < m + w; j++)
        {
            fprintf(fp1, "%d ", schools[i].scores[j]);//各个项目得分
        }
        fprintf(fp1, "\n\n");
    }
    fclose(fp1);

    FILE* fp2 = fopen("sports.txt", "w");
    if (fp2 == NULL)
    {
        printf("文件未成功打开！！！\n");
    }
    for (int i = 0; i < m + w; i++)
    {
        fprintf(fp2, "%d %s\n",sports[i].number ,sports[i].name);
        fprintf(fp2, "%d\n", sports[i].award_num);
        for (int j = 0; j < sports[i].award_num; j++)
        {
            fprintf(fp2, "%d ", sports[i].win_school[j]);
        }
        fprintf(fp2, "\n\n");
    }
    fclose(fp2);
}

void merge_sort(School temp[], int st, int en, int option, School temp1[])//按照不同的参数对学校数组进行排序
{
    //根据option，选择按照不同的参数排序
    //0学校总分，1男子总分，2女子总分
    if (en - st == 1)return;
    int mid = st + (en - st) / 2;
    merge_sort(temp, st, mid, option, temp1);
    merge_sort(temp, mid, en, option, temp1);

    int st1 = st, st2 = mid, tst = st;
    while (st1 < mid && st2 < en)
    {
        if (temp[st1].total_score[option] > temp[st2].total_score[option])temp1[tst++] = temp[st1++];
        else temp1[tst++] = temp[st2++];
    }
    while (st1 < mid)temp1[tst++] = temp[st1++];
    while (st2 < en)temp1[tst++] = temp[st2++];
    int j;
    for (j = st; j < en; j++)
        temp[j] = temp1[j];
}

void schoolInput(int schoolnum, int award_num, int i, int pos)//输入学校成绩并统计
{
    if (award_num == 3)
    {
        schools[schoolnum].scores[pos] += three[i];
        schools[schoolnum].total_score[0] += three[i];
        if (pos >= 0 && pos < m)schools[schoolnum].total_score[1] += three[i];
        else if (pos >= m && pos < m + w)schools[schoolnum].total_score[2] += three[i];
    }
    else if (award_num == 5)
    {
        schools[schoolnum].scores[pos] += five[i];
        schools[schoolnum].total_score[0] += five[i];
        if (pos >= 0 && pos < m)schools[schoolnum].total_score[1] += five[i];
        else if (pos >= m && pos < m + w)schools[schoolnum].total_score[2] += five[i];
    }
}

void inputScores()//输入项目成绩菜单
{
loop1:
    system("cls");
    printf("请按顺序输入各个项目成绩（三位或后五位为前三名或前五名的成绩,名次靠前的先输入）：\n");
    firstUsed();
    for (int pos = 0; pos < m + w; pos++)
    {
        printf("项目名称:%s,取前%d名:\n",sports[pos].name,sports[pos].award_num);
        int award_num = sports[pos].award_num;
        printf("输入获奖学校编号:");

        for (int i = 0; i < award_num; i++)
        {
            scanf("%d", &sports[pos].win_school[i]);//输入获奖学校编号
            sports[pos].win_school[i]--;
            if (sports[pos].win_school[i] < 0 || sports[pos].win_school[i] >= m + w)
            {
                i--;
                printf("没有您输入的编号对应的学校，请重新输入：\n");
                continue;
            }
            schoolInput(sports[pos].win_school[i], award_num, i, pos);
        }
    }

    int flag = 0;
loop2:
    system("cls");
    printf("\n\n\n");
    printf("\t\t**************************************************\n");
    printf("\t\t*     您的输入已完成，请输入以下操作对应编号     *\n");
    printf("\t\t*================================================*\n");
    printf("\t\t*       +      1.保存输入       +                *\n");
    printf("\t\t*================================================*\n");
    printf("\t\t*       +      2.重新输入       +                *\n");
    printf("\t\t*================================================*\n");
    printf("\t\t*       +      3.返回主菜单     +                *\n");
    printf("\t\t*================================================*\n");
    printf("\t\t*       +      4.退出系统       +                *\n");
    printf("\t\t**************************************************\n");
    if (flag == 0)printf("请输入您选择的选项对应的编号：\n");
    else printf("没有您输入的选项编号，请重新输入：\n");
    int option;
    scanf("%d", &option);
    switch (option)
    {
    case 1:
        saveToFile();
        printf("\n\n\n\t\t\t\t保存成功！！！\n");
        Sleep(1000);
        goto loop2;
        break;
    case 2:
        initialization();
        goto loop1;
        break;
    case 3:
        initialization();
        system("cls");
        return;
        break;
    case 4:
        saveToFile();
        Sleep(1000);
        exit(0);
        break;
    default:
        flag = 1;
        goto loop1;
    }
}

void showSchool()///输出学校菜单
{
    const char* str[] = { "总分","男子总分","女子总分" };
    int flag = 0;
    while (1)
    {
        system("cls");
        printf("\n\n\n");
        printf("\t\t******************************************\n");
        printf("\t\t*     +    1.按学校编号列出      +       *\n");
        printf("\t\t*========================================*\n");
        printf("\t\t*     +    2.按学校总分列出      +       *\n");
        printf("\t\t*========================================*\n");
        printf("\t\t*     +    3.按男子项目总分列出  +       *\n");
        printf("\t\t*========================================*\n");
        printf("\t\t*     +    4.按女子项目总分列出  +       *\n");
        printf("\t\t*========================================*\n");
        printf("\t\t*     +    5.返回主菜单          +       *\n");
        printf("\t\t*========================================*\n");
        printf("\t\t*     +    6.退出系统            +       *\n");
        printf("\t\t******************************************\n");
        if (flag == 0)
            printf("请输入选项对应编号：");
        else printf("没有您输入的选项，请重新输入：");
        int option;
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            system("cls");
            printf("\t|\t\t学校按照编号列出                       |\n");  
            printf("\t|______________________________________________________|\n");
            printf("\t|学校编号|     学校名称     |学校总分|男子总分|女子总分|\n");
            printf("\t|________|__________________|________|________|________|\n");
            for (int i = 0; i < n; i++)
            {
                printf("\t|%8d|%18s|%8d|%8d|%8d|\n",
                    schools[i].number, schools[i].name, schools[i].total_score[0], schools[i].total_score[1], schools[i].total_score[2]);
                printf("\t|________|__________________|________|________|________|\n");
            }
            printf("-----按任意键返回上一级-----");
            getchar();
            getchar();
            break;

        case 2:
        case 3:
        case 4:
            system("cls");
            for (int i = 0; i < n; i++)
            {
                temp[i] = schools[i];
            }
            merge_sort(temp, 0, n, option - 2, temp1);
            printf("\t|\t\t学校按照%s列出\t                 |\n", str[option - 2]);
            printf("\t|______________________________________________________|\n");
            printf("\t|学校编号|     学校名称     |学校总分|男子总分|女子总分|\n");
            printf("\t|________|__________________|________|________|________|\n");
            for (int i = 0; i < n; i++)
            {
                printf("\t|%8d|%18s|%8d|%8d|%8d|\n",
                    temp[i].number, temp[i].name, temp[i].total_score[0], temp[i].total_score[1], temp[i].total_score[2]);
                printf("\t|________|__________________|________|________|________|\n");
            }
            printf("-----按任意键返回上一级-----");
            getchar();
            getchar();
            break;
        case 5:
            system("cls");
            return;
            break;
        case 6:
            saveToFile();
            Sleep(1000);
            exit(0);
            break;
        default:
            flag = 1;
        }
    }
}

void showSports()///输出查找项目菜单
{
    int flag = 0;
    while (1)
    {
        system("cls");
        printf("\n\n\n");
        printf("\t\t******************************************\n");
        printf("\t\t*     +    1.查询学校项目成绩   +        *\n");
        printf("\t\t*========================================*\n");
        printf("\t\t*     +    2.查询项目获奖学校   +        *\n");
        printf("\t\t*========================================*\n");
        printf("\t\t*     +    3.返回主菜单         +        *\n");
        printf("\t\t*========================================*\n");
        printf("\t\t*     +    4.退出系统           +        *\n");
        printf("\t\t******************************************\n");
        if (flag == 0)
            printf("请输入选项对应编号：");
        else printf("您输入的选项不存在，请重新输入：");
        int option;
        scanf("%d", &option);
        printf("*****************************************************\n");

        switch (option)
        {
        case 1:
            //system("cls");
            printf("请输入要查询的学校编号：");
            int num;
            scanf("%d", &num);
            num--;
            printf("请输入要查询的该学校的项目编号：");
            int sp;
            scanf("%d", &sp);
            sp--;
            printf("==================================================\n");
            printf("|%s的%s项目获奖得分情况：", schools[num].name, sports[sp].name);
            printf("%3d 分\n", schools[num].scores[sp]);
            printf("==================================================\n");
            printf("-----按任意键返回上一级-----");
            getchar();
            getchar();
            break;
        case 2:
            //system("cls");
            printf("请输入要查询的项目编号：");
            int num1;
            scanf("%d", &num1);
            if (num1 <= 0 || num1 > 20)
            {
                printf("您输入的项目编号有误，请重新输入:");
                scanf("%d", &num1);
            }
            num1--;
            printf("您查询的%s项目的获奖学校如下：\n", sports[num1].name);
            printf("\t_____________________________\n");
            printf("\t|学校编号|     学校名称     |\n");
            printf("\t|________|__________________|\n");
            for (int i = 0; i < sports[num1].award_num; i++)
            {
                printf("\t|%8d|%18s|\n", schools[sports[num1].win_school[i]].number, schools[sports[num1].win_school[i]].name);
                printf("\t|________|__________________|\n");
            }
            printf("-----按任意键返回上一级-----");
            getchar();
            getchar();
            break;
        case 3:
            system("cls");
            return;
            break;
        case 4:
            saveToFile();
            Sleep(1000);
            exit(0);
            break;
        default:
            flag = 1;
        }
    }
}

void setting()///设置菜单
{
    while (1)
    {
        system("cls");
        printf("\n\n\n");
        printf("\t\t******************************************\n");
        printf("\t\t*     +    1.设置项目前三或前五  +       *\n");
        printf("\t\t*========================================*\n");
        printf("\t\t*     +    2.设置学校数目        +       *\n");
        printf("\t\t*========================================*\n");
        printf("\t\t*     +    3.设置男子项目数目    +       *\n");
        printf("\t\t*========================================*\n");
        printf("\t\t*     +    4.设置女子项目数目    +       *\n");
        printf("\t\t*========================================*\n");
        printf("\t\t*     +    5.返回主菜单          +       *\n");
        printf("\t\t*========================================*\n");
        printf("\t\t*     +    6.退出系统            +       *\n");
        printf("\t\t*========================================*\n");
        printf("\t\t******************************************\n");
       
        printf("请输入选项对应编号：");
        int option;
        scanf("%d", &option);
        printf("**********************************************\n");
        switch (option)
        {
        case 1:
            while (1)
            {
                //system("cls");
                printf("请输入要设置的项目编号：");
                int n1;
                scanf("%d", &n1);
                n1--;
                printf("请输入3或5设置该项目要取的获奖名次：");
                while (1)
                {
                    int n2;
                    scanf("%d", &n2);
                    if (n2 == 3 || n2 == 5)
                    {
                        sports[n1].award_num = n2;
                        break;
                    }
                    system("cls");
                    printf("您输入的数据有误，请重新输入：");
                }
                printf("继续设置请输入1，返回上一级请输入2：");
                scanf("%d", &n1);
                if (n1 == 1)continue;
                else if (n1 == 2)break;
            }
            break;
        case 2:
            //system("cls");
            printf("请输入学校数目：");
            while (1)
            {
                scanf("%d", &n);
                //参赛学校数量不能大于20，不能小于1
                if (n <= 20 && n >= 1)break;
                else
                {
                    //system("cls");
                    printf("您输入的学校数目不合法，请重新输入：");
                }
            }
            printf("-----按任意键返回上一级-----\n");
            getchar();
            getchar();
            break;
        case 3:
            //system("cls");
            printf("请输入男子项目数目：");
            while (1)
            {
                scanf("%d", &m);
                //男子项目个数不能大于20，不能小于1
                if (m <= 20 && m >= 0)break;
                else
                {
                    //system("cls");
                    printf("您输入的男子项目数目不合法，请重新输入：");
                }
            }
            printf("-----按任意键返回上一级-----\n");
            getchar();
            getchar();
            break;
        case 4:
            //system("cls");
            printf("请输入女子项目数目：");
            while (1)
            {
                scanf("%d", &w);
                //女子项目个数不能大于20，不能小于1
                if (w <= 20 && w >= 0)break;
                else
                {
                    //system("cls");
                    printf("您输入的女子项目数目不合法，请重新输入：");
                }
            }
            printf("-----按任意键返回上一级-----\n");
            getchar();
            getchar();
            break;
        case 5:
            system("cls");
            return;
            break;
        case 6:
            saveToFile();
            Sleep(1000);
            exit(0);
            break;
        }

        FILE* fp = fopen("setting.txt", "w");
        if (fp == NULL)
        {
            printf("文件未成功打开！！！\n");
            system("pause");
        }
        for (int i = 0; i < m + w; i++)
        {
            fprintf(fp, "%d ", sports[i].award_num);// 取3或者5名
        }
        //for (int i = m + w; i < 50; i++)
        //{
        //    fprintf(fp, "%d ", default_num);//
        //}
        fprintf(fp, "\n%d\n%d\n%d\n", n, m, w);
        fclose(fp);
    }
}

void InputName()///输入学校和项目名称菜单
{
    int flag = 0;
    while (1)
    {
        system("cls");
        printf("\n\n\n");
        printf("\t\t******************************************\n");
        printf("\t\t*     +      1.输入学校名称        +     *\n");
        printf("\t\t*========================================*\n");
        printf("\t\t*     +      2.输入比赛项目名称    +     *\n");
        printf("\t\t*========================================*\n");
        printf("\t\t*     +      3.返回主菜单          +     *\n");
        printf("\t\t*========================================*\n");
        printf("\t\t*     +      4.退出系统            +     *\n");
        printf("\t\t*========================================*\n");
        printf("\t\t******************************************\n");
        if (flag == 0)
            printf("请输入选项对应编号：\n");
        else printf("没有您输入的选项，请重新输入：\n");
        int option;
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            system("cls");
            printf("请按照编号顺序输入学校名称（输入 stop ，则停止输入）：\n");
            for (int i = 0; i < n; i++)
            {
                printf("编号 %d：", i + 1);
                char tmp[20] = {'\0'};
                scanf("%s", tmp);
                if (strcmp(tmp, "stop") == 0)
                {
                    printf("输入停止!\n");
                    break;
                }
                strcpy(schools[i].name, tmp);
                schools[i].number = i + 1;
                //printf("...%s", schools[i].name);
            }
            printf("-----按任意键返回上一级-----\n");
            saveToFile();
            getchar();
            getchar();
            break;
        case 2:
            system("cls");
            printf("请按照编号顺序输入项目名称（输入 stop ，则停止输入）：\n");
            for (int i = 0; i < m + w; i++)
            {
                char tmp[20] = { '\0' };
                if (i < m)
                {
                    printf("男子项目 编号 %d：", i + 1);
                    scanf("%s", &tmp);
                }
                else
                {
                    printf("女子项目 编号 %d：", i + 1);
                    scanf("%s", &tmp);
                }
                
                if (strcmp(tmp, "stop") == 0)
                {
                    printf("输入停止!\n");
                    break;
                }
                strcpy(sports[i].name, tmp);
                sports[i].number = i + 1;
            }
            printf("-----按任意键返回上一级-----\n");
            saveToFile();
            getchar();
            getchar();
            break;
        case 3:
            system("cls");
            return;
            break;
        case 4:
            saveToFile();
            Sleep(1000);
            exit(0);
            break;
        default:
            flag = 1;
        }
    }
}
void showAllSchools()//所有参赛学校
{
    system("cls");
    printf("\n\n");
    printf("\t|========所有参赛学校=======|\n");
    printf("\t_____________________________\n");
    printf("\t|学校编号|     学校名称     |\n");
    printf("\t|________|__________________|\n");
    for (int i = 0; i < n; i++)
    {
        printf("\t|%8d|%18s|\n",
            schools[i].number, schools[i].name);
        printf("\t|________|__________________|\n");
    }
    printf("-----按任意键返回上一级-----");
    getchar();
    getchar();
}
void showAllGames()//展示所有比赛项目
{
    readFromFile();
    system("cls");
    printf("\n\n");
    printf("\t|========所有比赛项目=======|\n");
    printf("\t_____________________________\n");
    printf("\t|项目编号|     项目名称     |\n");
    printf("\t|________|__________________|\n");
    for (int i = 0; i < m+w; i++)
    {
        printf("\t|%8d|%18s|\n",
            sports[i].number, sports[i].name);
        printf("\t|________|__________________|\n");
    }
    printf("-----按任意键返回上一级-----");
    getchar();
    getchar();
}

void menu()///主菜单的操作
{
    int flag = 0;
    while (1)
    {
        system("cls");
        printf("\n\n");
        //打印菜单栏
        printf("\n\t\t+==============================================================+\n");
        printf("\t\t+                运动会分数统计系统  主菜单                    +\n");
        printf("\t\t+==============================================================+\n");
        printf("\t\t+ 【信息录入】                                                 +\n");
        printf("\t\t+     1. 输入学校和项目名称       2.输入项目成绩               +\n");
        printf("\t\t+--------------------------------------------------------------+\n");
        printf("\t\t+ 【查看信息】                                                 +\n");
        printf("\t\t+     3.查看参赛学校        4.查看比赛项目                     +\n");
        printf("\t\t+     5.查看学校成绩        6.查看项目成绩                     +\n");
        printf("\t\t+--------------------------------------------------------------+\n");
        printf("\t\t+ 【设置】                                                     +\n");
        printf("\t\t+     7.设置                                                   +\n");
        printf("\t\t+--------------------------------------------------------------+\n");
        printf("\t\t+  0. 退出系统                                                 +\n");
        printf("\t\t+--------------------------------------------------------------+\n");
        printf("\t\t+ 【提示】                                                     +\n");
        printf("\t\t+     初次使用时，请先录入相关信息                             +\n");
        printf("\t\t+--------------------------------------------------------------+\n");
        if (flag == 0)
            printf("请输入对应选项的编号：");
        else printf("没有您输入的选项，请重新输入：");
        int option;
        scanf("%d", &option);
        switch (option)
        {
        case 1://输入学校和项目名称
            InputName();
            break;
        case 2://输入项目成绩
            inputScores();
            break;
        case 3://查看参赛学校
            showAllSchools();
            break;
        case 4://查看比赛项目
            showAllGames();
            break;
        case 5://查看学校成绩
            showSchool();
            break;
        case 6://查看项目成绩
            showSports();
            break;
        case 7://设置
            setting();
            break;
        case 0://退出系统
            saveToFile();
            Sleep(1000);
            exit(0);
            break;
        default:
            flag = 1;
        }
    }
}


