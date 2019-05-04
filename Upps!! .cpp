#include <bits/stdc++.h>
using namespace std;
vector<int>vec[10000];
int level[10000];
int visit[10000];
int t=0;

int BFS(int a,int b)
{
    if(a==b) return 0;
    memset(level,0,sizeof(level));
    memset(visit,0,sizeof(visit));

    queue<int>q;
    q.push(a);
    level[a]=0;
    visit[a]=1;

    while(!q.empty()){
        int v = q.front();
        int siz = vec[v].size();
        q.pop();

        for(int i = 0; i < siz; i++){
            int u = vec[v][i];
			if (b==u) return level[v]+1;
            if(visit[u]==0){
                visit[u]=1;
                q.push(u);
                level[u] = level[v] + 1;
            }

           /* if(u==b){
                while(!q.empty()){
                    q.pop();
                }
                return level[u];
            }*/
        }
    }
	return 0;

}

int main()
{
    int nnn;

    while(scanf("%d",&nnn)!=EOF){
        int cnt=20,n,a;
        for(int i=1;i<20;i++){
		  if (i==1) n=nnn;
          else   scanf("%d", &n);
            for(int j=1;j<=n;j++){
                scanf("%d",&a);
                vec[i].push_back(a);
				vec[a].push_back(i);
            }
        }
        int tc,first,second;
        t++;
        printf("Test Set #%d\n",t);
        scanf("%d", &tc);
        for(int k=1;k<=tc;k++){
            scanf("%d %d",&first,&second);
            if(first>9 && second>9){
                printf("%d to %d: %d\n",first,second,BFS(first,second));
            }
            else if(first>9 && second<=9){
                printf("%d to  %d: %d\n",first,second,BFS(first,second));
            }
            else if(first<=9 && second>9){
                printf(" %d to %d: %d\n",first,second,BFS(first,second));
            }
            else{
                printf(" %d to  %d: %d\n", first,second,BFS(first,second));
            }
            //printf("%d to %d: %d\n",first,second,BFS(first,second));
        }
        printf("\n");
        memset(vec,0,sizeof(vec));
    }


    return 0;
}
