    #include<bits/stdc++.h>
    using namespace std;

    int main()
    {
        int n,m;
        long long res=0;
        cin>>n>>m;
        int v[n];
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            res+=min(v[x-1],v[y-1]);
        }
        cout<<res<<endl;
        return 0;
    }
