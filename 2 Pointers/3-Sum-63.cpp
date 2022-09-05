#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout() for(auto x:arr)cout<<x<<' '
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)

void solve()
  {int n;
   ll t,ans=1e18;
   cin>>n>>t;
   int arr[n];
   arrin(n,arr)
   sort(arr,arr+n);

   rep(i,0,n)
    {int head=n-1,tail=0;
     ll tar=t-arr[i],sum=0;

     while(head>i && tail<i)
      {sum=arr[head]+arr[tail];
       ll diff=abs(tar-sum);
       if(sum<tar)
        {tail++;
         sum=arr[head]+arr[tail];
         ll diff1=abs(tar-sum);
         if(diff1>diff)
          break;
        }
       else if(sum>tar)
        {head--;
         sum=arr[head]+arr[tail];
         ll diff1=abs(tar-sum);
         if(diff1>diff)
          break;
        }
       else
        {ans=0;
         head--;tail++;
         break;
        }

       ans=min(ans,diff);
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