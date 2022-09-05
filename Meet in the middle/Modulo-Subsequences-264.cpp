#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout() for(auto x:arr)cout<<x<<' ';
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)
#define vi vector<int>

void solve()
  {int n,m;
   cin>>n>>m;
   int arr[n];
   arrin(n,arr)

   vi v[2];
   rep(i,0,n)
    v[i%2].push_back(arr[i]);

   vector<ll> sums[2];
   rep(mask,0,1<<(int)v[0].size())
    {ll sum=0;
     rep(j,0,(int)v[0].size())
      if(mask&(1<<j))
        sum+=v[0][j];

     sum%=m;
     sums[0].push_back(sum);
    }
   rep(mask,0,1<<(int)v[1].size())
    {ll sum=0;
     rep(j,0,(int)v[1].size())
      if(mask&(1<<j))
        sum+=v[1][j];

     sum%=m;
     sums[1].push_back(sum);
    }

   sort(sums[1].begin(),sums[1].end());

   int ans=0;
   rep(i,0,(int)sums[0].size())
    {auto it=upper_bound(sums[1].begin(),sums[1].end(),m-sums[0][i]);
     if(it!=sums[0].begin()) 
      it--;
     auto it1=upper_bound(sums[1].begin(),sums[1].end(),2*m-sums[0][i]);
     if(it1!=sums[0].begin()) 
      it1--;
         
     int a1=(sums[0][i]+*it)%m;
     int a2=(sums[0][i]+*it1)%m;
     int am=max(a1,a2);

     ans=max(ans,am);
    }

   cout<<ans;
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 //int _t;cin>>_t;while(_t--)
 solve();
}