#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout(arr) for(auto x:arr)cout<<x<<' ';
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)
#define vi vector<int>

int n,m,ans=0;
char grid[1010][1010];
bool vis[1010][1010];
int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};

bool valid_grid(int x,int y)
  {return !(x<0 || x>=n || y<0 || y>=m || vis[x][y] || grid[x][y]=='#');
  }

void dfs(int x,int y)
  {vis[x][y]=1;
   rep(i,0,4)
    {int nx=x+dx[i];
     int ny=y+dy[i];
     if(valid_grid(nx,ny))
      dfs(nx,ny);
    }
   return;
  }

void solve()
  {cin>>n>>m;
   rep(i,0,n)
    cin>>grid[i];
   memset(vis,0,sizeof(vis));
   
   rep(i,0,n)
    rep(j,0,m)
      {if(valid_grid(i,j))
        {dfs(i,j);
         ans++;
        }
      }

   cout<<ans;
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 //int _t;cin>>_t;while(_t--)
 solve();
}