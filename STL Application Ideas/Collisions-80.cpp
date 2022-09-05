#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
    {int n,m;       //n:x m:y
     cin>>n>>m;
     int xax[n],yax[m];
     for(int i=0;i<n;i++)
        {int xi,ui;
         cin>>xi>>ui;
         xax[i]=(xi*ui);
        }
     for(int i=0;i<m;i++)
        {int yi,vi;
         cin>>yi>>vi;
         yax[i]=(yi*vi);
        }
     sort(yax,yax+m);
     sort(xax,xax+n);
     
     int ans=0;

     for(int i=0,j=0;i<m && j<n; )
        {if(yax[i]==xax[j])
            {ans++;
             i++;
             j++;
            }
         if(yax[i]>xax[j])
            j++;
         if(yax[i]<xax[j])
            i++;
        }
     cout<<ans<<'\n';
    }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}