#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define ull unsigned long long
using namespace std;

int tree[400005];
int arr[100005];
int inf = 100000000;

int segment_tree_init(int node, int start, int en){
    if(start == en){
        tree[node] = arr[start];
        return arr[start];
    }
    int left  = node*2;
    int right = (node*2) + 1;
    int mid   = (start+en)/2;
    int q1 = segment_tree_init(left,start,mid);
    int q2 = segment_tree_init(right,mid+1,en);
    tree[node] = min(tree[left] , tree[right]);
    return tree[node];
}

int segment_tree_query(int node, int start, int en, int q_start, int q_end){
    if(q_start>en || q_end<start){
        return inf;
    }
    if(q_start<=start && q_end>=en){
        return tree[node];
    }
    int left  = (node*2);
    int right = (node*2)+1;
    int mid   = (start+en)/2;
    int q1 = segment_tree_query(left,start,mid,q_start,q_end);
    int q2 = segment_tree_query(right,mid+1,en,q_start,q_end);
    return min(q1,q2);

}
int main()
{
   // ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,query,i,j,q_start,q_end,y,data,q;
    //ofstream cout("output_1082.txt");
    //freopen("output_1082.txt","w",stdout);
    scanf("%d",&q);
    j=1;
    while(q--){
        //getchar();
        scanf("%d%d",&n,&query);
        for(i=1; i<=n; i++){
            scanf("%d",&arr[i]);
        }
        segment_tree_init(1,1,n);
        printf("Case %d:\n",j);
        j++;
        while(query--){
            scanf("%d%d",&q_start,&q_end);
            if(q_start>q_end) swap(q_start,q_end);
            printf("%d\n",segment_tree_query(1,1,n,q_start,q_end));
        }
    }

    return 0;
}

