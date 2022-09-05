#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout() for(auto x:arr)cout<<x<<' ';
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)
#define vi vector<int>

void solve()
  {int n;
   cin>>n;
   int arr[n];
   arrin(n,arr)
   
   rep(i,0,n)
    arr[i]%=n;
   rep(i,1,n)
    {arr[i]+=arr[i-1];
     arr[i]%=n;
    }

   map<int,int> m;
   m[0]=1;

   rep(i,0,n)
    {m[arr[i]]++;
     if(m[arr[i]]>1)
      {cout<<"YES\n";
       return;
      }
    }
   cout<<"NO\n";
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}