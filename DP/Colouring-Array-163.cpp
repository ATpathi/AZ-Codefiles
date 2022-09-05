#include<bits/stdc++.h>
using namespace std;
#define int long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout() for(auto x:arr)cout<<x<<' ';
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)
#define vi vector<int>
int n,m,k_fin;
int arr[105];
int ptc[105][105];
int dp[110][110];

int rec(int level,int k)
  {//pruning
   if(k<0 || level>n)
    return 2e18;
   if(k>0 && level==n)
    return 2e18;
   //base case
   if(k==0 && level==n)
    return 0;
   //cache check
   if(dp[level][k]!=-1)
    return dp[level][k];
   //transition
   int ans=2e18;
   if(arr[level]>0)
    {if(arr[level]==arr[level-1])
      ans=min(rec(level+1,k),ans);
     else
      ans=min(rec(level+1,k-1),ans);
    }
   else
    {rep(i,0,m)
      {if(arr[level-1]==i)
        {arr[level]=i;
         ans=min(ans,rec(level+1,k)+ptc[level][i]);
         arr[level]=0;
        }
       else
        {arr[level]=i;
         ans=min(ans,rec(level+1,k-1)+ptc[level][i]);
         arr[level]=0;
        }
      }
    }
   //save and return
   return dp[level][k]=ans;
  }
void solve()
  {cin>>n>>m>>k_fin;
   rep(i,0,n)
    cin>>arr[i];
   for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      cin>>ptc[i][j];

   memset(dp,-1,sizeof(dp));

   if(rec(0,k_fin)!=2e18)
    cout<<rec(0,k_fin)<<'\n';
   else 
    cout<<-1<<'\n';
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}