#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,x;
    cin>>t;

    while(t--){
        cin>>n;
        x =  (n>20?n-n%20:n);
        cout<<x/2<<" "<<(x%2==1? (x/2)+1 : x/2)<<endl;
    }
    return 0;
}
