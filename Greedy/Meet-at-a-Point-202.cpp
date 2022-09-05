#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout(arr) for(auto x:arr)cout<<x<<' ';
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)
#define vi vector<int>

void solve()
  {int n,medx,medy;
   cin>>n;
   vi x,y;
   rep(i,0,n)
    {int ax,ay;
     cin>>ax>>ay;
     x.push_back(ax);y.push_back(ay);
    }
  
   sort(x.begin(),x.end());
   sort(y.begin(),y.end());

   int i=(n-1)/2;
   medx=x[i];medy=y[i];
   
   ll ans=0;
   rep(i,0,n)
    ans+=abs(x[i]-medx)+abs(y[i]-medy);

   cout<<ans<<'\n';
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}