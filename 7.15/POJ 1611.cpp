#include <iostream>
#include <stdio.h>
using namespace std;

int Total[30005];

void Init(int n)
//��ʼ�� ��ѡ
{
    for(int i = 0 ;i < n ;i++)
        Total[i] = i;
}

int GetRoot(int a)
//��ѯ���ڵ�
{
    if(Total[a] != a)
    {
        Total[a] = GetRoot(Total[a]);
    }
    return Total[a];
}

void Union(int a,int b)
{
    int num1,num2;//��ֹwarning����������
    num1 = GetRoot(a);
    num2 = GetRoot(b);
    if(num1 != num2)
        Total[b] = Total[a];
    printf("union %d & %d\n",a,b);
}

int Connected(int a,int b)//if connected
{
    if(Total[a] == Total[b])
        {
        printf("True\n");
        return 1;
        }
    else
        {
        printf("False\n");
        return 0;
        }
}

int main()
{
    int n,group;
    int stus,stu_fir,stu_oth;
    int i,j;
    int Count = 0;
    scanf("%d %d",&n,&group);
    Init(n);
    //��ʼ��
    for(i = 0; i < group; i++)
        {
        scanf("%d %d",&stus,&stu_fir);
        //stu_fir���ں����ڵ�һ��ͬѧUnion
            for(j = 1; j < stus; j++)
            {
                scanf("%d",&stu_oth);
                Union(stu_fir,stu_oth);
            }
        }
    for(i = 0; i < n; i++)
        {
            if(Total[i] == 0)
                Count++;
        }
        printf("%d",Count);
        //ûдCount[]
        //������ʵ��+N��
}




