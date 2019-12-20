#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define max_index 100005
using namespace std;

struct info{long long prop,sum;}tree[max_index*4];
void Lazy_Propagation_Update(ll node, ll s, ll e, ll i, ll j, ll data){
    if(j<s || i>e){
        return ;
    }
    if(i<=s&&j>=e){
        tree[node].sum += (e-s+1)*data;
        tree[node].prop += data;
        return;
    }
    ll left  = (node*2);
    ll right = (node*2)+1;
    ll mid   = (s+e)/2;
    Lazy_Propagation_Update(left,s,mid,i,j,data);
    Lazy_Propagation_Update(right,mid+1,e,i,j,data);
    tree[node].sum = tree[left].sum + tree[right].sum + (e-s+1)*tree[node].prop;
}

ll Lazy_Propagation_Query(ll node, ll s, ll e, ll i, ll j, ll carry = 0){
    if(j<s || i>e){
        return 0;
    }
    if(i<=s&& j>=e){
        return tree[node].sum + carry * (e-s+1);
    }
    ll left  = (node*2);
    ll right = (node*2)+1;
    ll mid   = (e+s)/2;
    ll q1 = Lazy_Propagation_Query(left,s,mid,i,j,tree[node].prop+carry);
    ll q2 = Lazy_Propagation_Query(right,mid+1,e,i,j,tree[node].prop+carry);
    return q1+q2;
}


int main()
{
    ll q,t,x,y,n,m,i,j,query,data=1,d;
    //freopen("output2.txt","w",stdout);
    //freopen("input.txt","r",stdin);
    scanf("%lld",&q);
    t=1;
    while(q--){
        scanf("%lld%lld",&n,&query);
        memset(tree,0,sizeof(tree));

        printf("Case %lld:\n",t++);
        while(query--){
            scanf("%lld",&d);

            if(d==0){
                scanf("%lld%lld%lld",&x,&y,&data);
                Lazy_Propagation_Update(1,1,n,x+1,y+1,data);
            }
            else{
                scanf("%lld%lld",&x,&y);
                printf("%lld\n",Lazy_Propagation_Query(1,1,n,x+1,y+1));
            }
        }
    }
    return 0;
}
