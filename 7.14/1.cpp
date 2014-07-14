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
//递归调用初始化树,Mid()测试

void Insert(int root, int i,int v)
//第i个数，值为v{
    if(tree[root].L==tree[root].R){
        tree[root].minL = tree[root].maxR = v;
        return;
    }
    tree[root].minL = min(tree[root].minL,v);
    tree[root].maxR = max(tree[root].maxR,v);
    //v,对比左右区间值
    if(i<=tree[root].Mid())
        Insert(2*root+1,i,v);
    else
        Insert(2*root+2,i,v);
}

void Query(int root,int sl,int sr)
    //查询区间[sl,sr]
{
    if(minL >= tree[root].minL  && tree[root].maxR <= maxR)
    //如果全局最小值<[左节点 并且 右节点]<全局最大值
    return;
}

int main(){
    int i;
    int n;
    int h;
    scanf("%d",&n);
    BuildTree(0,1,n);
    for(i = 1;i <= n;i ++ )
        {
            scanf("%d",&h);
            Insert(0,i,h);
        }
    for(i = 0 ;i <= n*2; i++ )
    printf("%d %d min:%d max:%d\n",tree[i].L,tree[i].R,tree[i].minL,tree[i].maxR);


}

