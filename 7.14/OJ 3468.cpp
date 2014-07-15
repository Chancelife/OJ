/*==================================================================
给定Q (1 ≤ Q ≤ 100,000)个数A1,A2 … AQ,， 以及可能多次进行的两个操作:
1) 对某个区间Ai … Aj的每个数都加n(n可变 ）
2) 求某个区间Ai … Aj的数的和
本题树节点要存哪些信息？
只存该区间的数的和，行不行？
====================================================================*/

#include <iostream>
#include <stdio.h>
using namespace std;

struct CNode
{
    int L,R;
    CNode * pLeft, * pRight;
    long long n_Sum;//需要增加的总和
    long long Inc;//增量c累加
};

CNode Tree[200005];

int Count = 0;
int Mid(CNode * pRoot)
{
    return (pRoot->L + pRoot-> R)/2;
}

void BuildTree(CNode * pRoot,int L, int R)
{
    pRoot->L = L;
    pRoot->R = R;
    pRoot->n_Sum = 0;
    pRoot->Inc = 0;
    if(L==R)//是节点
        return;
    Count++;
    pRoot->pLeft = Tree + Count;//左节点
    Count ++;
    pRoot->pRight = Tree + Count;//右节点

    BuildTree(pRoot->pLeft,L,(L+R)/2);
    BuildTree(pRoot->pLeft,(L+R)/2+1,R);//递归树枝
}



int main()
{
    int n;
    scanf("%d",&n);
    BuildTree(Tree,1,n);

    printf("%d %d",Tree[4].pLeft,Tree[4].R);
}
