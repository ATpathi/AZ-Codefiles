#include<bits/stdc++.h>
using namespace std;

void solve()
  {int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++)
    cin>>a[i];
   int gcd=a[0];
   for(int i=1;i<n;i++)
    {gcd=__gcd(gcd,a[i]);
     if(gcd==1)
      break;
    }
   if(gcd==1)
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