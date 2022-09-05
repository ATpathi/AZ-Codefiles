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

string s;
int dp[1010][1010],len;

int rec(int level,int op_br)
  {//pruning
   if(op_br>len-level)
    return 0;
   if(op_br<0 || len-level<0)
    return 0;
   //base case 
   if(op_br==0 && level==len)
    return 1;
   //cache check
   if(dp[level][op_br]!=-1)
    return dp[level][op_br];
   //transition 
   int ans=0;
   if(s[level]=='(')
    add(ans,rec(level+1,op_br+1));
   else if(s[level]==')')
    add(ans,rec(level+1,op_br-1));
   else
    {add(ans,rec(level+1,op_br+1));
     add(ans,rec(level+1,op_br-1));
    }
   //save and return
   return dp[level][op_br]=ans;
  }

void solve()
  {cin>>s;
   len=s.length(); 
   rep(i,0,len+1)
    rep(j,0,len+1)
      dp[i][j]=-1;
   cout<<rec(0,0)<<'\n';
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}