#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout() for(auto x:arr)cout<<x<<' ';
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)

void solve()
  {int n,X;
   cin>>n>>X;
   int arr[n];
   arrin(n,arr)

   vector<int> v1,v2;

   rep(i,0,n)
    if(i%2)
      v1.push_back(arr[i]);
    else
      v2.push_back(arr[i]);

   vector<ll> sub1,sub2;
   rep(mask,0,1<<(int)v1.size())
    {ll sum=0;
     rep(i,0,(int)v1.size())
      {if(mask&(1<<i))
        sum+=v1[i];
      }
     sub1.push_back(sum);
    }
   rep(mask,0,1<<(int)v2.size())
    {ll sum=0;
     rep(i,0,(int)v2.size())
      {if(mask&(1<<i))
        sum+=v2[i];
      }
     sub2.push_back(sum);
    }

   ll ans=0;
   sort(sub2.begin(),sub2.end());
   for(auto x:sub1)
    {auto it=upper_bound(sub2.begin(),sub2.end(),X-x);
     ans+=it-sub2.begin();
    }
   
   cout<<ans<<'\n';
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}