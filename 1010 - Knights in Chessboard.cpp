#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

int main()
{
    int n,m,q,t,x,num;
    //ofstream cout("output_1082.txt");
    scanf("%d",&q);
    t=1;
    while(q--){
        scanf("%d%d",&n,&m);
        num = 0;
        if(m*n<=4){
            num = m*n;
        }
        else if(min(n,m)==1){
            num = max(n,m);
        }
        else if(min(n,m)==2 && (n+m)%4==0){
            num = n+m;
        }
        else if(min(n,m)==2 && max(n,m)&1){
            num = max(n,m)+1;
        }
        else if(min(n,m)==2 && max(n,m)&1 == 0){
            num = max(n,m);
        }

        else{
            x = n*m;
            x++;
            x = x/2;
            num = x;

        }
        printf("Case %d: %d\n",t++,num);

    }
    return 0;

}
