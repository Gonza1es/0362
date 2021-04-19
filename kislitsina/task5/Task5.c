#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

void menu();//������ ����
int TenToFact();//������� �� 10 �� � �������������
int FactToTen();//������� �� ������������� �� � 10-��
int GetNumOfTransp();//��������� ������ ������������ �� ������ � ��������
int GetTranspByNum();//��������� ������������ �� ������ � ��������
int GetNextTransp();//��������� ��������� ������������ �� �������
int GetFactorial();//���������� ���������� �����

int main()
{
    setlocale(LC_ALL, "Rus");
    int choice;
    int a, b;
    system("cls");
    menu();
    A: scanf("%d", &choice);//����� ��������
    switch (choice){
case 1: printf("������� �����, ������� ����� ���������\n"); scanf("%d", &a);
        printf("����� � ������������� ������� ���������: %d\n", TenToFact(a)); break;
case 2: printf("������� �����, ������� ����� ���������\n"); scanf("%d", &a);
        printf("����� � ���������� ������� ���������: %d", FactToTen(a)); break;
case 3: printf("����������, ������� ���������� ��������� � ������������\n"); scanf("%d", &a); GetNextTransp(a); break;
case 4: printf("����������, ������� ���������� ��������� � ������������\n"); scanf("%d", &a); GetNumOfTransp(a); break;
case 5: printf("����������, ������� ���������� ��������� � ��������\n"); scanf("%d", &a); GetTranspByNum(a); break;
default: printf("���� ������� �������� �����. ���������� �����\n"); goto A;
    }
    return 0;
}

void menu()
{
    printf("\t\t����������, �������� ����������� ��������:\n\n");
    printf("1 - ������� �� 10 �� � �������������\t\t 2 - ������� �� ������������� � 10 ��\n");
    printf("3 - ��������� ��������� ������������ �� �������\t 4 - ��������� ������ �� ������������ � ��������\n");
    printf("5 - ��������� ������������ �� ������ � ��������\n");
}

int GetFactorial(int count)
{
    int res = 1;
    for (size_t j = 1; j <= count; j++)
    {
        res = res*j;
    }
    return res;
}

int TenToFact(int num)
{
    int p = 0, i = 2, k = 0;
    float deg;
    do
    {
       deg = pow(10, k);//�������� 10 � ��������������� ������� ��� ��������� �������� �����
       p += (num%i)*deg;
       num = num/i;
       k++;
       i++;
    } while(num != 0);
    return p;
}

int FactToTen(int num)
{
    int result = 0, i = 1, ost = 0, f = 0;
    do
    {
        ost = num % 10;
        num = num / 10;
        f = GetFactorial(i);
        result += ost*f;
        i++;
    } while (num != 0);
    return result;
}

int GetNextTransp(int size)
{
    int *t;
    int m = size - 2, q = size - 1, p;
    t = (int*)malloc(size*sizeof(int));
    printf("������� ������������\n");
    for(size_t i = 0; i < size; i++)
    {
        scanf("%d", &t[i]);
    }
    while (m != -1 && t[m] >= t[m+1])//���� ����� ��������
    {
        m--;
    }
    if (m == -1)
    {
        printf("������������ ������ ���\n");
    }
    while (t[q] <= t[m]) q--;//���� �������
    p = t[m];//����� �������� ������ ������� ���������� ������� �������� � ����� ��������
    t[m] = t[q];
    t[q] = p;
    m = m + 1;
    q = size - 1;
    while (m < q)//��������� �������� ��������
    {
        p = t[m+1];
        t[m+1] = t[q-1];
        t[q-1] = p;
    }
    printf("��������� ������������: \n");
    for (size_t i = 0; i < size; i++) printf("%d", t[i]);
    free(t);
    return 0;
}

int GetNumOfTransp(int size)
{
    int *t, *f, *inv;
    int number = 0;
    t = (int*)malloc(size*sizeof(int));
    printf("������� ������������\n");
    for(size_t i = 1; i <= size; i++)
    {
        scanf("%d", &t[i]);//������������
    }
    f = (int*)malloc(size*sizeof(int));
    inv = (int*)malloc(size*sizeof(int));
    for (size_t i = 1; i <= size; i++) inv[i] = 0;//������ ��������
    f[0] = 1;
    for (size_t i = 1; i <= size; i++) f[i] = f[i-1]*i;//������ �����������
    for (size_t i = 1; i <= size; i++)
    {
        for (size_t j = i+1; j <= size; j++)
        if (t[i]>t[j]) inv[i] += 1;
        number += inv[i]*f[size - i];//����� ������������ = ���������� �������� ��� ������� ����� * �������������� ���������(������� � ����� 2)
    }
    printf("����� ������������: %d\n", number+1);
    free(t);
    free(f);
    free(inv);
    return 0;
}

int GetTranspByNum(int size)
{
    int *t, *ost, *ans;
    int number, m;
    float q;
    t = (int*)malloc(size*sizeof(int));
    ans = (int*)malloc(size*sizeof(int));
    printf("������� ������� (��� ��������� ���������� ����� ��������� ������������� �����)\n");
    for(size_t i = 0; i < size; i++)
    {
        scanf("%d", &t[i]);
        ans[i] = 0;
    }
    printf("������� ����� ������� ������������:\n");
    A: scanf("%d", &number);
    m = GetFactorial(size);//������� ��������� ����� ��������� � ��������
    if (number > m) {printf("������� ����� �������, ��� %d\n", m); goto A;}//����� ������������ �� ������ ��������� ���������� ����� ��������� � ��������
    number = TenToFact(number-1);
    ost = (int*)malloc(size*sizeof(int));//������ �� �����, �� ������� ������������ number
    for(int i = 0; i < size; i++)
    {
        q = pow(10, size - i - 2);//�������� 10 � �������������� �������
        ost[i] = number/q;//�������� ����� ���������� (������� � ������ �������� �������)
        number -= ost[i]*q;//��������� � ���������� �������
    }
    for (int i = 0; i < size; i++)//������� ��� ost
    {
        for (int j = 0; j < size; j++)//������� ��� t(�������)
        {
            if (ost[i] == j)//��� ���������� �������� ����� ����������� ��������� ��������
            {
                ans[i] = t[j];
                for (int l = j; l < size - 1; l++) t[l] = t[l + 1];//������������ �����
                t[size - 1] = 0;
            }
        }
    }
    printf("������� ������������\n");
    for(size_t i = 0; i < size; i++)
    {
        printf("%d", ans[i]);
    }
    free(t);
    free(ost);
    return 0;
}

