#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout(arr) for(auto x:arr)cout<<x<<' ';
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)
#define vi vector<int>

int n,m,ans=0;
vector<vi> g;
vi col,par;

bool dfs(int i,int npar)
  {col[i]=1;
   for(auto neigh:g[i])
    {if(neigh!=npar)
      {if(col[neigh]==0)
        {par[neigh]=i;
         if (dfs(neigh,i))
          return 1;
        }
       else if(col[neigh]==1)
        return 1;
      }
    }
   col[i]=2;
   return 0;
  }
  
void solve()
  {cin>>n>>m;
   g.resize(n+1);
   col.assign(n+1,0);
   par.assign(n+1,-1);
   rep(i,0,m)
    {int c1,c2;
     cin>>c1>>c2;
     g[c1].push_back(c2);
     g[c2].push_back(c1);
    }

   
   rep(i,0,n)
    if(col[i]==0 && dfs(i,par[i]))
      {ans=1;
       break;
      }

   if(ans)
    cout<<"YES\n";
   else 
    cout<<"NO\n";
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 //int _t;cin>>_t;while(_t--)
 solve();
}