#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define PI 2*acos(0.0)
using namespace std;


int main()
{
    int q,t,arr[3],a,b,x;
    scanf("%d",&q);
    t=1;
    while(q--){
        int time = 0;
        scanf("%d%d",&a,&b);
        x = abs(a-b);
        time = x*4 + 19 + a*4;

        printf("Case %d: %d\n",t++,time);
    }
    return 0;
}
