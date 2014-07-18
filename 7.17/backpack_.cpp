#include <iostream>
#include <stdio.h>
using namespace std;

int Space = 40;

int Sum[41];

int Init()
{
    for(int i = 0; i < Space; i++)
        Sum[i] = 0;
};

int main()
{
    int n;
    int sp;
    int i,j;
    scanf("%d",&n);
    Init();
    for(i = 0; i < n; i++)
    {
        scanf("%d",&sp);
        for(j = 40; j >= 1; j--)
        {
            if(Sum[j] > 0 && j+sp <= 40)
                Sum[j+sp] += Sum[j];
        }
        Sum[sp]++;
    }
    printf("%d",Sum[Space]);
}
