#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define Hare printf("here\n")
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define on(val,pos) val|(1<<pos)
#define off(val,pos) val&(~(1<<pos))
#define check(val,pos) (val&(1<<pos))

using namespace std;
int dp[6][7490];
//int arr[] = {0,1,5,10,25,50};
int arr[6];

void call()
{
    dp[0][0] = 1;

    for(int i = 1; i <= 5; i++){
        for(int j = 0; j <= 7489; j++){
            if(arr[i] > j) dp[i][j] = dp[i-1][j];
            else {
                dp[i][j] = dp[i-1][j] + dp[i][j-arr[i]];
            }
        }
    }
}
int main()
{

    arr[1] = 1;
    arr[2] = 5;
    arr[3] = 10;
    arr[4] = 25;
    arr[5] = 50;

    call();

    int n;
    while(scanf("%d", &n) != EOF){
        cout << dp[5][n] <<endl;
    }

    return 0;
}

