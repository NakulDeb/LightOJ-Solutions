#include<bits/stdc++.h>
#define M 15
using namespace std;
int n,m;
char graph[M][M];
bool visited[M][M];
int level[M][M];
int ii,jj;

bool BFS(char c, int x, int y){
    queue<pair<int,int> >q;
    for(int i=0; i<M; i++) memset(visited[i],false,sizeof(visited[i]));

    q.push({x,y});
    graph[x][y] = '.';
    level[x][y] = 0;
    visited[x][y] = true;


    while(!q.empty()){
        auto v = q.front();
        q.pop();

        if(!visited[v.first-1][v.second] &&v.first && graph[v.first-1][v.second]=='.'){
            visited[v.first-1][v.second] = true;
            level[v.first-1][v.second] = level[v.first][v.second]+1;
            q.push({v.first-1,v.second});
        }
        if(!visited[v.first+1][v.second] && v.first<n-1 && graph[v.first+1][v.second]=='.'){
            visited[v.first+1][v.second] = true;
            level[v.first+1][v.second] = level[v.first][v.second]+1;
            q.push({v.first+1,v.second});
        }
        if(!visited[v.first][v.second-1] && v.second && graph[v.first][v.second-1]=='.'){
            visited[v.first][v.second-1] = true;
            level[v.first][v.second-1] = level[v.first][v.second]+1;
            q.push({v.first,v.second-1});
        }
        if(!visited[v.first][v.second+1] && v.second<n-1 && graph[v.first][v.second+1]=='.'){
            visited[v.first][v.second+1] = true;
            level[v.first][v.second+1] = level[v.first][v.second]+1;
            q.push({v.first,v.second+1});
        }

        ///matching part

        if(v.first && graph[v.first-1][v.second]==char(c+1)){
            level[v.first-1][v.second] = level[v.first][v.second]+1;
            ii = v.first-1;
            jj = v.second;
            return 0;
        }
         if(v.first<n-1 && graph[v.first+1][v.second]==char(c+1)){
            level[v.first+1][v.second] = level[v.first][v.second]+1;
            ii = v.first+1;
            jj = v.second;
            return 0;
        }
         if(v.second && graph[v.first][v.second-1]==char(c+1)){
            level[v.first][v.second-1] = level[v.first][v.second]+1;
            ii = v.first;
            jj = v.second-1;
            return 0;
        }
         if(v.second<n-1 && graph[v.first][v.second+1]==char(c+1)){
            level[v.first][v.second+1] = level[v.first][v.second]+1;
            ii = v.first;
            jj = v.second+1;
            return 0;
        }

    }
    return 1;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t,q=1,i,j,x,y;
    char c;

    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        set<char>s;
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                scanf(" %c",&c);
                graph[i][j] = c;
                if(c<='Z' && c>='A'){
                    s.insert(c);
                }
            }
        }
        int ans = 0;
        printf("Case %d: ",q++);
        for(auto it=s.begin(); it!=--s.end(); it++){
            for(i=0; i<n; i++){
                for(j=0; j<n; j++){
                    if(graph[i][j]==(*it)){
                        if(BFS(graph[i][j],i,j)){
                            printf("Impossible\n");
                            goto L1;
                        };
                        ans += level[ii][jj];
                    }
                }
            }
        }
        printf("%d\n",ans);
        L1:i;
    }
    return 0;
}
