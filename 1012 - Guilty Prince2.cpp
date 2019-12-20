#include<bits/stdc++.h>
#define max_index 20
using namespace std;
int n,m;
char graph[max_index][max_index];

int BFS(int x,int y){
    bool visited[max_index][max_index];
    queue<pair<int,int> >q;
    int count = 1;

    for(int i=0; i<max_index; i++){
        for(int j=0; j<max_index; j++){
            visited[i][j] = false;
        }
    }
    visited[x][y] = true;
    q.push(make_pair(x,y));

    while(!q.empty()){
        auto p = q.front();
        q.pop();

        for(int i= p.first; i<n; i++){
            if(graph[i][p.second]=='#') break;
            if(!visited[i][p.second]){
                q.push(make_pair(i,p.second));
                visited[i][p.second] = true;
                count++;
            }
        }
        for(int i= p.first; i>=0; i--){
            if(graph[i][p.second]=='#') break;
            if(!visited[i][p.second]){
                q.push(make_pair(i,p.second));
                visited[i][p.second] = true;
                count++;
            }
        }

        for(int i= p.second; i>=0; i--){
            if(graph[p.first][i]=='#') break;
            if(!visited[p.first][i]){
                q.push(make_pair(p.first,i));
                visited[p.first][i] = true;
                count++;
            }
        }
        for(int i= p.second; i<m; i++){
            if(graph[p.first][i]=='#') break;
            if(!visited[p.first][i]){
                q.push(make_pair(p.first,i));
                visited[p.first][i] = true;
                count++;
            }
        }


    }
    return count;
}


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t,i,j,x,y,que=1;
    char c;

    cin>>t;
    while(t--){
        cin>>m>>n;
        for(i=0; i<n; i++){
            for(j=0; j<m; j++){
                cin>>graph[i][j];
                if(graph[i][j]=='@'){ x=i;y=j;}
            }
        }
        printf("Case %d: %d\n",que++,BFS(x,y));
    }
}
