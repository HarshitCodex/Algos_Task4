    #include<bits/stdc++.h>
    using namespace std;
    const int N=1001;
    const int K=6;
    int pos[K][N];
    int arr[K][N];
    int dp[N];
    int main()
    {
    	int n,k;
    	fill_n(dp,N,0);
    	cin>>n>>k;
    	for(int i=1;i<=k;i++)
    	{
    		for(int j=1;j<=n;j++)
    		{
    			cin>>arr[i][j];
    			pos[i][arr[i][j]]=j;
    		}
    	}
    	int ans=0;
    	for(int j=1;j<=n;j++)
    	{
    		int maxx=0;

    		for(int l=1;l<j;l++)
    		{

    			int i=0;
    			for(i=2;i<=k && pos[i][arr[1][l]]<pos[i][arr[1][j]];i++);
    			if(i==k+1 && dp[l]>maxx)
    				maxx=dp[l];

    		}
    		maxx+=1;
    		dp[j]=maxx;
    		ans=max(ans,dp[j]);
    	}
    	cout<<ans;
    	return 0;
    }
