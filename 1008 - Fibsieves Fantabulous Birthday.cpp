#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,q,t,i,j,x,y;
    cin>>q;
    //ofstream cout("output_1082.txt");
    t=1;
    while(q--){
        cin>>n;
        x = sqrt(n-1);
        x++;
        y = (x*x) - (x-1);
        ll col = x;
        ll row = x-abs(y-n);
        cout<<"Case "<<t++<<": ";
        if(y==n) cout<<x<<" "<<x<<endl;
        else if(x&1){
            if(y>n) cout<<col<<" "<<row<<endl;
            else    cout<<row<<" "<<col<<endl;
        }
        else{
            if(y<n) cout<<col<<" "<<row<<endl;
            else    cout<<row<<" "<<col<<endl;
        }
    }
    return 0;

}
