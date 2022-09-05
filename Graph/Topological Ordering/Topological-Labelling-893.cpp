#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout(arr) for(auto x:arr)cout<<x<<' ';
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)
#define vi vector<int>

int n,m;
vi outdeg;
vector<vi> g;
int ans[100100];

void kahn()
  {priority_queue<int> pq;
   int index=n;
   rep(i,1,n+1)
    if(outdeg[i]==0)
      pq.push(i);

   while(!pq.empty())
    {int node=pq.top();
     pq.pop();
     
     for(auto neigh:g[node])
      {outdeg[neigh]--;
       if(outdeg[neigh]==0)
        pq.push(neigh);
      }

     ans[node]=index--;
    }
  }

void solve()
  {cin>>n>>m;
   g.resize(n+1);
   outdeg.assign(n+1,0);
   rep(i,0,m)
    {int n1,n2;cin>>n1>>n2;
     g[n2].push_back(n1);
     outdeg[n1]++;
    }
   
   kahn();

   rep(i,1,n+1)
    cout<<ans[i]<<" ";
   cout<<'\n'; 
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 //int _t;cin>>_t;while(_t--)
 solve();
}