#include <stdio.h>

int main()
{
    int n,i,m,x,y,z;
    scanf("%d", &n);
    for(i=1;i<=n;i++){
        scanf("%d%d%d", &x, &y, &z);
        if(x==y && x==z){
        m = x;
       }

       else if(y>x&&y<z){
            m=y;
        }

        else if(x>y&&x<z){
            m=x;
        }
       else if(y>z&&y<x){
        m=y;
       }
       else if(z>x&&z<y){
        m=z;
       }
       else if(z>y&&z<x){
        m=z;
       }
       else if(x>z && x<y){
        m=x;
       }

        printf("Case %d: %d\n", i,m);
    }
    return 0;
}
