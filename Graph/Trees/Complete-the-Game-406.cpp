#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout(arr) for(auto x:arr)cout<<x<<' ';
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)
#define vi vector<int>

int n,m;
vector<vi> edge,backedge;
vi indeg,dp;

void solve()
  {cin>>n>>m;
   edge.resize(n+1);
   dp.assign(n+1,0);
   backedge.resize(n+1);
   indeg.assign(n+1,0);
   rep(i,0,m)
    {int a,b;
     cin>>a>>b;
     edge[a].push_back(b);
     backedge[b].push_back(a);
     indeg[b]++;
    }

   queue<int> q;
   rep(i,1,n+1)
    if(indeg[i]==0)
      q.push(i);
   dp[q.front()]=1;

   while(!q.empty())
    {int node=q.front();
     q.pop();

     for(auto neigh:edge[node])
      {indeg[neigh]--;
       if(indeg[neigh]==0)
        q.push(neigh);
      }

     for(auto prev:backedge[node])
      dp[node]=(dp[node]+dp[prev])%1000000007;
    }

   cout<<dp[n];
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 //int _t;cin>>_t;while(_t--)
 solve();
}