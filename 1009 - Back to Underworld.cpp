#include<bits/stdc++.h>
#define max_index 20001
using namespace std;

vector<int>graph[max_index];
int visited[max_index];
int WHITE=0,VAMPIRE = 1, LYKAN = 2;
int vam,lykan;

void BFS(int x){
    queue<int>q;
    q.push(x);
    vam++;
    visited[x] = VAMPIRE;

    while(!q.empty()){
        x = q.front();
        q.pop();

        for(int i=0; i<graph[x].size(); i++){
            if(visited[graph[x][i]]==WHITE){
                if(visited[x]==VAMPIRE){
                    lykan++;
                    visited[graph[x][i]] = LYKAN;
                }
                else{
                    vam++;
                    visited[graph[x][i]] = VAMPIRE;
                }
                q.push(graph[x][i]);
            }
        }
    }

}


int main()
{
    int t,i,q=1,n,m,u,v,x,y,index,sum;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&t);

    while(t--){
        scanf("%d",&n);
        index = 0;
        memset(visited,WHITE,sizeof(visited));
        for(i=0; i<max_index; i++) graph[i].clear();

        map<int,int>mp;
        for(i=1; i<=n; i++){
            scanf("%d%d",&u,&v);
            graph[u].push_back(v);
            graph[v].push_back(u);
            mp[u] = 1;
            mp[v] = 1;
            index = max(index,max(u,v));
        }

        sum=0;
        for(i=1; i<=index; i++){
            if(visited[i]==WHITE && mp[i]){
                vam=lykan=0;
                BFS(i);
                sum += max(vam,lykan);
            }
        }
        printf("Case %d: %d\n",q++,sum);
    }
}
