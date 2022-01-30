#include<bits/stdc++.h>
#include <math.h>
using namespace std;

int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,x;
	    cin>>n>>x;
	    long long int dp[n+1],i,j;
	    memset(dp,0,sizeof(dp));
	    dp[0]=1;
	    for(i=1;i<=n;i++)
	    {
	        for(j=n;j>=i;j--)
	        {
	            long long int y=pow(i,x);
	            if(j>=y)
	            {
	                dp[j]+=dp[j-y];
	            }
	        }
	    }
	    cout<<dp[n]<<endl;
	}
	return 0;
}