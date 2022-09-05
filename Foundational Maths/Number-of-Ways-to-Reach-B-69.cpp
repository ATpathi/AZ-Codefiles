#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
int facto[200001];

int binary_exp(int a,int p)
  {int ans=1;
   while(p)
    {if(p%2)
      ans=(1LL*ans*a)%MOD;
     p/=2;
     a=(1LL*a*a)%MOD;
    }
   return ans;
  }

void solve()
  {int n,m;
   cin>>n>>m;
   cout<<(1LL*facto[n+m]*binary_exp(((1LL*facto[n]*facto[m])%MOD),MOD-2)%MOD)<<"\n";
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 facto[0]=1;
 for(int i=1;i<=200000;i++)
  facto[i]=(1LL*i*facto[i-1])%MOD;

 int _t;cin>>_t;while(_t--)
 solve();
}