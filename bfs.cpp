#include<bits/stdc++.h>
using namespace std;
/**#define white 1
#define gray 2
#define black 3 */
int parent[100], dis[100], color[100];
vector <int> v[100];

void bfs(int start)
{
    parent[start]=-1;
    dis[start]=0;
    queue <int> q;
    q.push(start);

    while(!q.empty()){

        int x = q.front();
        cout << x << " ";
        q.pop();
        color[x]=1;
        for(int i=0; i<v[x].size(); i++){
            int child = v[x][i];
            if(color[child] ==0){
                q.push(child);
                parent[child]=x;
                dis[child] = 1+dis[x];
                color[child]=1;
            }
        }
    }
}

int main()
{
    int edge;
    cin >> edge;
    for(int i=0,n1,n2; i<edge; i++) cin >> n1 >> n2, v[n1].push_back(n2), v[n2].push_back(n1);
    bfs(1);
    puts("\n\n\n");
    cout << parent[6];
    return 0;
}
