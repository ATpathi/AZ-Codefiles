#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout(arr) for(auto x:arr)cout<<x<<' ';
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)
#define vi vector<int>

int par[100100],rnk[100100];
int comp=0;

int find(int node)
    {if(par[node]==node)
      return node;
     else
      return par[node]=find(par[node]);
    }

void merge(int x,int y)
  {int X=find(x),Y=find(y);

   if(X==Y)
    return;
   else
    {if(rnk[X]<rnk[Y])
      swap(X,Y);

     par[Y]=X;
     rnk[X]+=rnk[Y];
     rnk[Y]=0;
     comp++;
    }  
  }

void solve()
  {int n,m,q;
   cin>>n>>m>>q;
   pair<int,int> edges[m];
   rep(i,0,m)
    {int a,b;
     cin>>a>>b;
     edges[i]={a,b};
    }
   bool init[m];
   int queries[q];
   memset(init,0,sizeof(init));
   rep(i,0,q)
    {int a;cin>>a;
     if(a==1)
      {int b;cin>>b;
       init[b-1]=1;
       queries[q-1-i]=b-1;
      }
     else
      queries[q-1-i]=-1;
    }
 
   rep(i,0,n)
    {par[i]=i;
     rnk[i]=1;
    }

   rep(i,0,m)
    {if(!init[i])
      merge(edges[i].first,edges[i].second);
    }

   stack<int> ans;
  //  arrout(queries)
  //  cout<<'\n';
   for(auto q:queries)
    {if(q==-1)
      {ans.push(n-comp);
      //  cout<<n-comp<<'\n';
      }
     else
      merge(edges[q].first,edges[q].second);
    }

   while(!ans.empty())
    {cout<<ans.top()<<'\n';
     ans.pop();
    }
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 //int _t;cin>>_t;while(_t--)
 solve();
}