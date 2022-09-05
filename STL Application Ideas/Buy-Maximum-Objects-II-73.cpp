#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
    {int n,q;
     cin>>n>>q;
     int a[n];
     for(int i=0;i<n;i++)
        cin>>a[i];
     sort(a,a+n);
    
     int pr[n];
     pr[0]=a[0];
     for(int i=1;i<n;i++)
        pr[i]=pr[i-1]+a[i];

     int m[q];
     for(int i=0;i<q;i++)
        cin>>m[i];
     
     for(int i=0;i<q;i++)
        {int ans=distance(pr,upper_bound(pr,pr+n,m[i]));
         cout<<ans<<'\n';
        }
    }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

//  int _t;cin>>_t;while(_t--)
 solve();
}