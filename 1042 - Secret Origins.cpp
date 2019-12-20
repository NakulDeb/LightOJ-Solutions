#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define PI 2*acos(0.0)
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int q,t,n,i,x,ones;
    //ofstream cout("output_1082.txt");
    //freopen("output_1082.txt","w",stdout);
    cin>>q;
    t=1;
    while(q--){
        cin>>n;
        x = 0;
        bitset<32>bt(n);

        for(i=0; i<31; i++){
            if(bt.test(i)==1 && bt.test(i+1)==0){
                bt[i] =  0;
                bt[i+1] = 1;
                break;
            }
            if(bt[i]==1) x = i;
        }
        i=0;
        ones = 0;
        while(x>=i){
            if(bt[i]==1){
                ones++;
                bt[i] = 0;
            }
            i++;
        }
        i=0;
        while(ones){
            bt[i++] = 1;
            ones--;
        }
        cout<<"Case "<<t++<<": "<<bt.to_ulong()<<endl;
    }
    return 0;
}
