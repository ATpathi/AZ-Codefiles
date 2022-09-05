#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout() for(auto x:arr)cout<<x<<' ';
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)
const int N=1e9+1;
bool freq[N];

void solve()
  {int n,x;
   cin>>n>>x;
   int arr[n];
   arrin(n,arr)
   
   if(n<4)
    {cout<<"NO";
     return;
    }

   
   memset(freq,0,sizeof(freq));

   for(int b=n-1;b>0;b--)
    {rep(a,0,b)
      {if(x-(arr[a]+arr[b])>=0 && freq[x-(arr[a]+arr[b])])
        {cout<<"YES";
         return;
        }

       int c=b;
       rep(d,c+1,n)
        if(arr[c]+arr[d]<=1e9)
          freq[arr[c]+arr[d]]=1;
      }
    }
   
   cout<<"NO";
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 //int _t;cin>>_t;while(_t--)
 solve();
}