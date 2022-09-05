#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout(arr) for(auto x:arr)cout<<x<<' ';
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)
#define vi vector<int>

void solve()
  {int n;
   cin>>n;
   ll ans=0;
   vi arr1(n),arr2(n);
   arrin(n,arr1)
   arrin(n,arr2)
   sort(arr1.begin(),arr1.end());
   sort(arr2.begin(),arr2.end());
   rep(i,0,n)
    ans+=abs(arr1[i]-arr2[i]);

   cout<<ans<<'\n';
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}