#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout() for(auto x:arr)cout<<x<<' '
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)

void solve()
  {int n,k,d;
   cin>>n>>k>>d;
   int arr[n];
   int pre[n];
   arrin(n,arr)
   pre[0]=arr[0];
   rep(i,1,n)
    pre[i]=arr[i]+pre[i-1];

   multiset<int> ms;
   int ans=-1e9-7;

   int head=-1,tail=0,oddc=0;
   while(tail<n)
    {while(head<n-1 && (oddc<k || (oddc==k && arr[head+1]%2==0)))
      {head++;
       if(arr[head]%2)
        oddc++;
       ms.insert(pre[head]);
      }

     int tar=(tail==0?0:pre[tail-1])+d;
     auto hi=ms.upper_bound(tar);

     if(hi!=ms.begin())
      {hi--;
       int high=*hi-(tail==0?0:pre[tail-1]);
       ans=max(ans,high);
      }

     if(tail<=head)
      {ms.erase(ms.find(pre[tail]));
       if(arr[tail]%2)
        oddc--;
       tail++;
      }
     else
      {tail++;
       head=tail-1;
      }
    }
   if(ans==-1e9-7)
    cout<<"IMPOSSIBLE\n";
   else
    cout<<ans<<'\n';
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}