#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout() for(auto x:arr)cout<<x<<' ';
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)
#define vi vector<int>

const int mod=1e8;
int k1,k2;
int dp[105][105][2];

int rec(int n1,int n2,bool f)
  {//pruning

   //base case check
   if(n1+n2==0)
    return 1;
   //cache check
   if(dp[n1][n2][f]!=-1)
    return dp[n1][n2][f];
   //transition
   int ans=0;
   if(f==0)
    {rep(i,1,min(n1,k1)+1)
      ans=(ans+rec(n1-i,n2,1-f))%mod;
    }
   else
    {rep(i,1,min(n2,k2)+1)
      ans=(ans+rec(n1,n2-i,1-f))%mod;
    }
   //save and return
   return dp[n1][n2][f]=ans;
  }

void solve()
  {int n1,n2;
   cin>>n1>>n2;
   cin>>k1>>k2;
   memset(dp,-1,sizeof(dp));
   cout<<(rec(n1,n2,0)+rec(n1,n2,1))%mod<<'\n';
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}