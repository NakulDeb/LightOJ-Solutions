#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define PI 2*acos(0.0)
using namespace std;


int main()
{
    int q,t,arr[3];
    scanf("%d",&q);
    t=1;
    while(q--){
        scanf("%d%d%d",&arr[0],&arr[1],&arr[2]);
        sort(arr,arr+3);
        char s[5]; strcpy(s,"no");
        if(arr[0]*arr[0] + arr[1]*arr[1] == arr[2]*arr[2]) strcpy(s,"yes");
        printf("Case %d: %s\n",t++,s);
    }
    return 0;
}
