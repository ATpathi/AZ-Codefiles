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
   vector<pair<ll,ll>> V;
   rep(i,0,n)
    {ll l,r;
     cin>>l>>r;
     V.push_back({l,r});
    }
   
   map<ll,ll> mp;
   for(auto v:V)
    mp[v.first]=max(mp[v.first],v.second);

   ll ans=0,last=0,maxi=0;
   for(auto m:mp)
    {if(m.first==last)
      {maxi=max(m.second,maxi);
       last=maxi;
       ans++;
      }
     else if(m.first>last)
      {last=maxi;
       ans++;
      }
     maxi=max(m.second,maxi);
    }
   if(last<L)
    ans++;

   cout<<ans;
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 //int _t;cin>>_t;while(_t--)
 solve();
}