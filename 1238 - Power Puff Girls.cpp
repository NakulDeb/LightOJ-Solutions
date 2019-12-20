#include<bits/stdc++.h>
#define max_index 25
using namespace std;
int n,m,num;
int graph[max_index][max_index];
bool visited[max_index][max_index];
int level[max_index][max_index];
struct girl{
    int row;
    int col;
};

void BFS(girl x){
    for(int i=0; i<max_index; i++) memset(visited[i],false,sizeof(visited[i]));
    queue<pair<int,int> >q;

    q.push({x.row,x.col});
    level[x.row][x.col] = 0;
    visited[x.row][x.col] = true;

    while(!q.empty()){
        auto s = q.front();
        q.pop();

        if(s.second>1&& !visited[s.first][s.second-1] && graph[s.first][s.second-1]){
            visited[s.first][s.second-1] = true;
            level[s.first][s.second-1] = level[s.first][s.second] +1;
            q.push({s.first,s.second-1});
        }
        if(s.second<n-2&& !visited[s.first][s.second+1] && graph[s.first][s.second+1]){
            visited[s.first][s.second+1] = true;
            level[s.first][s.second+1] = level[s.first][s.second] +1;
            q.push({s.first,s.second+1});
        }

        if(s.first>1&& !visited[s.first-1][s.second] && graph[s.first-1][s.second]){
            visited[s.first-1][s.second] = true;
            level[s.first-1][s.second] = level[s.first][s.second] +1;
            q.push({s.first-1,s.second});
        }
        if(s.first<m-2 && !visited[s.first+1][s.second] && graph[s.first+1][s.second]){
            visited[s.first+1][s.second] = true;
            level[s.first+1][s.second] = level[s.first][s.second] +1;
            q.push({s.first+1,s.second});
        }
    }
}


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int i,j,q=1,t;
    scanf("%d",&t);

    while(t--){
        scanf("%d%d",&m,&n);
        girl a,b,c,h;
        char ch;

        for(i=0; i<m; i++){
            for(j=0; j<n; j++){
                scanf(" %c",&ch);
                if(ch=='a')      {a.row = i; a.col = j;}
                else if(ch=='b') {b.row = i; b.col = j;}
                else if(ch=='c') {c.row = i; c.col = j;}
                else if(ch=='h') {h.row = i; h.col = j;}

                if(ch=='#' || ch=='m') graph[i][j] = 0;
                else                   graph[i][j] = 1;
            }
        }


        int mx = 0;
        BFS(h);
        mx = max(level[a.row][a.col],max(level[b.row][b.col],level[c.row][c.col]));

        printf("Case %d: %d\n",q++,mx);

    }
    return 0;
}
