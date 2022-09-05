#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout() for(auto x:arr)cout<<x<<' ';
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)
#define vi vector<int>

int n;
int arr[505],parr[505];
int dp[505][505];
int rec(int l,int r)
  {//pruning

   //base case
   if(l>=r)
    return 0;
   //cache check
   if(dp[l][r]!=-1)
    return dp[l][r];
   //transition
   int ans=1e9;
   rep(mid,l,r)
    {int X=(parr[mid]-(l>0?parr[l-1]:0))%100;
     int Y=(parr[r]-parr[mid])%100;

     ans=min(X*Y+rec(l,mid)+rec(mid+1,r),ans);
    }
   //save and return
   return dp[l][r]=ans;
  }

void solve()
  {cin>>n;
   arrin(n,arr);
   parr[0]=arr[0];
   rep(i,1,n)
    parr[i]=arr[i]+parr[i-1];
   memset(dp,-1,sizeof(dp));
   cout<<rec(0,n-1)<<'\n';
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

//  int _t;cin>>_t;while(_t--)
 solve();
}