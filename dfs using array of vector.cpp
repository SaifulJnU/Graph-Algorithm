#include<bits/stdc++.h>
using namespace std;
/* Input:
5 4
1 2
1 3
4 3
5 3

then
1
*/
vector<int> arr[1000000];
int vis[10000];

void dfs(int s)
{
    vis[s]=1;
    cout<<"->"<<s;
    for(int i=0;i<arr[s].size();i++)
    {
        int child=arr[s][i];
        if(vis[child]==0)
        {
            dfs(child);  ///recursion
        }
    }
}


int main()
{
    int v,e;
    cin>>v;
    cin>>e;
    int n1,n2;
    for(int i=1;i<=e;i++)
    cin>>n1>>n2, arr[n1].push_back(n2),arr[n2].push_back(n1);

///adjacency list output mane graph ta arki
    for(int i=1;i<=v;i++)
    {
        cout<<"node "<<i <<" is connected " ;
        for(auto x : arr[i])
        {
            cout<<"->"<<x;
        }
        cout<<endl;
    }

    ///koi theke traverse suru korbe seta
    int start;
    cin>>start;
    dfs(start);///dfs call

    return 0;
}
