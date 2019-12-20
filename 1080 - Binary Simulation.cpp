#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define max_index 100005
using namespace std;


struct info{long long prop,sum;}tre[max_index*4];
void Lazy_Propagation_Update(int node, int start, int en, int q_start, int q_end, long long data){
    if(q_start>en || q_end<start){
        return;
    }
    if(q_start<=start && q_end >=en){
        tre[node].sum += ((en-start+1)*data);
        tre[node].prop += data;
        return ;
    }
    int left  = (node*2);
    int right = (node*2)+1;
    int mid   = (start+en)/2;
    Lazy_Propagation_Update(left,start,mid,q_start,q_end,data);
    Lazy_Propagation_Update(right,mid+1,en,q_start,q_end,data);
    tre[node].sum = tre[left].sum + tre[right].sum + (en-start+1)*tre[node].prop;
}


int Lazy_Propagation_Query(int node, int start, int en, int q_start, int q_end,int carry = 0){
    if(q_start>en || q_end<start){
        return 0;
    }
    if(q_start<=start && q_end>=en){
        return tre[node].sum + carry*(en-start+1);
    }
    int left  = (node*2);
    int right = (node*2)+1;
    int mid   = (start+en)/2;

    int p1 = Lazy_Propagation_Query(left,start,mid,q_start,q_end,carry+tre[node].prop);
    int p2 = Lazy_Propagation_Query(right,mid+1,en,q_start,q_end,carry+tre[node].prop);
    return p1+p2;
}

int main()
{
    int q,t,x,y,n,i,query,data=1;
    //freopen("output2.txt","w",stdout);
    scanf("%d",&q);
    t=1;
    while(q--){
        char arr[max_index];
        scanf("%s",arr);
        int l = strlen(arr);
        scanf("%d",&query);

        printf("Case %d:\n",t++);
        memset(tre,0,sizeof(tre));
        while(query--){
            char c[5];
            scanf("%s",c);

            if(c[0]=='I'){
                scanf("%d%d",&x,&y);
                Lazy_Propagation_Update(1,1,l,x,y,data);
            }
            else{
                scanf("%d",&x);
                printf("%d\n",(arr[x-1] + Lazy_Propagation_Query(1,1,l,x,x))%2);

            }
        }
    }
    return 0;
}

