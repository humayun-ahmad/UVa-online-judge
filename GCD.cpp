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
    int n;
    while(1){
        cin >> n;
        if(n == 0) break;
        int G=0;
        for(int i = 1; i < n; i++)
        for(int j = i + 1;j <= n; j++)
        {
        G += gcd(i,j);
        }

        cout << G <<endl;

    }
    return 0;
}
