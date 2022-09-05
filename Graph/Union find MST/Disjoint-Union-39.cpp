#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout(arr) for(auto x:arr)cout<<x<<' ';
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)
#define vi vector<int>

int par[10010],rnk[10010];

int find(int node)
  {while(par[node]!=node)
  	{par[node]=par[par[node]];
     node=par[node];
    }
   return node;
  }

void merge(int x,int y)
  {int X=find(x),Y=find(y);
   if(X!=Y)
    {if(rnk[X]>=rnk[Y])
      {par[Y]=X;
       rnk[X]+=rnk[Y];
      }
    else
      {par[X]=Y;
       rnk[Y]+=rnk[X];
      }
    }
  }

void solve()
  {int n,q;
   cin>>n>>q;
   rep(i,0,n)
    {par[i]=i;
     rnk[i]=1;
    }

   rep(i,0,q)
    {int a,b,c;
     cin>>a>>b>>c;
     if(a==0)
      merge(b,c);
     else
      if(find(b)==find(c))
        cout<<"1\n";
      else
        cout<<"0\n";
    }
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 //int _t;cin>>_t;while(_t--)
 solve();
}