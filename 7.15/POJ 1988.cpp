#include <iostream>
#include <stdio.h>
using namespace std;


int Cube[300005];
int Under[300005];

int GetRoot(int a)
{
    if(Cube[a] != a)
        Cube[a] = GetRoot(a);
        return Cubep[a];
}

void Union(int a,int b)
{
    int Roota = GetRoot(a);
    int Rootb = GetRoot(b);
    if(Roota == Rootb)
        return;
    Cube[b] = Roota;
    Under[a] = sum[pa];
}




