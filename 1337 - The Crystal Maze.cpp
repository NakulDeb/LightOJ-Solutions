#include<bits/stdc++.h>
using namespace std;
const int M = 501;
int n,m;
char graph[M][M];
bool visited[M][M];
int ans[M][M];


int BFS(int x, int y){
    int num = 0;
    if(graph[x][y]=='C') num++;
    visited[x][y] = true;
    queue<pair<int,int> >q;
    q.push({x,y});

    vector<pair<int,int> > flag;
    while(!q.empty()){
        auto w = q.front();
        q.pop();
        int u = w.first;
        int v = w.second;
        flag.push_back({u,v});

        if(u && !visited[u-1][v] && graph[u-1][v]!='#'){
            if(graph[u-1][v]=='C') num++;
            q.push({u-1,v});
            visited[u-1][v] = true;
        }
        if(u<n-1 && !visited[u+1][v] && graph[u+1][v]!='#'){
            if(graph[u+1][v]=='C') num++;
            q.push({u+1,v});
            visited[u+1][v] = true;
        }
        if(v && !visited[u][v-1] && graph[u][v-1]!='#'){
            if(graph[u][v-1]=='C') num++;
            q.push({u,v-1});
            visited[u][v-1] = true;
        }
        if(v<m-1 && !visited[u][v+1] && graph[u][v+1]!='#'){
            if(graph[u][v+1]=='C') num++;
            q.push({u,v+1});
            visited[u][v+1] = true;
        }
    }
    for(auto it=flag.begin(); it!=flag.end(); it++){
        ans[it->first][it->second] = num;
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int k=1,t,i,j,x,y,q;

    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&q);

        for(i=0; i<n; i++){
            scanf(" %s",graph[i]);
        }
        for(i=0; i<=n; i++){
            for(j=0; j<=m; j++){
                visited[i][j] = false;
            }
        }
        for(i=0; i<n; i++){
            for(j=0; j<m; j++){
                if(graph[i][j]!='#' && !visited[i][j]){
                    BFS(i,j);
                }
            }
        }
        printf("Case %d:\n",k++);

        while(q--){
            scanf("%d%d",&x,&y);
            printf("%d\n",ans[x-1][y-1]);
        }

    }
    return 0;
}
