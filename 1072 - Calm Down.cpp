#include<stdio.h>
#include<math.h>

int main()
{
    int t,q=1;
    scanf("%d",&t);
    while(t--){
        float R,n;
        scanf("%f%f",&R,&n);
        R = R * sin((2*acos(0.0))/n);
        R /= (1 + sin((2*acos(0.0))/n));
        printf("Case %d: %.10f\n",q++,R);
    }
    return 0;
}
