#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+5;

void solve()
    {int n,k,q;
     cin>>n>>k>>q;
     int pre[N];
     for(int i=0;i<N;i++)
        pre[i]=0;
     int par[N];
     par[0]=0;
     for(int i=0;i<n;i++)
        {int l,r;
         cin>>l>>r;
         pre[l]++;
         pre[r+1]--;
        }
     for(int i=1;i<N;i++)
        pre[i]+=pre[i-1];
     for(int i=1;i<N;i++)
        par[i]=(pre[i]>=k);
     for(int i=2;i<N;i++)
        par[i]+=par[i-1];
     
     while(q--)
        {int l,r;
         cin>>l>>r;
         cout<<par[r]-par[l-1]<<'\n';
        }
    }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

//  int _t;cin>>_t;while(_t--)
 solve();
}