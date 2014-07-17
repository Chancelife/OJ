#include <iostream>
#include <stdio.h>
using namespace std;

const int INF = 0xffffff0;
int minL = INF;
int maxR = -INF;

struct Node
{
    int L,R;
    int minL,maxR;
    int Mid(){
        return (L+R)/2;
        }
};
Node tree[8000005];

void BuildTree(int root,int L,int R)
{
    tree[root].L = L;
    tree[root].R = R;
    tree[root].minL = INF;
    tree[root].maxR = -INF;
    if(L!=R){
        BuildTree(2*root+1,L,tree[root].Mid());
        BuildTree(2*root+2,tree[root].Mid()+1,R);
    }
};
//�ݹ���ó�ʼ����,Mid()����

void Insert(int root, int i,int v)
//��i������ֵΪv{
    if(tree[root].L==tree[root].R){
        tree[root].minL = tree[root].maxR = v;
        return;
    }
    tree[root].minL = min(tree[root].minL,v);
    tree[root].maxR = max(tree[root].maxR,v);
    //v,�Ա���������ֵ
    if(i<=tree[root].Mid())
        Insert(2*root+1,i,v);
    else
        Insert(2*root+2,i,v);
}

void Query(int root,int sl,int sr)
    //��ѯ����[sl,sr]
{
    if(minL <= tree[root].minL  && tree[root].maxR <= maxR)
    //���ȫ����Сֵ<[��ڵ� ���� �ҽڵ�]<ȫ�����ֵ ���������м䣬������return
    return;

    if(tree[root].L == sl && tree[root].R == sr){
        //��ڵ�=sl �ҽڵ�=sr
        minL = min(minL,tree[root].minL);
        maxR = max(maxR,tree[root].maxR);
        return;
    }

    if(sr <= tree[root].Mid())
        Query(2*root+1,sl,sr);
        //������֧
    else if(sl > tree[root].Mid())
        Query(2*root+2,sl,sr);
        //������֧
    else{
        Query(2*root+1,sl,tree[root].Mid());
        Query(2*root+2,tree[root].Mid()+1,sr);
    }
}

int main(){
    int i;
    int n,q;
    int h;
    scanf("%d %d",&n,&q);
    BuildTree(0,1,n);
    for(i = 1;i <= n;i ++ )
        {
            scanf("%d",&h);
            Insert(0,i,h);
        }
    for(i = 0;i < q; i++){
        int sl,sr;
        scanf("%d %d",&sl,&sr);
        minL = INF;
        maxR = -INF;
        Query(0,sl,sr);
        printf("%d\n",maxR - minL);
    }


    //for(i = 0 ;i <= n*2; i++ )
    //printf("%d %d min:%d max:%d\n",tree[i].L,tree[i].R,tree[i].minL,tree[i].maxR);
}

//AC!
