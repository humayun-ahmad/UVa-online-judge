#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int n,i,j,sum=0,x,temp,sum1=0,l,k,cnt=0;
    char str[100];

    scanf("%d %s", &n,str);
    if(atoi(str)==1){
        printf("1\n1\n1\n");
        return 0;
    }

    for( i=0; str[i]!='\0'; i++){

        x = str[i] - '0';
        sum += x;
        if(i<n-1) {
                printf("%d+",x);
                cnt=1;
        }
        else {
                printf("%d\n",x);
                cnt=1;
        }
    }
    while(sum>0 && cnt<=3){
         temp=sum%10;
         sum1 = temp;
         sum /= 10;
         if(sum!=0){
            printf("%d+", temp);
         }
         else{
            printf("%d\n", temp);
         }
         if(sum==0){
                cnt++;
            sum = temp;
         }


    }


    return 0;
}
