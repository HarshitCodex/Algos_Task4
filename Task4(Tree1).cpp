#include<bits/stdc++.h>
using namespace std;
vector<int> adj[200005],subt,ss;
int f[200005], dp[200005];
void dfs(int u,int p)
{
    dp[u]=1;
    ss.push_back(u);
    for(auto v: adj[u])
    {
        if(v!=p)
        {
            dfs(v,u);
            dp[u]+=dp[v];
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    for(int i=2;i<=n;i++)
    {
        int u;
        cin>>u;
        adj[u].push_back(i);
        adj[i].push_back(u);
    }
    dfs(1,0);
    int i=0;
    for(auto v :ss)
    {
        f[v]=i;
        i++;
    }
    while(q--)
    {

        int v,k;
        cin>>v>>k;
        int id=f[v]+k-1;
        if(dp[v]<k)
            cout<<-1<<endl;
        else
            cout<<ss[id]<<endl;
    }
}
