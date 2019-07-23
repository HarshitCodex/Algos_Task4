#include<bits/stdc++.h>
using namespace std;
const int over=INT_MIN/3600;
int n,m,k;
int lk[56][56];
vector<pair<int, pair<int , int> > > consize;
int dfs(int i,int j,int c) //finding connected component numbers
{
    if(i<0||i>n-1||j<0||j>m-1)
        return 0;
    if(!lk[i][j]||lk[i][j]==c)//for negatives/0/already existing lake
        return 0;
    if(i==0||i==n-1||j==0||j==m-1)
        return over;//so that answer becomes negative and rejected
    lk[i][j]=c;//marking as the number of the lake, also used as visited
    return 1+dfs(i+1,j,c)+dfs(i,j+1,c)+dfs(i-1,j,c)+dfs(i,j-1,c);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>k;
    memset(lk,0,sizeof(lk));
    int cnt=0;char c;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>c;
            if(c=='.')
                lk[i][j]=-1;//water mark
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(lk[i][j]==-1)
                consize.push_back(make_pair(dfs(i,j,++cnt),make_pair(i,j)));
        }
    }
    int res=0;
    sort(consize.begin(),consize.end());
    for(int i=0;i<cnt-k;i++)
    {
        if(consize[i].first>0)//here I checked the -ve cases
        {
            res+=consize[i].first;
            dfs(consize[i].second.first,consize[i].second.second,0);//this to mark the lake we are not keeping

        }
    }

    cout<<res<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(lk[i][j])
                cout<<".";
            else
                cout<<"*";
        }
        cout<<"\n";
    }
}
