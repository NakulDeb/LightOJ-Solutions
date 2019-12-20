#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,q,t,x,num;
    //ofstream cout("output_1082.txt");
    cin>>q;
    t=1;
    while(q--){
        cin>>n>>m;
        if(m*n<=4){
            cout<<"Case "<<t++<<": "<<m*n<<endl;
        }
        else if(min(n,m)==1){
            cout<<"Case "<<t++<<": "<<max(n,m)<<endl;
        }
        else if(min(n,m)==2 && (n+m)%4==0){
            cout<<"Case "<<t++<<": "<<n+m<<endl;
        }
        else if(min(n,m)==2 && max(n,m)&1){
            cout<<"Case "<<t++<<": "<<max(n,m)+1<<endl;
        }
        else if(min(n,m)==2 && max(n,m)&1 == 0){
            cout<<"Case "<<t++<<": "<<max(n,m)<<endl;
        }

        else{
            x = n*m;
            x++;
            x = x/2;
            cout<<"Case "<<t++<<": "<<x<<endl;
        }

    }
    return 0;

}
