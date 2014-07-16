#include <iostream>
#include <stdio.h>
using namespace std;

int Total[10005];

void Init(int n)
{
    for(int i = 0 ;i < n ;i++)
        Total[i] = i;
}

void Union(int a,int b)
{
    if(Total[a] == a)
        Total[b] = a;
    else
        Union(Total[a],b);
    printf("union %d & %d\n",a,b);
}

int Connected(int a,int b)//if connected
{
    if(Total[a] == Total[b])
    return 1;
    else
    return 0;
}


int main(){
    int n;
    int t;
    scanf("%d",&n);
    Init(n);

    Union(2,10);
    Union(10,3);
    printf("%d\n",Total[3]);
    t = Connected(5,3);
    printf("%d",t);

    return 0;
}
