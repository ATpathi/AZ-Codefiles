#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout(arr) for(auto x:arr)cout<<x<<' ';
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)
#define vi vector<int>
int n,arr[105];
int dp[105][105]; //dp(l,r) returns the min. seconds required to delete the arr[l:r]

int rec(int l,int r)
  {//pruning
   if(l>r)
    return 0;
   //base case
   if(l==r)
    return 1;
   //cache check
   if(dp[l][r]!=-1)
    return dp[l][r];
   //transition check
   int ans=1e9;
   rep(i,l,r+1)
    {if(arr[i]==arr[l] && i>l+1)
      ans=min(ans,rec(l+1,i-1)+(i<r?rec(i+1,r):0));
     if(i==l)
      ans=min(ans,rec(l+1,r)+1);
     if(i==l+1 && arr[l]==arr[i])
      ans=min(ans,rec(l+2,r)+1);
    }
   //save and return
   return dp[l][r]=ans;
  }
void solve()
  {cin>>n;
   arrin(n,arr)
   memset(dp,-1,sizeof(dp));

   cout<<rec(0,n-1)<<'\n';
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}