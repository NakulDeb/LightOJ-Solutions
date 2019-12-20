#include<bits/stdc++.h>
#define max_index 1001
using namespace std;


int cnt[max_index];
bool visited[max_index];
int n,m,k,num=0;

void BFS(vector<int>graph[],int x){
    memset(visited,false,sizeof(visited));
    queue<int>q;
    q.push(x);
    visited[x]= true;
    cnt[x]++;
    if(cnt[x]==k) num++;

    while(!q.empty()){
        x = q.front();
        q.pop();

        for(auto it=graph[x].begin(); it!=graph[x].end(); it++){
            if(!visited[*it]){
                q.push(*it);
                visited[*it] = true;
                cnt[*it]++;
                if(cnt[*it]==k)num++;
            }
        }
    }
}


int main()
{
    int t,q=1,i,x,y;

    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&k,&n,&m);

        vector<int>graph[n+1];
        int arr[n+1];

        for(i=0; i<k; i++){
            scanf("%d",&arr[i]);
        }
        for(i=0; i<m; i++){
            scanf("%d%d",&x,&y);
            graph[x].push_back(y);

        }
        num=0;
        memset(cnt,0,sizeof(cnt));
        for(i=0; i<k; i++){
            BFS(graph,arr[i]);
        }
        printf("Case %d: %d\n",q++,num);
    }
    return 0;
}
