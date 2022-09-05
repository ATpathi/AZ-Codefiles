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
   int arr[n];
   arrin(n,arr)
   int ans=1;
   if(n<=m)
    {rep(i,0,n-1)
      {rep(j,i+1,n)
        {int sub=abs(arr[j]-arr[i]);
         sub%=m;
         ans=(1LL*ans*sub)%m;
        }
      }
    }  
   else 
    ans=0;

   cout<<ans;
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 //int _t;cin>>_t;while(_t--)
 solve();
}