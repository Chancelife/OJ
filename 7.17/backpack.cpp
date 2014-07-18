#include <iostream>
using namespace std;
#define MAX 41

    int main()
    {
        int n,i,j,input;
        int sum[MAX];
        for(i=0;i<MAX;i++)
            sum[i]=0; cin >> n;
        for(i=0;i<n;i++)
            {
                cin >> input;
        for(j=40;j>=1;j--)

            if(sum[j]>0 && j+input <= 40)
            sum[j+input] += sum[j];
        //如果j有sum[j]种方式可达，则每种方式加上input就可达 j + input
        sum[input]++;
        }
        cout << sum[40] << endl;
    return 0; }
