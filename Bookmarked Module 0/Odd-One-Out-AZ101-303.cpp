#include<bits/stdc++.h>
using namespace std;

void solve()
    {int n,m,xorr;
     cin>>n;
     cin>>xorr;
     n-=1;
     while(n--)
        {cin>>m;
         xorr=xorr^m;
        }
     cout<<xorr<<'\n';
    }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();

}