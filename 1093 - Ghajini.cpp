#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define PI 2*acos(0.0)
#define max_index 100005
using namespace std;

int tree_max[max_index*4];
int tree_min[max_index*4];
int arr[max_index];

void segment_tree_init_max(int node, int start, int end){
    if(start==end){
        tree_max[node] = arr[start];
        return ;
    }
    int left  = (node*2);
    int right = (node*2)+1;
    int mid   = (start+end)/2;
    segment_tree_init_max(left,start,mid);
    segment_tree_init_max(right,mid+1,end);
    tree_max[node] = max(tree_max[left],tree_max[right]);
}

int segment_tree_query_find_max(int node,int start, int end, int x, int y){
    if(x>end || y<start)   return INT_MIN;
    if(x<=start && y>=end) return tree_max[node];
    int left  = (node*2);
    int right = (node*2)+1;
    int mid   = (start+end)/2;
    int q1 = segment_tree_query_find_max(left,start,mid,x,y);
    int q2 = segment_tree_query_find_max(right,mid+1,end,x,y);
    return max(q1,q2);
}

void segment_tree_init_min(int node, int start, int end){
    if(start==end){
        tree_min[node] = arr[start];
        return ;
    }
    int left  = (node*2);
    int right = (node*2)+1;
    int mid   = (start+end)/2;
    segment_tree_init_min(left,start,mid);
    segment_tree_init_min(right,mid+1,end);
    tree_min[node] = min(tree_min[left],tree_min[right]);
}

int segment_tree_query_find_min(int node,int start, int end, int x, int y){
    if(x>end || y<start)   return INT_MAX;
    if(x<=start && y>=end) return tree_min[node];
    int left  = (node*2);
    int right = (node*2)+1;
    int mid   = (start+end)/2;
    int q1 = segment_tree_query_find_min(left,start,mid,x,y);
    int q2 = segment_tree_query_find_min(right,mid+1,end,x,y);
    return min(q1,q2);
}


int main()
{
    int q,t,x,n,d,i,j,mx,mn,ans;
    //freopen("output2.txt","w",stdout);
    scanf("%d",&q);
    t=1;
    while(q--){
        int time = 0;
        scanf("%d%d",&n,&d);
        for(i=1; i<=n; i++) scanf("%d",&arr[i]);

        segment_tree_init_max(1,1,n);
        segment_tree_init_min(1,1,n);
        ans = 0;
        for(i=1; i<=n-d+1; i++){
            ans = max(ans,segment_tree_query_find_max(1,1,n,i,i+d-1) - segment_tree_query_find_min(1,1,n,i,i+d-1));
        }
        printf("Case %d: %d\n",t++,ans);
    }
    return 0;
}
