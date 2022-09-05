#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout(arr) for(auto x:arr)cout<<x<<' ';
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)
#define vi vector<int>

int n,occ,dp;
bool cent2=0;
vector<vi> g;
vi dep,par;

void dfs(int node,int parent,int depth)
  {par[node]=parent;
   dep[node]=depth;
   if(cent2)
    {if(depth==dp/2)
      occ++;
    }
   else
    {if(depth==(dp/2)-1)
      occ++;
    }
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

   vi centres;
   dp=dep[maxn];
   int ans=1;

   if(dp%2)
    {int i=maxn;
     cent2=1;
     while(dep[i]>(dp/2)+1)
      i=par[i];
     int c1=i;
     int c2=par[i];

     occ=0;
     dfs(c1,c2,0);
     ans=occ;
     occ=0;
     dfs(c2,c1,0);
     ans*=occ;
    }
   else
    {int i=maxn,mult=0;
     while(dep[i]>dp/2)
      i=par[i];
     ans=0;occ=0;
     for(auto nc:g[i])
      {occ=0;
       
       dfs(nc,i,0);
      //  cout<<occ<<" ";
       ans+=mult*occ;
       mult+=occ;
      }
    }

   cout<<ans<<'\n';
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 //int _t;cin>>_t;while(_t--)
 solve();
}