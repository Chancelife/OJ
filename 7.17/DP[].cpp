#include <iostream>
#include <stdio.h>
using namespace std;

int Base[100][100];
int Temp[100];
int line = 0;

void Init()
{
    for(int i = 0; i < line; i++)
        {
            Temp[i] = 0;
        }
}

void SumLine(int LineNo)
{
    for(int i = 0; i <= LineNo; i++)
    {
        Temp[i] = Base[LineNo][i] + max(Temp[i],Temp[i+1]);
    }
}

int main()
{
    int i,j;
    scanf("%d",&line);
    for(i = 0; i < line; i++)
        {
            for(j = 0; j <= i; j++)
            {
            scanf("%d",&Base[i][j]);
            }
        }
    Init();
    for(i = line-1; i >= 0; i--)
        {
        SumLine(i);
        printf("%d %d %d\n",Temp[0],Temp[1],Temp[2]);
        }
    printf("%d",Temp[0]);
}
