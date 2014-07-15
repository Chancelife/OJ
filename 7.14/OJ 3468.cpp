/*==================================================================
����Q (1 �� Q �� 100,000)����A1,A2 �� AQ,�� �Լ����ܶ�ν��е���������:
1) ��ĳ������Ai �� Aj��ÿ��������n(n�ɱ� ��
2) ��ĳ������Ai �� Aj�����ĺ�
�������ڵ�Ҫ����Щ��Ϣ��
ֻ�����������ĺͣ��в��У�
====================================================================*/

#include <iostream>
#include <stdio.h>
using namespace std;

struct CNode
{
    int L,R;
    CNode * pLeft, * pRight;
    long long n_Sum;//��Ҫ���ӵ��ܺ�
    long long Inc;//����c�ۼ�
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
    if(L==R)//�ǽڵ�
        return;
    Count++;
    pRoot->pLeft = Tree + Count;//��ڵ�
    Count ++;
    pRoot->pRight = Tree + Count;//�ҽڵ�

    BuildTree(pRoot->pLeft,L,(L+R)/2);
    BuildTree(pRoot->pLeft,(L+R)/2+1,R);//�ݹ���֦
}



int main()
{
    int n;
    scanf("%d",&n);
    BuildTree(Tree,1,n);

    printf("%d %d",Tree[4].pLeft,Tree[4].R);
}
