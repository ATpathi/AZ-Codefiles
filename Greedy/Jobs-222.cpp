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

   vector<pair<int,int>> jobs(n+1);
   rep(i,0,n)
    cin>>jobs[i].first;
   rep(i,0,n)
    cin>>jobs[i].second;
   jobs.push_back({0,0});

   sort(jobs.rbegin(),jobs.rend());

   priority_queue<int> minheap;
   minheap.push(-jobs[0].second);
   int ans=0;

   rep(i,1,n+1)
    {int interval=jobs[i-1].first-jobs[i].first;

     while(interval>0 && !minheap.empty())
      {int mintop=-minheap.top();
       minheap.pop();
       int sub=min(interval,mintop);
       mintop-=sub;
       interval-=sub;
       if(mintop)
        minheap.push(-mintop);
       else
        ans++;
      }
     
     minheap.push(-jobs[i].second);
    }

   cout<<ans<<'\n';
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}