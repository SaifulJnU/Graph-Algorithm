#include<bits/stdc++.h>
using namespace std;

#define WHITE 1
#define GRAY 2
#define BLACK 3

int adj[100][100];
int color[100];
int node,edge;

int dfsvisit(int x)
{
    color[x]=GRAY; ///eikhane surute color gray korlam karon white kono node pabar por ekhane asce...tai prothom kaj color change kora

    for(int i=0; i<node; i++)
    {
        if(adj[x][i]==1)    ///eikhane neighbor node khujalam
        {
            if(color[i]==WHITE) ///eikhane node sudu neighbor hole hobe na atar color white o hote hobe jodi white hoy tobe dfsvisit call korbo
            {
                dfsvisit(i);   ///recursive call ..... it works like back tracking
            }
        }
    }
    color[x]=BLACK;  /// sob sese color ta black korlam mane oi node theke ar kothao jaoya jabe na tai
    cout<<x<<" ";  /// x mane node er man print korlam je node tar kaj ses. mane shakha proshaka sob visit hoye gece.
}

void dfs()   ///dfs function
{
    for(int i=0; i<node; i++)
    {
        color[i]=WHITE;     ///prothome sob gula node er man white korlam
    }
    for(int i=0; i<node; i++)
    {
        if(color[i]== WHITE)   ///je node er man white pabo setate dfsvisit call korlam jar kaj hobe asepaser node gula traverse kora
        {
            dfsvisit(i);
        }
    }
}


int main()
{
    cin>>node>>edge;
    int n1,n2;
    for(int i=0; i<edge; i++)
    {
        cin>>n1>>n2;        ///normally graph er node gular connection build korlam
        adj[n1][n2]=1;
        adj[n2][n1]=1;
    }
    cout<<"DFS traverse : ";
    dfs();   ///dfs call korlam ......ekhane kono value diya call dilam na karon dfs e jekhan theke e start kori na keno traverse er man same thakbe.
    return 0;
}
