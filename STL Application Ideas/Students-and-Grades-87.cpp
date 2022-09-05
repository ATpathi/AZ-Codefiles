#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
void solve()
    {int n,m;
     cin>>n>>m;
     set<int> a;
     for(int i=0;i<n;i++)
      {int x;
       cin>>x;
       a.insert(x);
      }
     for(int i=0;i<m;i++)
      {int x;
       cin>>x;
       if(a.count(x))
        cout<<"YES\n";
       else
        cout<<"NO\n";
       a.insert(x);
      }
    }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}