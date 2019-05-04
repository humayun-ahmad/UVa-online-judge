#include <bits/stdc++.h>
using namespace std;
int visit[50005];
vector<int>vec[50005];

void BFS(int a)
{
    queue<int>q;


    q.push(a);
    visit[a]=1;

    while(!q.empty()){
        int v = q.front();
        int siz = vec[v].size();

        q.pop();

        for(int i=0;i<siz;i++){
            int u = vec[v][i];

            if(visit[u]==0){
                visit[u]=1;
                q.push(u);
            }
        }

    }
    //return st;
}


int main()
{
    int n,m,a,b,t=0;
    //cin >> n >> m;

    while(1){
            memset(visit,0,sizeof(visit));
            memset(vec,0,sizeof(vec));
            cin >> n >> m;
    if(n==0 && m==0) break;
        for(int i=0;i<m;i++){
            cin >> a >> b;
            vec[a].push_back(b);
            vec[b].push_back(a);
        }



        int cn=0;
        for(int i=1;i<=n;i++){
            if(visit[i]==0){
                cn++;
                BFS(i);
            }
        }

        printf("Case %d: %d\n", ++t,cn);


    }


    return 0;
}
