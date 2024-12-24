#define _CRT_SECURE_NO_WARNINGS 1
#include"record.h"

#define default_num 3  ///Ĭ�ϻ�������Ŀ��ȡ3��5

//��ʼ��Ĭ��ֵ
int n = 20;  //���ѧУ��Ŀ
int m = 10;  //���������Ŀ��Ŀ
int w = 10;  //���Ů����Ŀ��Ŀ
School schools[25];  //ѧУ�ṹ������
School temp[25];  //�������������б�ѧУ����
School temp1[25];  //���򻺴�����
Sport sports[50];  //������Ŀ�ṹ������
int three[3] = { 5,3,2 };   //���ǰ������ѧУ����
int five[5] = { 7,5,3,2,1 };  //���ǰ������ѧУ����

void readFromFile();//�������ļ���ȡ���е��˶���ɼ���Ϣ

//��һ��ʹ�ã�������������
void firstUsed()
{
    //��������ѧУ����Ŀ����շ������顣
    //��ѧУ�ܷ֣�0���������ܷ֣�1����Ů���ܷ֣�2������Ӧ�ĸ�����Ŀ�÷�����Ϊ0
    for (int i = 0; i < n; i++)
    {
        schools[i].total_score[0] = 0;
        schools[i].total_score[1] = 0;
        schools[i].total_score[2] = 0;
        for (int j = 0; j < m + w; j++) {
            schools[i].scores[j] = 0;
        }
    }
    //�����ӡ�Ů����Ŀ��ǰ����ǰ������Ϊ0
    for (int i = 0; i < m + w; i++)
    {
        for (int j = 0; j < 5; j++)
            sports[i].win_school[j] = 0;
    }
    //printf("������������");
    //���ļ��ж�ȡ�����˶���Ŀȡ�����Σ�3��5
    FILE* fp = fopen("setting.txt", "r");
    if (fp == NULL) {
        // �ļ������ڵĴ����߼�
        printf("��ǰ���ò����ڣ�����Ĭ������.\n");
        fp = fopen("setting.txt", "w");
        for (int i = 0; i < 50; i++) {
            sports[i].award_num = default_num; // Ĭ��ֵ3
            fprintf(fp, "%d\n", default_num);
            //����ѧУ������������Ŀ����Ů����Ŀ��
            fprintf(fp, "%d\n%d\n%d",10 ,5 ,5);
        }
        return;
    }
    for (int i = 0; i < m+w; i++)
    {
        fscanf(fp, "%d", &sports[i].award_num);
    }
    fclose(fp);
}
//���ļ��ж�ȡ����
void readFromFile()
{
    FILE* fp1 = fopen("schools.txt", "r");
    if (fp1 == NULL)
    {
        firstUsed();
    }
    int cnt = 0;//��¼�ж�����ѧУ
    //fscanf(fp1, "%d", &n);
    //printf("��%d��ѧУ\n", n);
    while (1) {
        // ��ȡѧУ����
        if (fscanf(fp1, "%s", schools[cnt].name) != 1) {
            break;
        }
        // ��ȡѧУ��š�����÷֡�������Ŀ�÷֡�Ů����Ŀ�÷�
        if (fscanf(fp1, "%d %d %d %d",
            &schools[cnt].number,
            &schools[cnt].total_score[0],
            &schools[cnt].total_score[1],
            &schools[cnt].total_score[2]) != 4) {
            break;
        }
        for (int j = 0; j < m + w; j++) {
            //������Ŀ�÷�
            if (fscanf(fp1, "%d", &schools[cnt].scores[j]) != 1) {
                break;
            }
        }
        cnt++;
    }
    //for (int i = 0; i < n; i++)
    //{
    //    //ѧУ����
    //    fscanf(fp1, "%s", schools[i].name);
    //    //ѧУ��� ����÷� ������Ŀ�÷� Ů����Ŀ�÷�
    //    fscanf(fp1, "%d %d %d %d",
    //        &schools[i].number,&schools[i].total_score[0], &schools[i].total_score[1], &schools[i].total_score[2]);
    //    for (int j = 0; j < m + w; j++)
    //    {
    //        fscanf(fp1, "%d", &schools[i].scores[j]);//������Ŀ�÷�
    //    }
    //}
    fclose(fp1);

    FILE* fp2 = fopen("sports.txt", "r");
    if (fp2 == NULL)
    {
        firstUsed();
    }
    //������Ŀ������Ů����Ŀ����
    //fscanf(fp2, "%d %d", &m, &w);
    for (int i = 0; i < m + w; i++)
    {
        //������Ŀ��� ��Ŀ����
        fscanf(fp2, "%d %s",&sports[i].number,sports[i].name);
        //������Ŀȡ���ε��� 3/5
        fscanf(fp2, "%d", &sports[i].award_num);
        for (int j = 0; j < sports[i].award_num; j++)
        {
            fscanf(fp2, "%d", &sports[i].win_school[j]);//���ǰ����ǰ���ѧУ
        }
    }
    fclose(fp2);
}
//��ʼ���������ڴ��ļ����������д򿪳���Ķ�ȡ��ʼ������
void initialization()
{
    //��ȡ
    readFromFile();
    //��������
    FILE* fp = fopen("setting.txt", "r");
    if (fp == NULL)
    {
        firstUsed();
    }
    for (int i = 0; i < m+w; i++)
    {
        fscanf(fp, "%d", &sports[i].award_num);
    }
    fscanf(fp, "%d%d%d", &n, &m, &w);
    fclose(fp);
}
//�����뵽�ڴ��е����ݴ浽�ļ���
void saveToFile()
{
    FILE* fp1 = fopen("schools.txt", "w");
    if (fp1 == NULL)
    {
        printf("�ļ�δ�ɹ��򿪣�����\n");
    }

    //fprintf(fp1, "%d\n", n);//ѧУ����
    for (int i = 0; i < n; i++)
    {
        fprintf(fp1, "%s\n", schools[i].name);
        //numberѧУ���
        //0ѧУ�ܷ�   1�����ܷ�  2Ů���ܷ�
        fprintf(fp1, "%d %d %d %d \n", 
            schools[i].number,schools[i].total_score[0], schools[i].total_score[1], schools[i].total_score[2]);
        for (int j = 0; j < m + w; j++)
        {
            fprintf(fp1, "%d ", schools[i].scores[j]);//������Ŀ�÷�
        }
        fprintf(fp1, "\n\n");
    }
    fclose(fp1);

    FILE* fp2 = fopen("sports.txt", "w");
    if (fp2 == NULL)
    {
        printf("�ļ�δ�ɹ��򿪣�����\n");
    }
    //����������Ŀ������Ů����Ŀ����
    //fprintf(fp2, "%d %d\n", m, w);
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
//���ղ�ͬ�Ĳ�����ѧУ�����������
void merge_sort(School temp[], int st, int en, int option, School temp1[])
{
    //����option��ѡ���ղ�ͬ�Ĳ�������
    //0ѧУ�ܷ֣�1�����ܷ֣�2Ů���ܷ�
    if (en - st == 1)return;//������ķ�Χֻ��һ��Ԫ�أ�ֱ�ӷ���
    int mid = st + (en - st) / 2;
    //��벿��
    merge_sort(temp, st, mid, option, temp1);
    //�Ұ벿��
    merge_sort(temp, mid, en, option, temp1);

    int st1 = st, st2 = mid, tst = st;
    //�ϲ���������������
    while (st1 < mid && st2 < en)
    {
        if (temp[st1].total_score[option] > temp[st2].total_score[option])temp1[tst++] = temp[st1++];
        else temp1[tst++] = temp[st2++];
    }
    while (st1 < mid)temp1[tst++] = temp[st1++];
    while (st2 < en)temp1[tst++] = temp[st2++];

    //����
    for (int j = st; j < en; j++)
        temp[j] = temp1[j];
}
//����ѧУ�ɼ���ͳ��
void inputSchoolScores(int schoolnum, int award_num, int i, int pos)
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
//������Ŀ�ɼ��˵�
void inputScores()
{
loop1:
    system("cls");
    printf("�밴˳�����������Ŀ�ɼ�����λ�����λΪǰ������ǰ�����ĳɼ�,���ο�ǰ�������룩��\n");
    firstUsed();
    printf("===========================================\n");
    for (int pos = 0; pos < m + w; pos++)
    {
        printf("��Ŀ����:%s,ȡǰ%d��:\n",sports[pos].name,sports[pos].award_num);
        int award_num = sports[pos].award_num;
        printf("�����ѧУ���:");

        for (int i = 0; i < award_num; i++)
        {
            scanf("%d", &sports[pos].win_school[i]);//�����ѧУ���
            sports[pos].win_school[i]--;
            if (sports[pos].win_school[i] < 0 || sports[pos].win_school[i] >= m + w)
            {
                i--;
                printf("û��������ı�Ŷ�Ӧ��ѧУ�����������룺\n");
                continue;
            }
            //����ѧУ�ɼ���ͳ��
            inputSchoolScores(sports[pos].win_school[i], award_num, i, pos);
        }
        printf("===========================================\n");
    }

    int flag = 0;
loop2:
    system("cls");
    printf("\n\n\n");
    printf("\033[46;37m");
    printf("\t\t**************************************************\n");
    printf("\t\t*     ������������ɣ����������²�����Ӧ���     *\n");
    printf("\t\t*================================================*\n");
    printf("\t\t*       +      1.��������       +                *\n");
    printf("\t\t*================================================*\n");
    printf("\t\t*       +      2.��������       +                *\n");
    printf("\t\t*================================================*\n");
    printf("\t\t*       +      3.�������˵�     +                *\n");
    printf("\t\t*================================================*\n");
    printf("\t\t*       +      4.�˳�ϵͳ       +                *\n");
    printf("\t\t**************************************************\n");
    printf("\033[0m");
    if (flag == 0)printf("��������ѡ���ѡ���Ӧ�ı�ţ�\n");
    else printf("û���������ѡ���ţ����������룺\n");
    int option;
    if (scanf("%d", &option) != 1) {
        printf("�Ƿ����룬���������֣�\n");
        while (getchar() != '\n'); // ��ջ�����
        flag = 1; // ��Ǵ�������
    }
    else flag = 0;

    switch (option)
    {
    case 1:
        saveToFile();
        printf("\n\n\n\t\t\t\t����ɹ�������\n");
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
//���ѧУ�˵�
void showSchool()
{
    const char* str[] = { "�ܷ�","�����ܷ�","Ů���ܷ�" };
    //��������Ƿ����Ҫ�� 0����/1��ȷ
    int flag = 0;
    while (1)
    {
        system("cls");
        printf("\n\n\n");
        printf("\033[0m");//�ָ�Ĭ����ɫ
        printf("\033[46;37m");
        printf("\t\t******************************************\n");
        printf("\t\t*     +    1.��ѧУ����г�      +       *\n");
        printf("\t\t*========================================*\n");
        printf("\t\t*     +    2.��ѧУ�ܷ��г�      +       *\n");
        printf("\t\t*========================================*\n");
        printf("\t\t*     +    3.��������Ŀ�ܷ��г�  +       *\n");
        printf("\t\t*========================================*\n");
        printf("\t\t*     +    4.��Ů����Ŀ�ܷ��г�  +       *\n");
        printf("\t\t*========================================*\n");
        printf("\t\t*     +    5.�������˵�          +       *\n");
        printf("\t\t*========================================*\n");
        printf("\t\t*     +    6.�˳�ϵͳ            +       *\n");
        printf("\t\t******************************************\n");
        printf("\033[0m");//�ָ�Ĭ����ɫ
        if (flag == 0)
            printf("������ѡ���Ӧ��ţ�");
        else printf("û���������ѡ����������룺");
        int option;
        if (scanf("%d", &option) != 1) {
            printf("�Ƿ����룬���������֣�\n");
            while (getchar() != '\n'); // ��ջ�����
            flag = 1; // ��Ǵ�������
            continue; // ���¿�ʼѭ��
        }
        else flag = 0;

        switch (option)
        {
        case 1:
            system("cls");
            printf("\033[36m");//����������ɫ
            printf("\t|\t\tѧУ���ձ���г�                       |\n");  
            printf("\t|______________________________________________________|\n");
            printf("\t|ѧУ���|     ѧУ����     |ѧУ�ܷ�|�����ܷ�|Ů���ܷ�|\n");
            printf("\t|________|__________________|________|________|________|\n");
            for (int i = 0; i < n; i++)
            {
                printf("\t|%8d|%18s|%8d|%8d|%8d|\n",
                    schools[i].number, schools[i].name, schools[i].total_score[0], schools[i].total_score[1], schools[i].total_score[2]);
                printf("\t|________|__________________|________|________|________|\n");
            }
            printf("\033[0m");//�ָ�Ĭ����ɫ
            printf("-----�������������һ��-----");
            getchar();//���ջس���������ʾ��Ϣ
            getchar();
            break;
        case 2:
        case 3:
        case 4:
            system("cls");
            //����ԭ���飬���ı�ԭ����˳��
            for (int i = 0; i < n; i++)
            {
                temp[i] = schools[i];
            }
            merge_sort(temp, 0, n, option - 2, temp1);
            printf("\033[36m");

            printf("\t|\t\tѧУ����%s�г�\t                 |\n", str[option - 2]);
            printf("\t|______________________________________________________|\n");
            printf("\t|ѧУ���|     ѧУ����     |ѧУ�ܷ�|�����ܷ�|Ů���ܷ�|\n");
            printf("\t|________|__________________|________|________|________|\n");
            for (int i = 0; i < n; i++)
            {
                printf("\t|%8d|%18s|%8d|%8d|%8d|\n",
                    temp[i].number, temp[i].name, temp[i].total_score[0], temp[i].total_score[1], temp[i].total_score[2]);
                printf("\t|________|__________________|________|________|________|\n");
            }
            printf("\033[0m");

            printf("-----�������������һ��-----");
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

//���������Ŀ�˵�
void showSports()
{
    int flag = 0;//���
    while (1)
    {
        system("cls");
        printf("\n\n\n");
        printf("\033[0m");//�ָ�Ĭ����ɫ
        printf("\033[46;37m");
        printf("\t\t******************************************\n");
        printf("\t\t*     +    1.��ѯѧУ��Ŀ�ɼ�   +        *\n");
        printf("\t\t*========================================*\n");
        printf("\t\t*     +    2.��ѯ��Ŀ��ѧУ   +        *\n");
        printf("\t\t*========================================*\n");
        printf("\t\t*     +    3.�������˵�         +        *\n");
        printf("\t\t*========================================*\n");
        printf("\t\t*     +    4.�˳�ϵͳ           +        *\n");
        printf("\t\t******************************************\n");
        printf("\033[0m");//�ָ�Ĭ����ɫ
        if (flag == 0)
            printf("������ѡ���Ӧ��ţ�");
        else printf("�������ѡ����ڣ����������룺");
        int option;
        if (scanf("%d", &option) != 1) 
        {
            printf("�Ƿ����룬���������֣�\n");
            while (getchar() != '\n'); // ��ջ�����
            flag = 1; // ��Ǵ�������
            continue; // ���¿�ʼѭ��
        }
        else flag = 0;
        if(option!=4)
            printf("*****************************************************\n");
        int f = 0;
        switch (option)
        {
        case 1:
            //system("cls");
            printf("������Ҫ��ѯ��ѧУ��ţ�");
            int num;
            f = scanf("%d", &num);
            while (f!= 1||num>20||num<0)
            {
                f = scanf("%d", &num);
                while (getchar() != '\n');//��ջ�����
                if (num > 0 && num <= 20)
                    break;
                printf("��������������������:");
            }
            num--;
            printf("������Ҫ��ѯ�ĸ�ѧУ����Ŀ��ţ�");
            int sp;
            f = scanf("%d", &sp);
            while (f != 1 || sp > m + w || sp < 0)
            {
                f = scanf("%d", &sp);
                while (getchar() != '\n');//��ջ�����
                if (sp > 0 && sp <= m + w)
                    break;
                printf("��������������������:");
            }
            sp--;
            printf("==================================================\n");
            printf("|%s��%s��Ŀ�񽱵÷������", schools[num].name, sports[sp].name);
            printf("%3d ��\n", schools[num].scores[sp]);
            printf("==================================================\n");
            printf("-----�������������һ��-----");
            getchar();
            getchar();
            break;
        case 2:
            //system("cls");
            printf("������Ҫ��ѯ����Ŀ��ţ�");
            int num1;
            scanf("%d", &num1);
            //����������20 ����0
            if (num1 <= 0 || num1 > 20)
            {
                printf("���������Ŀ�����������������:");
                scanf("%d", &num1);
            }
            num1--;
            printf("����ѯ��%s��Ŀ�Ļ�ѧУ���£�\n", sports[num1].name);
            printf("\t____________________________________\n");
            printf("\t|ѧУ���|     ѧУ����     | ���� |\n");
            printf("\t|________|__________________|______|\n");
            for (int i = 0; i < sports[num1].award_num; i++)
            {
                printf("\t|%8d|%18s|%4d  |\n", 
                    schools[sports[num1].win_school[i]].number, schools[sports[num1].win_school[i]].name,i+1);
                printf("\t|________|__________________|______|\n");
            }
            printf("-----�������������һ��-----");
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
//���ò˵�(����ǰ����ǰ�塢ѧУ��������Ŀ����)
void setting()
{
    while (1)
    {
        system("cls");
        printf("\n\n\n");
        printf("\033[0m");//�ָ�Ĭ����ɫ
        printf("\033[46;37m");//������ɫ
        printf("\t\t******************************************\n");
        printf("\t\t*     +    1.������Ŀǰ����ǰ��  +       *\n");
        printf("\t\t*========================================*\n");
        printf("\t\t*     +    2.����ѧУ��Ŀ        +       *\n");
        printf("\t\t*========================================*\n");
        printf("\t\t*     +    3.����������Ŀ��Ŀ    +       *\n");
        printf("\t\t*========================================*\n");
        printf("\t\t*     +    4.����Ů����Ŀ��Ŀ    +       *\n");
        printf("\t\t*========================================*\n");
        printf("\t\t*     +    5.�������˵�          +       *\n");
        printf("\t\t*========================================*\n");
        printf("\t\t*     +    6.�˳�ϵͳ            +       *\n");
        printf("\t\t*========================================*\n");
        printf("\t\t******************************************\n");
        printf("\033[0m");//�ָ�Ĭ����ɫ

        printf("������ѡ���Ӧ��ţ�");
        int option;
        scanf("%d", &option);

        printf("**********************************************\n");
        switch (option)
        {
        case 1:
            while (1)
            {
                //system("cls");
                printf("������Ҫ���õ���Ŀ��ţ�");
                int n1;
                scanf("%d", &n1);
                n1--;
                printf("������3��5���ø���ĿҪȡ�Ļ����Σ�");
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
                    printf("������������������������룺");
                }
                printf("��������������1��������һ��������2��");
                scanf("%d", &n1);
                if (n1 == 1)continue;
                else if (n1 == 2)break;
            }
            break;
        case 2:
            //system("cls");
            printf("������ѧУ��Ŀ��");
            while (1)
            {
                scanf("%d", &n);
                //����ѧУ�������ܴ���20������С��1
                if (n <= 20 && n >= 1)break;
                else
                {
                    //system("cls");
                    printf("�������ѧУ��Ŀ���Ϸ������������룺");
                }
            }
            printf("-----�������������һ��-----\n");
            getchar();
            getchar();
            break;
        case 3:
            //system("cls");
            printf("������������Ŀ��Ŀ��");
            while (1)
            {
                scanf("%d", &m);
                //������Ŀ�������ܴ���20������С��1
                if (m <= 20 && m >= 0)break;
                else
                {
                    //system("cls");
                    printf("�������������Ŀ��Ŀ���Ϸ������������룺");
                }
            }
            printf("-----�������������һ��-----\n");
            getchar();
            getchar();
            break;
        case 4:
            //system("cls");
            printf("������Ů����Ŀ��Ŀ��");
            while (1)
            {
                scanf("%d", &w);
                //Ů����Ŀ�������ܴ���20������С��1
                if (w <= 20 && w >= 0)break;
                else
                {
                    //system("cls");
                    printf("�������Ů����Ŀ��Ŀ���Ϸ������������룺");
                }
            }
            printf("-----�������������һ��-----\n");
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
            printf("�ļ�δ�ɹ��򿪣�����\n");
            system("pause");
        }
        for (int i = 0; i < m + w; i++)
        {
            fprintf(fp, "%d ", sports[i].award_num);// ȡ3����5��
        }
        //for (int i = m + w; i < 50; i++)
        //{
        //    fprintf(fp, "%d ", default_num);//
        //}
        fprintf(fp, "\n%d\n%d\n%d\n", n, m, w);
        fclose(fp);
    }
}
//����ѧУ����Ŀ���Ʋ˵�
void inputName()
{
    int flag = 0;
    while (1)
    {
        system("cls");
        printf("\n\n\n");
        printf("\033[46;37m");//���ñ�����ɫ��������ɫ
        printf("\t\t******************************************\n");
        printf("\t\t*     +      1.����ѧУ����        +     *\n");
        printf("\t\t*========================================*\n");
        printf("\t\t*     +      2.���������Ŀ����    +     *\n");
        printf("\t\t*========================================*\n");
        printf("\t\t*     +      3.�������˵�          +     *\n");
        printf("\t\t*========================================*\n");
        printf("\t\t*     +      4.�˳�ϵͳ            +     *\n");
        printf("\t\t*========================================*\n");
        printf("\t\t******************************************\n");
        printf("\033[0m");//�ָ�Ĭ����ɫ
        if (flag == 0)
            printf("������ѡ���Ӧ��ţ�");
        else printf("û���������ѡ����������룺");
        int option;
        if (scanf("%d", &option) != 1) {
            printf("�Ƿ����룬���������֣�\n");
            while (getchar() != '\n'); // ��ջ�����
            flag = 1; // ��Ǵ�������
            continue; // ���¿�ʼѭ��
        }
        else flag = 0;
        switch (option)
        {
        case 1:
            system("cls");
            printf("�밴�ձ��˳������ %d ��ѧУ���ƣ�(������ɺ��Զ�����)\n",n);
            for (int i = 0; i < n; i++)
            {
                printf("��� %d��", i + 1);
                char tmp[20] = {'\0'};
                scanf("%s", tmp);
                if (strcmp(tmp, "stop") == 0)
                {
                    n = i;
                    printf("����ֹͣ!\n");
                    break;
                }
                strcpy(schools[i].name, tmp);
                schools[i].number = i + 1;
                //printf("...%s", schools[i].name);
            }
            printf("-----�������������һ��-----\n");
            saveToFile();//���浽�ļ�
            getchar();
            getchar();
            break;
        case 2:
            system("cls");
            printf("�밴�ձ��˳������ %d ����Ŀ���ƺ� %d ��Ů����Ŀ���ƣ�(������ɺ��Զ�����)\n",m,w);
            for (int i = 0; i < m + w; i++)
            {
                char tmp[20] = { '\0' };
                if (i < m)
                {
                    printf("������Ŀ ��� %d��", i + 1);
                }
                else
                {
                    printf("Ů����Ŀ ��� %d��", i + 1);
                }
                scanf("%s", tmp);
                if (strcmp(tmp, "stop") == 0)
                {
                    if (i < m)
                        m = i;//ֹͣʱ�������������Ŀ��
                    if (i > m)
                        w = m + w - i - 1;//ֹͣʱ�������Ů����Ŀ��
                    printf("����ֹͣ!\n");
                    break;
                }
                strcpy(sports[i].name, tmp);
                sports[i].number = i + 1;
            }
            printf("-----�������������һ��-----\n");
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
//���в���ѧУ
void showAllSchools()
{
    system("cls");
    printf("\n\n");
    printf("\033[36m");
    printf("\t|========���в���ѧУ=======|\n");
    printf("\t_____________________________\n");
    printf("\t|ѧУ���|     ѧУ����     |\n");
    printf("\t|________|__________________|\n");
    for (int i = 0; i < n; i++)
    {
        printf("\t|%8d|%18s|\n",
            schools[i].number, schools[i].name);
        printf("\t|________|__________________|\n");
    }
    printf("\033[0m");
    printf("-----�������������һ��-----");
    getchar();
    getchar();
}
//չʾ���б�����Ŀ
void showAllGames()
{
    system("cls");
    printf("\n\n");
    printf("\033[36m");
    printf("\t|========���б�����Ŀ=======|\n");
    printf("\t_____________________________\n");
    printf("\t|��Ŀ���|     ��Ŀ����     |\n");
    printf("\t|________|__________________|\n");
    for (int i = 0; i < m+w; i++)
    {
        printf("\t|%8d|%18s|\n",
            sports[i].number, sports[i].name);
        printf("\t|________|__________________|\n");
    }
    printf("\033[40;37m");
    printf("-----�������������һ��--------------");
    getchar();
    getchar();
}
//���˵��Ĳ���
void menu()
{
    int flag = 0;
    while (1)
    {
        system("cls");
        printf("\n\n");
        //��ӡ�˵���
        printf("\033[46;37m");
        printf("\n\t\t+==============================================================+\n");
        printf("\t\t+                �˶������ͳ��ϵͳ  ���˵�                    +\n");
        printf("\t\t+==============================================================+\n");
        printf("\033[0m");//�ָ�Ĭ����ɫ
        printf("\033[42;30m");
        printf("\t\t+ ����Ϣ¼�롿                                                 +\n");
        printf("\t\t+     1. ����ѧУ����Ŀ����       2.������Ŀ�ɼ�               +\n");
        printf("\t\t+--------------------------------------------------------------+\n");
        printf("\033[42;30m");
        printf("\t\t+ ���鿴��Ϣ��                                                 +\n");
        printf("\t\t+     3.�鿴����ѧУ        4.�鿴������Ŀ                     +\n");
        printf("\t\t+     5.�鿴ѧУ�ɼ�        6.�鿴��Ŀ�ɼ�                     +\n");
        printf("\t\t+--------------------------------------------------------------+\n");
        printf("\033[42;30m");
        printf("\t\t+ �����á�                                                     +\n");
        printf("\t\t+     7.����                                                   +\n");
        printf("\t\t+--------------------------------------------------------------+\n");
        printf("\033[42;30m");
        printf("\t\t+  0. �˳�ϵͳ                                                 +\n");
        printf("\033[41;33m");
        printf("\t\t+--------------------------------------------------------------+\n");
        printf("\t\t+ ����ʾ��                                                     +\n");
        printf("\t\t+     1.����ʹ��ʱ������¼�������Ϣ                           +\n");
        printf("\t\t+     2.Ĭ������Ϊ10������ѧУ��5��������Ŀ��5��Ů����Ŀ       +\n");
        printf("\t\t+--------------------------------------------------------------+\n");
        printf("\033[0m");//�ָ�Ĭ����ɫ
        if (flag == 0)
            printf("�������Ӧѡ��ı�ţ�");
        else printf("û���������ѡ����������룺");
        int option;
        if (scanf("%d", &option) != 1) {
            printf("�Ƿ����룬���������֣�\n");
            while (getchar() != '\n'); // ��ջ�����
            flag = 1; // ��Ǵ�������
            continue; // ���¿�ʼѭ��
        }
        else 
            flag = 0;
        switch (option)
        {
        case 1:
            //����ѧУ����Ŀ����
            inputName();
            break;
        case 2:
            //������Ŀ�ɼ�
            inputScores();
            break;
        case 3:
            //�鿴����ѧУ
            showAllSchools();
            break;
        case 4:
            //�鿴������Ŀ
            showAllGames();
            break;
        case 5:
            //�鿴ѧУ�ɼ�
            showSchool();
            break;
        case 6:
            //�鿴��Ŀ�ɼ�
            showSports();
            break;
        case 7:
            //����
            setting();
            break;
        case 0:
            //�˳�ϵͳ
            saveToFile();
            Sleep(1000);
            exit(0);
            break;
        default:
            flag = 1;
        }
    }
}


