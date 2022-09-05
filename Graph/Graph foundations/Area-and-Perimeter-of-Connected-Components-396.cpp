#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout(arr) for(auto x:arr)cout<<x<<' ';
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)
#define vi vector<int>

int n;
char grid[1010][1010];
int dx[]={1,0,-1,0},dy[]={0,-1,0,1}; 
int vis[1010][1010];
pair<int,int> ans={0,0};

pair<int,int> dfs(int x,int y)
  {vis[x][y]=1;
   pair<int,int> ans={1,0};

   rep(i,0,4)
    {int nx=x+dx[i],ny=y+dy[i];
     if(nx<n && nx>=0 && ny>=0 && ny<n)
      {if(grid[nx][ny]=='#' && vis[nx][ny]==0)
        {pair<int,int> reto=dfs(nx,ny);
         ans.first+=reto.first;
         ans.second+=reto.second;
        }
       else if(grid[nx][ny]=='.')
        ans.second++;
      }
     else
      ans.second++;
    }
   return ans;
  }

void solve()
  {cin>>n;
   rep(i,0,n)
    rep(j,0,n)
      vis[i][j]=0;

   rep(i,0,n)
    cin>>grid[i];

   rep(i,0,n)
    rep(j,0,n)
      {if(grid[i][j]=='#' && vis[i][j]==0)
        {pair<int,int> reto=dfs(i,j);
         if(reto.first>ans.first)
          {ans.first=reto.first;
           ans.second=reto.second;
          }
         else if(ans.first==reto.first && ans.second>reto.second)
          ans.second=reto.second;
        }
      }

  //  rep(i,0,n)
  //   {rep(j,0,n)
  //     cout<<grid[i][j];
  //    cout<<'\n';
  //   }
   cout<<ans.first<<" "<<ans.second<<'\n';
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 //int _t;cin>>_t;while(_t--)
 solve();
}