#include<bits/stdc++.h>
using namespace std;
#define int long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout() for(auto x:arr)cout<<x<<' ';
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)
#define vi vector<int>

void solve()
   {int n;
    cin>>n;
    int c[n];
    string s[n],rev[n];
    rep(i,0,n)
      cin>>c[i];

    rep(i,0,n)
      {cin>>s[i];
       rev[i]=s[i];
       reverse(rev[i].begin(),rev[i].end());
      }

    int dp[n][2];
    dp[0][1]=c[0];
    dp[0][0]=0;

    rep(i,1,n)
      {dp[i][1]=dp[i][0]=1e18;
       
       if(s[i]>=s[i-1])
         dp[i][0]=min(dp[i-1][0],dp[i][0]);
       if(s[i]>=rev[i-1])
         dp[i][0]=min(dp[i-1][1],dp[i][0]);
       if(rev[i]>=s[i-1])
         dp[i][1]=min(dp[i][1],dp[i-1][0]+c[i]);
       if(rev[i]>=rev[i-1])
         dp[i][1]=min(dp[i][1],dp[i-1][1]+c[i]);
      }

    int ans=min(dp[n-1][0],dp[n-1][1]);

    if(ans==1e18)
      cout<<-1<<'\n';
    else
      cout<<ans<<'\n';
   }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}