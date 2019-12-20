#include<bits/stdc++.h>
using namespace std;
int graph[101][101];
bool visited[101];
int n,cost,g;

void DFS(int v,int e){
    for(int i=1; i<=n; i++){
        if(!visited[i] && (graph[v][i] || graph[i][v])){
            if(graph[i][v]) cost += graph[i][v];
            visited[i] = true;
            g = i;
            DFS(i,e);
            break;
        }
    }
}

int main()
{
    int t,i,j,x,y,w,q=1,mx,total_cost;

    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=1; i<=n; i++){
            for(j=1; j<=n; j++){
                graph[i][j] = 0;
            }
            visited[i] = false;
        }
        total_cost = 0;
        for(i=0; i<n; i++){
            scanf("%d%d%d",&x,&y,&w);
            graph[x][y] = w;
            total_cost += w;
        }
        cost = 0;
        visited[x] = true;
        DFS(x,y);
        if(graph[x][g]) cost += graph[x][g];
        printf("Case %d: %d\n",q++,min(cost,total_cost-cost));
    }

    return 0;
}
