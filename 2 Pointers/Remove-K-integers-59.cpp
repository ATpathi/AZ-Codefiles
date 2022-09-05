#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout() for(auto x:arr)cout<<x<<' ';
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)

void solve()
  {int n,k;
   cin>>n>>k;
   int arr[n],diff[n-1];
   deque<int> q;
   arrin(n,arr)

   rep(i,1,n)
    diff[i-1]=arr[i]-arr[i-1];

   int window=n-k-1,ans=2e9;   
   rep(i,0,n-1)
    {while(!q.empty() && i-q.front()+1>window)
      q.pop_front();

     while(!q.empty() && diff[i]>=diff[q.back()])
      q.pop_back();

     q.push_back(i);

     if(i+1>=window)
      ans=min(ans,diff[q.front()]);
    }

   cout<<ans<<'\n';
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}