#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout() for(auto x:arr)cout<<x<<' ';
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)
#define vi vector<int>
int MOD=1e9+7;

int binary_exp(int a,int p)
    {int ans=1;
     while(p)
         {if(p%2)
              ans=(1LL*ans*a)%MOD;
          a=(1LL*a*a)%MOD;
          p/=2;
         }
     return ans;
    }
/*All the inline functions are written with the assumption that the arguments
passed will in the range [0,MOD-1]*/
/*An inline function must preferably be written with void return type as
otherwise the compiler might ignore it*/
inline void add(int &a,int b)
    {a+=b;
     if(a>=MOD)
         a-=MOD;
    }
inline void sub(int &a,int b)
    {a-=b;
     if(a<0)
         a+=MOD;
    }
inline void mul(int &a,int b)
    {a=(int)((1LL*a*b)%MOD);
    }
inline void divi(int &a,int b)
    {a=(int)((1LL*a*(binary_exp(b,MOD-2)))%MOD);
    }
// const int N=1e6+1;
// int facto[N];
// void factorial()
//     {facto[0]=1;
//      for(int i=1;i<=N;i++)
//         {int ans=facto[i-1];
//          mul(ans,i);
//          facto[i]=ans;
//         }
//     }


int n,m;
int arr[1010][1010];
ll dp[1010][1010];
//dp returns the maximum sum path from (x,y) to (n-1,m-1)
ll rec(int x,int y)
    {//pruning
     if(x>=n || y>=m)
        return -1e18;
     //base case
     if(x==n-1 && y==m-1)
        return arr[n-1][m-1];
     //cache check
     if(dp[x][y]!=-1)
        return dp[x][y];
     //transition
     ll ans=arr[x][y];
     if(x!=n-1)
        ans=max(ans,ans+rec(x+1,y));
     if(y!=m-1)
        ans=max(ans,arr[x][y]+rec(x,y+1));
     //save and return
     return dp[x][y]=ans;
    }
void solve()
    {cin>>n>>m;
     rep(i,0,n)
        rep(j,0,m)
            {cin>>arr[i][j];
             dp[i][j]=-1;
            }
     cout<<rec(0,0)<<'\n';
    }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}