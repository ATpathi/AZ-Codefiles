#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
  {int n;
   cin>>n;
   int arr[n+1];
   arr[0]=0;
   int lo_o=0,hi_o=0;
   for(int i=1;i<=n;i++)
    {cin>>arr[i];
     lo_o=min(arr[i],lo_o);
     hi_o+=arr[i];
    }

   int no_subs=(n*(n+1))/2;
   int ans;
   while(lo_o<=hi_o)
    {int medx=(lo_o+hi_o)/2;
     int no_nos=0;
    //  cout<<"medx: "<<medx<<'\n';
     int p2=1,p1=1,sum=0;
     while(p2<=n)
      {sum+=arr[p2];
       while(sum>medx && p2>=p1)
        {sum-=arr[p1];
         p1++;
        }
       no_nos+=p2-p1+1;
       p2++;
      }

     if(no_nos>=(no_subs+1)/2)
      {hi_o=medx-1;
       ans=medx;
      //  cout<<"ans changed to: "<<ans<<" no_nos with this new medx: "<<no_nos<<'\n';
      }
     else
      lo_o=medx+1;
    }

   cout<<ans<<'\n';
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}