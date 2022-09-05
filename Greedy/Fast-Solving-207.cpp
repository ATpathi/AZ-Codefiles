#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout(arr) for(auto x:arr)cout<<x<<' ';
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)
#define vi vector<int>

void solve()
  {int n;
   cin>>n;
   int R[n],l[n],r[n];

   arrin(n,R)
   
   r[0]=1;
   l[n-1]=1;
   
   rep(i,1,n)
    {if(R[i]>R[i-1])
      r[i]=1+r[i-1];
     
     else 
      r[i]=1;
    }

   rrep(i,n-2,-1)
    {if(R[i]>R[i+1])
      l[i]=1+l[i+1];
     
     else 
      l[i]=1;
    }

   ll ans=0;

   rep(i,0,n)
    ans+=max(l[i],r[i]);

   cout<<ans<<'\n';
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}