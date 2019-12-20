#include<bits/stdc++.h>
#define M 30003
#define ll long long
using namespace std;

int n,k,mx;
vector<vector<pair<int,int> > >graph;
bool visited[M];
int level[M];

void  DFS(int x, int ans){
    level[x] = ans;
    if(mx<ans){
        mx = ans;
        k = x;
    }
    for(int i=0; i<graph[x].size(); i++){
        int v = graph[x][i].first;
        int w = graph[x][i].second;
        if(!visited[v]){
            visited[v] = true;
            DFS(v,ans+w);
        }
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t,i,x,y,w,q=1;

    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        vector<vector<pair<int,int> > >v(n+1);
        swap(graph,v);
        memset(visited,false,sizeof(visited));

        for(i=1; i<n; i++){
            scanf("%d%d%d",&x,&y,&w);
            graph[x].push_back({y,w});
            graph[y].push_back({x,w});

        }
        mx = 0;
        visited[0] = true;
        DFS(0,0);

        mx = 0;
        memset(visited,false,sizeof(visited));
        visited[k] = true;
        DFS(k,0);

        int dis1[M];
        for(i=0; i<n; i++) dis1[i] = level[i];

        mx = 0;
        memset(visited,false,sizeof(visited));
        visited[k] = true;
        DFS(k,0);

        printf("Case %d:\n",q++);
        for(i=0; i<n; i++){
            printf("%d\n",max(dis1[i],level[i]));
        }
    }
    return 0;
}
