#include<bits/stdc++.h>
using namespace std;
#define int long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout(arr) for(auto x:arr)cout<<x<<' ';
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)
#define vi vector<int>

void solve()
  {int X,Y,ans=0;
   cin>>X>>Y;
   while(X<Y)
    {if(Y%2)
      Y++;
     else
      Y/=2;
    
     ans++;
    }
   ans+=X-Y;
   cout<<ans<<'\n';
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}