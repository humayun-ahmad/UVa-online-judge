/***
Name: Humayun Ahmad Rajib
Roll: 18010276140
10:56 PM
Monday, December 9, 2019 (GMT+6)
Time in Rcc (Motihar)
**/


#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI acos(-1)
#define Hare printf("here\n")
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define on(val,pos) val|(1<<pos)
#define off(val,pos) val&(~(1<<pos))
#define check(val,pos) (val&(1<<pos))
#define MX 100010
using namespace std;
int sz,n;

struct Point
{
  ll x,y;
};

Point p0;
Point stk[MX];
stack<Point> s;
Point points[MX];

//int Swap(Point &p1, Point &p2)
//{
//    Point temp = p1;
//    p1 = p2;
//    p2 = temp;
//}

ll distSq(Point p1, Point p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}

double solve(Point A, Point B, Point C)
{
    double a = sqrt((double)distSq(A,B));
    double b = sqrt((double)distSq(B,C));
    double c = sqrt((double)distSq(C,A));

    return acos((b*b-c*c-a*a)/(-2*a*c));

}

int right_turn(Point p, Point q, Point r)
{
    ll val = (q.y -p.y)*(r.x-q.x) - (r.y - q.y)*(q.x - p.x);
    if(val < 0) return 2;
    if(val > 0) return 1;
    else return val;

}

int compare(Point x, Point y)
{
    int ret = right_turn(points[0], x,y);
    if(ret == 0){
        ll dist1 = distSq(points[0], x);
        ll dist2 = distSq(points[0], y);
        return dist1 < dist2;
    }
    else if(ret == 2) return true;
    else
        return false;
}

Point nextToTop()
{
    Point p = s.top();
    s.pop();
    Point res = s.top();
    s.push(p);
    return res;
}

double convexHull(int n)
{
    int ymn = points[0].y, idx = 0;
    for(int i = 0; i < n ;i++){
        if(points[i].y < ymn || (points[i].y ==ymn && points[i].x < points[idx].x)){
            ymn = points[i].y;
            idx = i;
        }
    }

    swap(points[0], points[idx]);

    sort(&points[1], &points[n],compare);

    s.push(points[0]);

    for(int i = 1; i < n; i++){
        while(s.size() > 1 && right_turn(nextToTop(), s.top(), points[i]) != 2 ) s.pop();
        s.push(points[i]);
    }

    vector<Point> v;

    while(!s.empty()){
        v.push_back(s.top());
        s.pop();
    }

    if((int)v.size() < 3) return 0.0;
    reverse(v.begin(),v.end());

    double ret = 1258.0;
    int cnt = (int)v.size();

    for(int i = 0; i < cnt; i++){
        int j = (i+1)%cnt;
        int k = (i-1 + cnt)%cnt;
        ret = min(ret,(solve(v[i],v[j], v[k])*180)/PI);
    }
    return ret;

//        for(int i = 0; i < s.size(); i++){
//        cout << v[i].x << " " << v[i].y <<endl;
//    }



}

int main()
{
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);

    int tc,n,t=0;

    cin >> tc;

    while(tc--){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> points[i].x >> points[i].y;
        }

        printf("Case %d: %.6lf\n", ++t,convexHull(n));
    }

    return 0;
}
