#include <iostream>
#include <stdio.h>
using namespace std;

int Total[30005];
int Sum[30005];

void Init(int n)
{
    for(int i = 0 ;i < n ;i++)
    {
        Total[i] = i;
        Sum[i] = 1;
    }
}

int GetRoot(int a)
//查询根节点
{
    if(Total[a] != a)
    {
        Total[a] = GetRoot(Total[a]);
    }
    return Total[a];
}

void Union(int a,int b)
{
    int num1 = GetRoot(a);
    int num2 = GetRoot(b);

    if(num1 == num2)
        return;

    Sum[num1] += Sum[num2];
    Total[num2] = num1;
    //printf("union %d & %d\n",a,b);
}

int main()
{
    int n,group;
    int stus,stu_fir,stu_oth;
    int i,j;
    while(true) {
        scanf("%d %d",&n,&group);
        if(n == 0 && group == 0)
            break;
        Init(n);
        //初始化
        for(i = 0; i < group; i++)
            {
                scanf("%d %d",&stus,&stu_fir);
                //stu_fir用于和组内第一个同学Union
                for(j = 1; j < stus; ++j)
                {
                    scanf("%d",&stu_oth);
                    Union(stu_fir,stu_oth);
                }
            }
    printf("%d\n",Sum[GetRoot(0)]);
    }
}




