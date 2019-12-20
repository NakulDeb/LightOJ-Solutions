#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define PI 2*acos(0.0)
#define max_index 100005
using namespace std;


int main()
{
    int q,t,x,n,i,area,max_area;
    //freopen("output2.txt","w",stdout);
    scanf("%d",&q);
    t=1;
    while(q--){
        int time = 0;
        scanf("%d",&n);
        int arr[n+5];stack<int>s;
        for(i=0; i<n; i++) scanf("%d",&arr[i]);

        max_area = -1;
        area = 0;
        i=0;
        while(i<n){
            if(s.empty() || arr[s.top()]<=arr[i]){
                s.push(i++);
            }
            else{
                x = s.top();
                s.pop();
                area = arr[x]*(s.empty()?i : i-s.top()-1);
            }
            max_area = max(max_area,area);
        }

        while(!s.empty()){
                x = s.top();
                s.pop();
                area = arr[x]*(s.empty()?i : i-s.top()-1);
                max_area = max(max_area,area);
        }
        printf("Case %d: %d\n",t++,max_area);
    }
    return 0;
}
