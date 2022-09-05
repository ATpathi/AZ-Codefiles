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
   
   rep(i,0,k-1)
    {while(!q.empty() && arr[q.back()]<=arr[i])
      q.pop_back();

     q.push_back(i);
    }

   rep(i,k-1,n)
    {if(i-q.front()+1>k)
      q.pop_front();

     while(!q.empty() && arr[q.back()]<=arr[i])
      q.pop_back();

     q.push_back(i);

     cout<<arr[q.front()]<<" ";
    }

   cout<<"\n";
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}