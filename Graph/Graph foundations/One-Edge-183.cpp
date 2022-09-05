#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout(arr) for(auto x:arr)cout<<x<<' ';
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)
#define vi vector<int>

int n,m,comp_no=1;
vector<vi> g;
vi comp;
bool ans=0;

void dfs(int start)
  {if(comp[start]==-1)
    comp[start]=comp_no++;
  //  cout<<"node: "<<start<<" "<<"team: "<<team[start]<<" ";
   for(auto neigh:g[start])
    if(comp[neigh]==-1)
      {comp[neigh]=comp[start];
       dfs(neigh);
      }      
  }

void solve()
  {cin>>n>>m;
   g.resize(n+1);
   comp.assign(n+1,-1);
   rep(i,0,m)
    {int n1,n2;
     cin>>n1>>n2;
     g[n1].push_back(n2);
     g[n2].push_back(n1);
    }
   map<int,int> mp;

   rep(i,1,n+1)
    {if(comp[i]==-1)
      {dfs(i);
       if(ans)
        break;
      }
     mp[comp[i]]++;
    }
   ll mps=0,ans=0;

   for(auto m:mp)
    {ans+=mps*m.second;
     mps+=m.second;
    }
   cout<<ans<<'\n';
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 //int _t;cin>>_t;while(_t--)
 solve();
}