#include<bits/stdc++.h>
using namespace std;

void solve()
  {int a,b,c;
   cin>>a>>b>>c;
   if(c%__gcd(a,b))
    cout<<"No\n";
   else 
    cout<<"Yes\n";
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();

}