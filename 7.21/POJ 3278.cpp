tx#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int Maxp[100005];
int Visited[100005];

struct Step{
    int P;//位置P
    int steps;
    Step(int xx,int s):P(xx),steps(s){}//重构
};

queue<Step> Q;

int main()
{
    int N,K;
    cin>>N>>K;
    memset(Visited,0,sizeof(Visited));//初始化
    Q.push(Step(N,0));//传入
    Visited[N] = 1;//Visit标记

    while(!Q.empty())
    {
        Step q = Q.front();
        if(q.P == K)
        {
            cout<<q.steps<<endl;
            return 0;
        }
        else
        {
            if(q.P-1 > 0 && !Visited[q.P-1])
            {
                Q.push(Step(q.P-1,q.steps+1));
                Visited[q.P-1];
            }
            if(q.P+1 <100005 && !Visited[q.P+1])
            {
                Q.push(Step(q.P+1,q.steps+1));
                Visited[q.P+1];
            }
            if(q.P*2 < 100005 && !Visited[q.P*2])
            {
                Q.push(Step(q.P*2,q.steps+1));
                Visited[q.P*2];
            }
            Q.pop();
        }
    }
    return 0;
}


