#include<bits/stdc++.h>
using namespace std;
const long long MOD=1e9 + 7;
vector<long long> tree[100005];
bool vis[100005];
long long con,res=0,n,k;
long long modexp(long long a,long long b,long long mod)
{
    long long pw=1;
    a%=mod;
    while(b)
    {
        if(b&1)
        {
            pw=(pw*a)%mod;
        }
        b/=2;
        a=((a%mod)*(a%mod))%mod;
    }
    return pw;
}
void dfs(long long u)
{
    if(!vis[u])
    {
        con++;
        vis[u]=true;
        for(long long i=0;i<tree[u].size();i++)
        {
            dfs(tree[u][i]);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    for(long long i=0;i<n-1;i++)
    {
        long long u,v,w;
        cin>>u>>v>>w;
        if(w==0)
        {
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
    }
    res=modexp(n,k,MOD);
        for(long long i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                con=0;
                dfs(i);
                res=(res+MOD - modexp(con,k,MOD))%MOD;
            }
        }
        cout<<res<<endl;

}
