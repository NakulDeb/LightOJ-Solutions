#include<bits/stdc++.h>

int main()
{
    int t,q=1;
    scanf("%d",&t);

    while(t--){
        int x1,y1,x2,y2,x,y,n;
        scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&n);
        printf("Case %d:\n",q++);
        while(n--){
            scanf("%d%d",&x,&y);
            if(x>x1&&x<x2&&y>y1&&y<y2) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
