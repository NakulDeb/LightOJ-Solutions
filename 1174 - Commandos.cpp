#include<bits/stdc++.h>
#define max_index 100
using namespace std;
int n,r,s,d,num,end_node,l1;
bool visited[max_index];
int distance1[max_index];
int distance2[max_index];

void BFS(vector<int>graph[],int x, int distance[]){
    memset(visited,false,sizeof(visited));
    queue<int>q;
    q.push(x);
    distance[x] = 0;
    visited[x] = true;

    while(!q.empty()){
        x = q.front();
        q.pop();

        for(auto it=graph[x].begin(); it!=graph[x].end(); it++){
            if(!visited[*it]){
                visited[*it] = true;
                q.push(*it);
                distance[*it] = distance[x]+1;
            }
        }
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t,q=1,x,y,i;
    scanf("%d",&t);

    while(t--){
       scanf("%d%d",&n,&r);
       vector<int>graph[max_index];
       for(i=0; i<r; i++){
            scanf("%d%d",&x,&y);
            graph[x].push_back(y);
            graph[y].push_back(x);
       }
       scanf("%d%d",&s,&d);
       memset(distance1,0,sizeof(distance1));
       memset(distance2,0,sizeof(distance2));
       BFS(graph,s,distance1);
       BFS(graph,d,distance2);

       int ans = 0;
       for(i=0; i<n; i++){
            ans = max(ans,distance1[i]+distance2[i]);
       }

       printf("Case %d: %d\n",q++,ans);

    }
    return 0;
}
