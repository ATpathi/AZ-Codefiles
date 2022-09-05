#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout(arr) for(auto x:arr)cout<<x<<' ';
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)
#define vi vector<int>

void solve()
  {int n,k;
   cin>>n>>k;
   string s,rgb="RGB";
   cin>>s;

   int ans=1e9;


   rep(col,0,3)
    {int j=col,a[n];
     memset(a,0,sizeof(a));
     rep(i,0,n)
      {if(s[i]!=rgb[j%3])
        a[i]=1;

       j++;
       a[i]+=(i>0?a[i-1]:0);
      }

     ans=min(ans,a[k-1]);
     rep(i,k,n)
      ans=min(ans,a[i]-a[i-k]);
    }

   cout<<ans<<'\n';
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}