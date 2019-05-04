#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,tc,arr[55],cnth=0,cntl=0;

    cin >> tc;

    for(int i=1;i<=tc;i++){
        cin >> n;

        for(int j=0;j<n;j++){
            cin >> arr[j];
        }

        for(int j=0;j<n-1;j++){
            if(arr[j]<arr[j+1]){
                cnth++;
            }
            else if(arr[j]>arr[j+1]){
                cntl++;
            }
        }

        printf("Case %d: %d %d\n",i,cnth,cntl);
        cnth=0;cntl=0;
    }

    return 0;
}
