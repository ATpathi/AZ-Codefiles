#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout() for(auto x:arr)cout<<x<<' '
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)

void solve()
  {int n,k;
   cin>>n>>k;
   int arr[n];
   arrin(n,arr);
   
   int head=-1,tail=0;
   ll sum=0,ans=0;

   while(tail<n)
    {while(head<n-1 && sum+arr[head+1]<=k)
      {head++;
       sum+=arr[head];
      }

     ans+=head-tail+1;

     if(tail<=head)
      {sum-=arr[tail];
       tail++;
      }
     else
      {tail++;
       head=tail-1;
      }
    }

   cout<<ans<<'\n';
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}