#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
   {int n,m,q;
    cin>>n>>m>>q;
    ll a[n+2][m+2];
    memset(a,0,sizeof(a));

    for(int i=0;i<q;i++)
      {int u,l,d,r,C;
       cin>>u>>l>>d>>r>>C;
       d++;r++;
       a[u][l]+=C;
       a[d][l]-=C;
       a[u][r]-=C;
       a[d][r]+=C;
      }
    
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
         a[i][j]+=a[i][j-1];
      
    ll max=-1e18;
    int count;
    for(int i=1;i<=m;i++)
      for(int j=1;j<=n;j++)
         {a[j][i]+=a[j-1][i];
          if(max<a[j][i])
            {max=a[j][i];
             count=1;
            }
          else if(max==a[j][i])
            count++;
         }
    
    cout<<max<<" "<<count<<'\n';
   }
signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);
 
//  int _t;cin>>_t;while(_t--)
 solve();
}