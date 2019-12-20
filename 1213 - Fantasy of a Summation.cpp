#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define ull unsigned long long
using namespace std;
long long const INF = 2e18 + 100;
int const MAX = 3*1e5 +10;
///double area(double x1,double y1,double x2,double y2,double x3,double y3){return fabs((x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))/2.0);}
///bool inside_or_not(double x1,double y1,double x2,double y2,double x,double y){if(x>x1&&x<x2&&y>y1&&y<y2) return true; return false;}
///bool cmp(const pair<int,int> &a, const pair<int,int> &b) { return (a.first > b.first);}
///auto comp = [](string a, string b){ return a > b;};
///priority_queue<string, vector<string>, decltype(comp)>pq(comp);
///priority_queue<string, vector<string>, greater<string> >pq; //or use this
///ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
ll mod_and_pow(ll a, ll b, ll d){ll ans = 1;while(b){if(b&1) ans = (ans*a)%d;a = (a*a)%d;b >>= 1;}return ans;}

ll l = (1LL<<62);
ull m = (1LL<<63);
vector< pair <int,int> > v;
multiset<int>mset; /// default sorting with ascending order.
multiset<int, greater<int> >ms;


ll cases, caseno;
ll n, k, MOD;
ll A[1001];


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    scanf("%lld", &cases);
    while( cases-- ) {
        scanf("%lld %lld %lld", &n, &k, &MOD);

        ll i,j, i1, i2, i3, iK;

        for( i = 0; i < n; i++ ) scanf("%lld", &A[i]);

        ll res = 0;
        for(j=0; j<n; j++){
            res = (res+A[j]*((int)mod_and_pow(n,k-1,MOD)))%MOD;
        }

        res = (res*k)%MOD;

        printf("Case %lld: %lld\n", ++caseno, res);
    }




    return 0;
}
