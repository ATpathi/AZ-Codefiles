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

int n,m,k;
int dp[2050][2050];

int rec(int level,int kleft)
    {//pruning

     //base case check
     if(kleft==0 && level<=n)
        return 1;
     else if(kleft>0 && level==n)
        return 0;
     //cache check
     if(dp[level][kleft]!=-1)
        return dp[level][kleft];
     //transition
     int ans=0;

     add(ans,rec(level+1,kleft));
     if(kleft>0)
        {int temp=m-1;
         mul(temp,rec(level+1,kleft-1));
         add(ans,temp);
        }
     //save and return
     return dp[level][kleft]=ans;
    }

void solve()
    {cin>>n>>m>>k;
     memset(dp,-1,sizeof(dp));
     int ans=m;
     mul(ans,rec(1,k));
     cout<<ans<<'\n';
    }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}