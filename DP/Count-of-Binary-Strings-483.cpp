#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout(arr) for(auto x:arr)cout<<x<<' ';
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
int dp[1000100][5][2];

void init_dp()
  {memset(dp,0,sizeof(dp));

   rep(level,0,1e6+1)
    {rep(cur,0,5)
      {rep(occ,0,2)
        {if(level==0)
          {if((occ==1 || cur==4))
            dp[level][cur][occ]=1;
           else
            dp[level][cur][occ]=0;
          }

         else
          {int ans=0;
           if(occ==0)
            {if(cur==0)
              {add(ans,dp[level-1][0][0]);
               add(ans,dp[level-1][1][0]);
              }
             else if(cur==1)
              {add(ans,dp[level-1][0][0]);
               add(ans,dp[level-1][2][0]);
              }
             else if(cur==2)
              {add(ans,dp[level-1][2][0]);
               add(ans,dp[level-1][3][0]);
              }
             else if(cur==3)
              {add(ans,dp[level-1][0][0]);
               add(ans,dp[level-1][4][1]);
              }
             else if(cur==4)
              {add(ans,dp[level-1][2][1]);
               add(ans,dp[level-1][0][1]);
              }
            }
           else
            {if(cur==0)
              {add(ans,dp[level-1][0][1]);
               add(ans,dp[level-1][1][1]);
              } 
             else if(cur==1)
              {add(ans,dp[level-1][0][1]);
               add(ans,dp[level-1][2][1]);
              }
             else if(cur==2)
              {add(ans,dp[level-1][2][1]);
               add(ans,dp[level-1][3][1]);
              }
             else if(cur==3)
              {add(ans,dp[level-1][0][1]);
               add(ans,dp[level-1][4][1]);
              }
             else if(cur==4)
              {add(ans,dp[level-1][2][1]);
               add(ans,dp[level-1][0][1]);
              }
            }
           dp[level][cur][occ]=ans;
          }
        }
      }
    }
  }

void solve()
  {int n;
   cin>>n;
  
   int anso=binary_exp(2,n);
   sub(anso,dp[n][0][0]);
   cout<<anso<<'\n';
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);
 init_dp();
 int _t;cin>>_t;while(_t--)
 solve();
}