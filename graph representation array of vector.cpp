#include<bits/stdc++.h>
using namespace std;
vector<int>arr[1000000]
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
    

    return 0;
}