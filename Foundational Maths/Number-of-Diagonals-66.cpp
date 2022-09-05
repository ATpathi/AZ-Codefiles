#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;

int binary_exp(int a,int p)
  {int ans=1;
   while(p)
    {if(p%2)
      ans=(1LL*ans*a)%mod;
     p/=2;
     a=(1LL*a*a)%mod;
    }
   return ans;
  }
void solve()
  {int n,ans;
   cin>>n;
   ans=(1LL*((1LL*n*(n-3))%mod)*binary_exp(2,mod-2))%mod;
   cout<<ans<<"\n";
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}