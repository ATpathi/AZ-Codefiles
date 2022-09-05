#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout(arr) for(auto x:arr)cout<<x<<' ';
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)
#define vi vector<int>

int n,m;
vector<vi> g;
vi vis;
bool cycle;

void dfs(int start)
  {vis[start]=1;
   
   for(auto neigh:g[start])
    {if(vis[neigh]==0)
      dfs(neigh);
     else if(vis[neigh]==1)
      cycle=1;
    }

   vis[start]=2;
  }

void solve()
  {cin>>n>>m;
   g.clear();
   g.resize(n+1);
   vis.assign(n+1,0);
   rep(i,0,m)
    {int n1,n2;
     cin>>n1>>n2;
     g[n1].push_back(n2);
    }
   cycle=0;
   rep(i,1,n+1)
    if(vis[i]==0)
      dfs(i);

   if(cycle)
    cout<<"Yes\n";
   else
    cout<<"No\n";
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}