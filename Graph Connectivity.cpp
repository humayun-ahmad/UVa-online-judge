
#include <bits/stdc++.h>
using namespace std;
vector <int>vec[600];
int visit[500];

void BFS(int n)
{
    queue <int> q+;

    q.push(n);
    visit[n]=1;

    while(!q.empty()){
        int v = q.front();
        int siz = vec[n].size();
        q.pop();
            for(int i=1;i<=siz;i++){
                int u = vec[v][i];
                if(visit[u]==0){
                    visit[u]=1;
                    q.push(u);
                }
            }
    }

}

int main()
{
    int tc,cnt=0,i;
    string c,ch;

    cin >> tc;

    while(tc--){

        cin >> c;
        cin.ignore();

        while(getline(cin,ch) && ch != ""){
            vec[ch[0]].push_back(ch[1]);
            vec[ch[1]].push_back(ch[0]);
        }
        memset(visit,0,500);
        for(i='A';i<=c[0];i++){
            if(visit[i]==0){
                cnt++;
                BFS(i);
            }
        }

        cout << cnt <<endl;
        cout << endl;

        for(i='A';i<=c[0];i++){
            vec[i].clear();
        }
    }

    return 0;
}
