#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if(b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int main()
{
    int arr[100010];
    int a,b;
    while(1){
        //int mn = 9999999;
        scanf("%d", &a);
        if(a==0) return 0;
        arr[0] = a;
        int i=1;
        while(1){
            scanf("%d", &arr[i]);
            if(arr[i]==0)
                break;
            i++;
        }
        int g=0;
        for(int j=1;j<i;j++){
            int dif = arr[j] - arr[j-1];
            g = gcd(max(g,dif),min(g,dif));
        }
        if(g<0) g = g*-1;
        cout << g <<endl;

    }
    return 0;
}
