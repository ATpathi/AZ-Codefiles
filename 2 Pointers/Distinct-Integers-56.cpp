#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout() for(auto x:arr)cout<<x<<' ';
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)

const int N=1e6+1,NO=1e5+1;
int arr[NO],n;
int freq[N];

ll kDis(int k)
  {ll ans=0;
   int head=-1,tail=0,dis=0;
   while(tail<n)
    {while(head<n-1 && (dis<k || (dis==k && freq[arr[head+1]]>0)))
      {head++;
       if(freq[arr[head]]==0)
        dis++;
       freq[arr[head]]++;
      }
     
     ans+=head-tail+1;

     if(tail<=head)
      {freq[arr[tail]]--;
       if(freq[arr[tail]]==0)
        dis--;
      
       tail++;
      }
     else
      {tail++;
       head=tail-1;
      }
    }

   return ans;
  }
void solve()
  {int k;
   cin>>n>>k;

   arrin(n,arr)

   ll ans=kDis(k)-kDis(k-1);
   cout<<ans<<'\n';
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);
 memset(freq,0,sizeof(freq));

 int _t;cin>>_t;while(_t--)
  solve();
}