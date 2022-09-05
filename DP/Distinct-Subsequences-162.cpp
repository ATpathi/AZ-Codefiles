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

void solve()
  {string s;
   int n;
   cin>>s;
   n=s.length();
   map<int,int> mp,mpa;
   rep(i,0,26)
    mp[i]=0;
   int count=0;
   rep(i,0,n)
    {if(mp[s[i]-'A']==0)
      {mpa[s[i]-'A']=count;
       
       mp[s[i]-'A']=1;
       add(mp[s[i]-'A'],count);
       add(count,mp[s[i]-'A']);
      }
     else
      {mp[s[i]-'A']=count;
       sub(mp[s[i]-'A'],mpa[s[i]-'A']);
       mpa[s[i]-'A']=count;
       add(count,mp[s[i]-'A']);
      }
    }
   cout<<(count+1)%MOD<<'\n';
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}