#include <bits/stdc++.h>
using namespace std;

struct cell
{
    int x,y;
    int dis;
    cell(){}
    cell(int x,int y,int dis) : x(x),y(y),dis(dis){}
};

bool isInside(int x,int y,int N)
{
    if(x>=1 && x <= N && y >= 1 && y <= N)
        return true;
    return false;
}

int minStepToReachTarget(int knightPos[], int targetPos[],int N)
{
    int dx[]= {-2,-1,1,2,-2,-1,1,2};
    int dy[]= {-1,-2,-2,-1,1,2,2,1};

    queue < cell > q;

    q.push(cell(knightPos[0],knightPos[1],0));

    cell t;

    int x,y;
    bool visit[N+1][N+1];

    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
        visit[i][j] = false;

    visit[knightPos[0]][knightPos[1]] =true;
    while(!q.empty())
    {
        t = q.front();
        q.pop();

        if(t.x == targetPos[0] && t.y == targetPos[1])
        return t.dis;

        for(int i=0;i<8;i++)
        {
            x = t.x + dx[i];
            y = t.y + dy[i];

            if(isInside(x,y,N) && !visit[x][y]){
                visit[x][y] = true;
                q.push(cell(x,y,t.dis+1));
            }
        }
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int N=8;
    int r1,r2,c1,c2;
    char a,b;
    while(cin >>a>>r1>>b>>r2){
     c1 = a - 'a' + 1;
     c2 = b - 'a' + 1;
    // cout << c1 << " " <<c2<< endl;
    int knightPos[] = {r1,c1};
    int targetPos[] = {r2,c2};
    printf("To get from %c%d to %c%d takes %d knight moves.\n",a,r1,b,r2,minStepToReachTarget(knightPos,targetPos,N));
    //cout <<"To get from" minStepToReachTarget(knightPos,targetPos,N)<<endl;
    }
    fclose (stdout);
    return 0;
}

