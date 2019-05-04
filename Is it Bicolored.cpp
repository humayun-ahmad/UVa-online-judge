#include <bits/stdc++.h>
using namespace std;

vector <int>vec[250];


int bfs(int s)
{
    int i;
    int color[250]={0};
    int visit[250]={0};

    queue <int> q;
    q.push(s);
    color[s] = 1;
    while(!q.empty()){
        int a = q.front();
        q.pop();
       int d = color[a]==1?2:1;
       int l= vec[a].size();
        for(i=0;i<l;i++){
                 s = vec[a][i];
            if(color[a]==color[s]){
                return 0;
            }
            if(!visit[s]){
                q.push(s);
                color[s] = d;
                visit[s]=1;
            }
        }
    }
    return 1;
}

int main()
{
    int n,a,b,x,i,cnt=0;

    while(scanf("%d", &n) != EOF && n){
    scanf("%d", &x);
    for(i=0;i<x;i++){
        scanf("%d %d", &a, &b);
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    if(bfs(0)) printf("BICOLORABLE.\n");
    else printf("NOT BICOLORABLE.\n");

    for(i=0;i<n;i++) vec[i].clear();
    }

    return 0;
}
