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
vi team;
bool ans=0;

void dfs(int start)
  {if(team[start]==-1)
    team[start]=0;
  //  cout<<"node: "<<start<<" "<<"team: "<<team[start]<<" ";
   for(auto neigh:g[start])
    {if(team[neigh]==-1)
      {team[neigh]=1-team[start];
       dfs(neigh);
      }
     else
      {// cout<<"->start: "<<start<<" untraversed node: "<<neigh<<" team: "<<team[neigh]<<" team[start]: "<<team[start]<<" ";
       if(team[neigh]==team[start])
        {// cout<<"CHANGED ";
         ans=1;
        }
      }
    }
  }

void solve()
  {cin>>n>>m;
   g.resize(n+1);
   team.assign(n+1,-1);
   rep(i,0,m)
    {int n1,n2;
     cin>>n1>>n2;
     g[n1].push_back(n2);
     g[n2].push_back(n1);
    }

   rep(i,1,n+1)
    if(team[i]==-1)
      {dfs(i);
       if(ans)
        break;
      }

   if(ans)
    cout<<"NO\n";
   else
    cout<<"YES\n";
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 //int _t;cin>>_t;while(_t--)
 solve();
}