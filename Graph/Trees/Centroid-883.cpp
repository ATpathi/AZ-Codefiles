#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout(arr) for(auto x:arr)cout<<x<<' ';
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)
#define vi vector<int>

int n;
vector<vi> g;
vi subsize,par;

void dfs(int node,int parent)
  {par[node]=parent;
   subsize[node]=1;

   for(auto neigh:g[node])
    {if(neigh!=parent)
      {dfs(neigh,node);
       subsize[node]+=subsize[neigh];
      }
    }
  }

int findCentroid(int node,int parent)
  {dfs(node,parent);
   int ans=node;

   for(auto neigh:g[node])
    if(subsize[neigh]>n/2)
      ans=findCentroid(neigh,node);
   
   return ans;
  }

void solve()
  {cin>>n;
   g.resize(n+1);
   subsize.resize(n+1);
   par.resize(n+1);
   rep(i,0,n-1)
    {int a,b;
     cin>>a>>b;
     g[a].push_back(b);
     g[b].push_back(a);
    }
   
   cout<<findCentroid(1,0);
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 //int _t;cin>>_t;while(_t--)
 solve();
}