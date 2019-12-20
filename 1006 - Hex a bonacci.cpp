#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define mx_index 10005
using namespace std;

int arr[mx_index];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,q,t,i,j,x,sum,temp_sum,md = 10000007;
    cin>>q;
    //ofstream cout("output_1082.txt");
    t=1;
    while(q--){
        for(i=0; i<6; i++){
            cin>>arr[i];
            arr[i] = arr[i]%md;
        }
        j = i;
        cin>>n;
        x = 0;
        for(i=6; i<=n; i++){
            sum = 0;
            for(j=x; j<i; j++){
                sum = (sum + arr[j])%md;
            }
            arr[i] = sum;
            x++;
        }
        cout<<"Case "<<t++<<": "<<arr[n]<<endl;
    }
    return 0;

}
