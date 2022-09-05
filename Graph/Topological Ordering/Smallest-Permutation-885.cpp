#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout(arr) for(auto x:arr)cout<<x<<' ';
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)
#define vi vector<int>

int n,m;
vi indeg;
vector<vi> g;
vi ans;

void kahn()
  {priority_queue<int> pq;
   rep(i,1,n+1)
    if(indeg[i]==0)
      pq.push(-i);

   while(!pq.empty())
    {int node=-pq.top();
     pq.pop();
     
     for(auto neigh:g[node])
      {indeg[neigh]--;
       if(indeg[neigh]==0)
        pq.push(-neigh);
      }

     ans.push_back(node);
    }
  }

void solve()
  {cin>>n>>m;
   g.resize(n+1);
   indeg.assign(n+1,0);
   rep(i,0,m)
    {int n1,n2;cin>>n1>>n2;
     g[n1].push_back(n2);
     indeg[n2]++;
    }
   
   kahn();

   if(ans.size()!=n)
    cout<<-1<<'\n';
   else
    {for(auto i:ans)
      cout<<i<<" ";
     cout<<'\n';
    }
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 //int _t;cin>>_t;while(_t--)
 solve();
}