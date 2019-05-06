#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;

    while(1){
        cin >> n;
        if(n==0) break;
        int rem,sum=0;
        while(1){
            rem = n%3;
            sum = sum + n/3;
            n = rem + n / 3;
            if(n==2 || n==1 || n==0) break;
        }
        if(n == 2) sum += 1;
        cout << sum <<endl;
    }
    return 0;
}
