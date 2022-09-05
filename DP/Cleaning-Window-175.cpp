#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout() for(auto x:arr)cout<<x<<' ';
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)
#define vi vector<int>

void solve()
  {int n,m;
   cin>>n>>m;
   
   int win[n][m];
   bool wind[n][m];

   rep(i,0,n)
    rep(j,0,m)
      {win[i][j]=0;wind[i][j]=0;
       
       if(i-1>=0)
        {win[i][j]=max(win[i-1][j],win[i][j]);
         
         if(j-1>=0)
          win[i][j]=max(win[i][j],win[i-1][j-1]);

         if(j+1<m)
          win[i][j]=max(win[i][j],win[i-1][j+1]);
        }
       
       int x;
       cin>>x;

       if(x>=win[i][j])
        wind[i][j]=1;

       win[i][j]=max(win[i][j],x);
      }

   rep(i,0,n)
    {rep(j,0,m)
      cout<<wind[i][j];
     cout<<'\n';
    }
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}