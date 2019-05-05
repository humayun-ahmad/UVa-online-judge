#include <bits/stdc++.h>
#define ll long long
using namespace std;
int t = 0;
void triangle(ll a, ll b, ll c);
int main()
{
    ll a,b,c,tc;
    cin >> tc;
    while(tc--){
        cin >> a >> b >> c;
        triangle(a,b,c);
    }
    return 0;
}

void triangle(ll a, ll b, ll c)
{
    cout << "Case " << ++t <<": ";
    if(a+b > c && b+c > a && a+c > b){
            if(a == b && b == c && a == c){
            cout << "Equilateral" <<endl;
        }
        else if((a == b && a != c) || (a == c && b!= a) || (b==c && a != b)){
            cout << "Isosceles" <<endl;
        }
        else{
            cout << "Scalene" <<endl;
        }
    }
    else
        cout <<"Invalid"<<endl;

}
