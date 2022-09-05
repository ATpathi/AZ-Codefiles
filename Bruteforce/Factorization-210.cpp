#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
  {ll n;
   cin>>n;
   set<ll> s;

   for(ll i=1;i*i<=n;i++)
    {if(n%i==0)
      {s.insert(i);
        if(i*i!=n)
          s.insert(n/i);
      }
    }

    for(auto i:s)
      cout<<i<<" ";
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 //int _t;cin>>_t;while(_t--)
 solve();
}