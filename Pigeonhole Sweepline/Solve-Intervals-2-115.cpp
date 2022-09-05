#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout() for(auto x:arr)cout<<x<<' ';
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)
#define vi vector<int>

void solve()
  {int n;
   ll L;
   cin>>n>>L;
   map<ll,int> mp;
   rep(i,0,n)
    {ll l,r;
     cin>>l>>r;
     mp[l]++;mp[r]--;
    }
   
   mp[-1]=0;
   int sub=1e6,temp=0;
   for(auto m:mp)
    {m.second+=temp;
     if(m.first!=L && m.first!=-1)
      sub=min(sub,m.second);

     temp=m.second;
    } 

   int ans=n+1-sub;
   cout<<ans;
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 //int _t;cin>>_t;while(_t--)
 solve();
}