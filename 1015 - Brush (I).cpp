#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

int main()
{
    ll n,m,q,t,i,x,num;
    //ofstream cout("output_1082.txt");
    //freopen("output_1082.txt","w",stdout);
    scanf("%lld",&q);
    t=1;
    while(q--){
        scanf("%lld",&n);
        num = 0;
        for(i=0; i<n; i++){
            scanf("%lld",&x);
            if(x>0)num += x;
        }
        printf("Case %lld: %lld\n",t++,num);

    }
    return 0;

}
