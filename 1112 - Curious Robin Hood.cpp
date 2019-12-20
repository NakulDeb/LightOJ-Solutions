#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define max_index 100005
using namespace std;
int tree[max_index*4];
int arr[max_index];
void segment_tree_init(int node, int start, int end){
    if(start == end){
        tree[node] = arr[start];
        return ;
    }
    int left  = node*2;
    int right = (node*2) + 1;
    int mid   = (start+end)/2;
    segment_tree_init(left,start,mid);
    segment_tree_init(right,mid+1,end);
    tree[node] = tree[left] + tree[right];
}

int segment_tree_query(int node, int start, int end, int q_start, int q_end){
    if(q_start>end || q_end<start){
        return 0;
    }
    if(q_start<=start && q_end>=end){
        return tree[node];
    }
    int left  = (node*2);
    int right = (node*2)+1;
    int mid   = (start+end)/2;
    int q1 = segment_tree_query(left,start,mid,q_start,q_end);
    int q2 = segment_tree_query(right,mid+1,end,q_start,q_end);
    return q1+q2;

}

void segment_tree_update(int node, int start, int end, int index, int new_value){
    if(index<start || index>end){
        return ;
    }
    if(index <=start && index >= end){
        tree[node] += new_value;
        return ;
    }
    int left  = (node*2);
    int right = (node*2)+1;
    int mid   = (start+end)/2;
    segment_tree_update(left,start,mid,index,new_value);
    segment_tree_update(right,mid+1,end,index,new_value);
    tree[node] = tree[left] + tree[right];
}

void segment_tree_update_set_0(int node, int start, int end, int index, int new_value){
    if(index<start || index>end){
        return ;
    }
    if(index <=start && index >= end){
        tree[node] = new_value;
        return ;
    }
    int left  = (node*2);
    int right = (node*2)+1;
    int mid   = (start+end)/2;
    segment_tree_update_set_0(left,start,mid,index,new_value);
    segment_tree_update_set_0(right,mid+1,end,index,new_value);
    tree[node] = tree[left] + tree[right];
}


int main()
{
    int q,t,x,y,n,m,i,j,query,data=1,d;
    //freopen("output2.txt","w",stdout);
    scanf("%d",&q);
    t=1;
    while(q--){
        scanf("%d%d",&n,&query);
        for(i=1; i<=n; i++){
            scanf("%d",&arr[i]);
        }
        segment_tree_init(1,1,n);


        printf("Case %d:\n",t++);
        while(query--){
            scanf("%d",&d);

            if(d==1){
                scanf("%d",&x);
                x++;
                printf("%d\n",segment_tree_query(1,1,n,x,x));
                segment_tree_update_set_0(1,1,n,x,0);

            }
            else if(d==2){
                scanf("%d%d",&x,&y);
                x++;
                segment_tree_update(1,1,n,x,y);

            }
            else{
                scanf("%d%d",&x,&y);
                x++;
                y++;
                printf("%d\n",segment_tree_query(1,1,n,x,y));
            }
        }
    }
    return 0;
}
