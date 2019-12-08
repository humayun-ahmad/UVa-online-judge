#include <bits/stdc++.h>
using namespace std;
int delimeter;
int checker=0;

struct Point
{
  int x,y;
};

Point p0;

Point nextToTop(stack<Point> &s)
{
    Point p = s.top();
    s.pop();
    Point res = s.top();
    s.push(p);
    return res;
}
//int Swap(Point &p1, Point &p2)
//{
//    Point temp = p1;
//    p1 = p2;
//    p2 = temp;
//}

int distSq(Point p1, Point p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}

int right_turn(Point p, Point q, Point r)
{
    int val = (q.y -p.y)*(r.x-q.x) - (r.y - q.y)*(q.x - p.x);
    if(val == 0) return 0;
    if(val>0) return 1;
    else return 2;

}

int compare(const void *vp1, const void *vp2)
{
    Point *p1 = (Point *)vp1;
    Point *p2 = (Point *)vp2;

    int o = right_turn(p0, *p1, *p2);
    if(o == 0){
        return (distSq(p0,*p2) >= distSq(p0, *p1)? -1 : 1);
    }
    return (o == 2)? -1 : 1;
}

void convexHull(Point points[],int n)
{
    int ymin = points[0].y, MIN = 0;
    for(int i = 1; i < n; i++){
        int y = points[i].y;
        if((y < ymin) || (ymin == y && points[i].x < points[MIN].x)){
            ymin = points[i].y;
            MIN = i;
        }
    }

//    Swap(points[0],points[MIN]);

    Point temp;
    temp = points[0];
    points[0] = points[MIN];
    points[MIN] = temp;

//    cout << "Check:" <<endl;
//    for(int i = 0;i < n; i++){
//        cout << points[i].x <<" "<<points[i].y<<endl;
//    }

    p0 = points[0];
    qsort(&points[1],n-1,sizeof(Point),compare);
    int m = 1;
    for(int i = 1; i < n; i++){
        while(i < n - 1 && right_turn(p0,points[i],points[i+1]) == 0){
            i++;
        }

        points[m] = points[i];

        m++;
    }

    if(m < 3) return;

//        for(int i = 0;i < n; i++){
//        cout << points[i].x <<" "<<points[i].y<<endl;
//    }
    stack<Point> s;

    s.push(points[0]);
    s.push(points[1]);
    s.push(points[2]);

//    for(int i = 0;i < n; i++){
//        cout << points[i].x <<" "<<points[i].y<<endl;
//    }

    for(int i = 3; i < m; i++){
        while(right_turn(nextToTop(s), s.top(),points[i]) != 2){
//            cout << "TEST" <<endl;
//        cout << s.top().x <<endl;
            s.pop();
        }
        s.push(points[i]);

    }
//    cout <<"Output: "<<endl;
    if(checker > 0){
        cout << "-1" <<endl;
        checker++;
    }
    else{
        checker++;
    }
//    for(int i = 0;i < n; i++){
//        cout << points[i].x <<" "<<points[i].y<<endl;
//    }
//    Point rem = s.top();
    cout << s.size() + 1 <<endl;

    stack<Point>out;

    while(!s.empty()){
        Point p = s.top();
      //  cout << p.x << " " <<p.y <<endl;
      out.push(p);
        s.pop();
    }
    //cout << rem.x << " " << rem.y <<endl;
    Point rem = out.top();
    while(!out.empty()){
        Point p = out.top();
        cout << p.x << " " <<p.y <<endl;
//      out.push(p);
        out.pop();
    }
    cout << rem.x << " " << rem.y <<endl;
}


int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    Point points[516];

    int n,tc,t=0,tt;
    cin >> tc;
    int tr = tc;
    cout << tc <<endl;
    while(tc--){
        cin >> n;

        for(int i = 0;i < n; i++){
            cin >> points[i].x >> points[i].y;
        }
        if(t<tr-1){
            t++;
            cin >> tt;
        }

//        for(int i = 0;i < n; i++){
//            cout << points[i].x <<" "<<points[i].y<<endl;
//        }
        convexHull(points,n);
    }
    return 0;
}

