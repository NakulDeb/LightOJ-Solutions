#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define PI 2*acos(0.0)
using namespace std;

int main()
{
    int q,t;
    //ofstream cout("output_1082.txt");
    //freopen("output_1082.txt","w",stdout);
    double r,area,d;
    scanf("%d",&q);
    t=1;
    while(q--){
        scanf("%lf",&r);
        d = r*2;
        area = (d*d) - (PI*r*r);
        printf("Case %d: %.2f\n",t++,area);

    }
    return 0;

}
