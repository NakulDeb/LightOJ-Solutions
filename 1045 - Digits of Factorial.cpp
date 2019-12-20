#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define PI 2*acos(0.0)
using namespace std;
ll factorial_digit_count(ll n,ll base){if(n<2) return 1;double d=0,dv = log(base);for(int i=2; i<=n; i++){d += log(i)/dv;}return (int)floor(d+1);}
ll factorial_digit_count_using_sumation(ll n,ll base){double ME = 2.71828182845904523536;double MYPI = 3.141592654;if(n<2) return 1;double x = ((n * log(n / ME)/log(base) +  (log(2 * MYPI * n)/log(base)) / 2.0));return (ll)floor(x+1);}


int main()
{
    ll q,t,num,i,x,base;
    scanf("%lld",&q);
    t=1;
    while(q--){
        scanf("%lld%lld",&num,&base);
        printf("Case %lld: %lld\n",t++,factorial_digit_count_using_sumation(num,base));
    }
    return 0;
}
