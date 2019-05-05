#include <stdio.h>
int main()
{
    int n,x,a,z=0,i,j;
    scanf("%d", &n);
    for(i = 1;i <= n;i++){
        scanf("%d", &x);
        for(j = 0;j < x;j++){
            scanf("%d", &a);
                if(a>z)z = a;
            }

        printf("Case %d: %d\n", i,z);
        z = 0;
    }

    return 0;
}
