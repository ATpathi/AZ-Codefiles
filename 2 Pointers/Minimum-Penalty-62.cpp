#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout() for(auto x:arr)cout<<x<<' '
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)

void solve()
  {int n,d;
   cin>>n>>d;
   int arr[n];
   arrin(n,arr);
   
   unordered_map<int,int> freq;
   int head=-1,tail=0,dis=0;
   int ans=d+1;

   while(tail<=n-d)
    {while(head<n-1 && head-tail+1<d)
      {head++;
       freq[arr[head]]++;
       if(freq[arr[head]]==1)
        dis++;
      }

     ans=min(ans,dis);

     if(tail<=head)
      {freq[arr[tail]]--;
       if(freq[arr[tail]]==0)
        {freq.erase(freq.find(arr[tail]));
         dis--;
        }
       
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