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
vi dep,par;

void dfs(int node,int parent,int depth)
  {par[node]=parent;
   dep[node]=depth;

   for(auto neigh:g[node])
    {if(neigh!=parent)  
      dfs(neigh,node,depth+1);
    }
  }

void solve()
  {cin>>n;
   g.resize(n+1);
   dep.resize(n+1);
   par.resize(n+1);
   rep(i,0,n-1)
    {int a,b;
     cin>>a>>b;
     g[a].push_back(b);
     g[b].push_back(a);
    }

   int maxn=1;
   dfs(1,0,0);
   rep(i,1,n+1)
    if(dep[maxn]<dep[i])
      maxn=i;

   dfs(maxn,0,0);
   rep(i,1,n+1)
    if(dep[maxn]<dep[i])
      maxn=i;

   if(dep[maxn]%2)
    cout<<-1;
   else
    {int i=maxn;
     while(dep[i]>dep[maxn]/2)
      i=par[i];

     cout<<i;
    }
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 //int _t;cin>>_t;while(_t--)
 solve();
}