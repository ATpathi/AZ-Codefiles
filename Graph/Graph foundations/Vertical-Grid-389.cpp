#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout(arr) for(auto x:arr)cout<<x<<' ';
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)
#define vi vector<int>

int grid[101][10];
int n,k;
int dx[]={1,0,-1,0},dy[]={0,-1,0,1};
int vis[101][10];
int comp_no=1;

bool valid_move(int x,int y,int cur_comp)
  {return (x>=0 && x<n && y>=0 && y<10 && grid[x][y]==cur_comp);
  }

bool gravity()
  {bool changes=0;
   rep(i,0,10)
    {int top=n-1,bottom=n-1;
     while(top>=0)
      {while(top>=0 && grid[top][i]==0)
        top--;
       
       if(top>=0)
        {if(top!=bottom)
          changes=1;
         grid[bottom--][i]=grid[top--][i];
        }
      }
     while(bottom>=0)
      grid[bottom--][i]=0;
    }
   return changes;
  }

void dfs(int x,int y)
  {rep(i,0,4)
    {int ny=y+dy[i],nx=x+dx[i];
     if(vis[nx][ny]==0 && valid_move(nx,ny,grid[x][y]))
      {vis[nx][ny]=vis[x][y];       
       dfs(nx,ny);
      }
    }
  }

void solve()
  {cin>>n>>k;

   rep(i,0,n)
    {string s;
     cin>>s;
     
     rep(j,0,10)
      grid[i][j]=s[j]-'0';  
    }
   
   map<int,int> mp;

   do
    {rep(i,0,n)
      rep(j,0,10)
        vis[i][j]=0;

     rep(x,0,n)
        {rep(y,0,10)
          {if(grid[x][y]!=0 && vis[x][y]==0)
            {vis[x][y]=comp_no++;
             dfs(x,y);
            }
           mp[vis[x][y]]++;
          }
        }

     rep(i,0,n)
      rep(j,0,10)
        if(grid[i][j]>0 && mp[vis[i][j]]>=k)
          grid[i][j]=0;
          
    } while (gravity()>0);
   
   
   rep(i,0,n)
    {rep(j,0,10)
      cout<<grid[i][j];
     cout<<'\n';
    }
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 //int _t;cin>>_t;while(_t--)
 solve();
}