#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout() for(auto x:arr)cout<<x<<' ';
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)
#define vi vector<int>

void solve()
  {int n,m;
   cin>>n>>m;
   bool grid[n][m];
   rep(i,0,n)
    rep(j,0,m)
      cin>>grid[i][j];

   int dp[n+1][m+1],max_side=0;
   memset(dp,0,sizeof(dp));
   
   rep(i,1,n+1)
    rep(j,1,m+1)
      {if(grid[i-1][j-1])
        dp[i][j]=1+min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]});
       else
        dp[i][j]=0;

       max_side=max(max_side,dp[i][j]);
      }

   cout<<max_side*max_side<<'\n';
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}