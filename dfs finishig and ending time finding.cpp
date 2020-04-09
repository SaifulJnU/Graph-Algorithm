#include<bits/stdc++.h>
using namespace std;

/*input
7 7
0 1
0 2
1 2
1 3
1 4
3 4
5 6
*/

#define WHITE 1
#define GRAY 2
#define BLACK 3
//#define time 1
int Time=1;
int sTime[100];///starting time er jonno array
int fTime[100]; ///ending time er jonno array
int adj[100][100];
int color[100];
int node,edge;

int dfsvisit(int x)
{
    color[x]=GRAY; ///eikhane surute color gray korlam karon white kono node pabar por ekhane asce...tai prothom kaj color change kora
    sTime[x]= Time; ///jokhon color gray tar mane just node tate aslam prothombar er jonno tai akhon hobe starting time
    ++Time;    /// ak node theke onno node e time er updating er jonno

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
    color[x]=BLACK;/// sob sese color ta black korlam mane oi node theke ar kothao jaoya jabe na tai

    fTime[x]=Time;/// jonkhon color black tar mane oi node tar shakha proshakha soho traverse ses tai se node ta theke ar next kono node e jaoya jai na.
                  ///tai back tracking wise finishing time ta hobe .
    ++Time;        /// ak node theke onno node e time er updating er jonno.

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
    cout<<"DFS Traverse : ";
    dfs();  ///dfs call korlam ......ekhane kono value diya call dilam na karon dfs e jekhan theke e start kori na keno traverse er man same thakbe.
    cout<<endl;
    //cout<<"       "<<"sT"<<" " <<"fT"<<endl;
    //cout<<"----------------"<<endl;

    ///to print starting time and ending time
    for(int i=0; i<node; i++)
    {
        cout<<"Node " <<(char)('A'+i)<<" "<<sTime[i]<<" "<<fTime[i]<<endl; /// taking character to represents different node that's it.
    }

    return 0;
}

