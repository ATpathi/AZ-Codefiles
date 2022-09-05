#include<bits/stdc++.h>
using namespace std;
#define ll long long
int MOD=1e9+7;


inline void add(int &a,int b)
   {a+=b;
    if(a>MOD)
       a-=MOD;
   }
inline void sub(int &a,int b)
   {a-=b;
    if(a<0)
       a+=MOD;
   }


void solve()
   {int n,m,q;
    cin>>n>>m>>q;
    int a[n][m];
    memset(a,0,sizeof(a));
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        {cin>>a[i][j];
         if(a[i][j]<0)
            a[i][j]+=MOD;
        }
    int pre[n+1][m+1];
    memset(pre,0,sizeof(pre));
    

    for(int i=1;i<=n;i++)
      {for(int j=1;j<=m;j++)
         {int ans=a[i-1][j-1];
          add(ans,pre[i][j-1]);
          add(ans,pre[i-1][j]);
          sub(ans,pre[i-1][j-1]);
          pre[i][j]=ans;
         }
      }

    for(int i=0;i<q;i++)
      {int u,l,d,r;
       cin>>u>>l>>d>>r;
       u--;l--;
       int ans=pre[d][r];
       add(ans,pre[u][l]);
       sub(ans,pre[d][l]);
       sub(ans,pre[u][r]);
       cout<<ans<<'\n';
      }
   }
signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);
 
//  int _t;cin>>_t;while(_t--)
 solve();
}