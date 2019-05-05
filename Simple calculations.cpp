#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc,n;
    double a,b,x;

    cin >> tc;

    while(tc--){
        cin >> n;

        cin >> a;
        cin >> b;
        double sum=0;
        while(n--){
                cin >> x;
            sum = (a+b)/2 - x;
        }

        cout << sum <<endl;


    }

    return 0;
}
