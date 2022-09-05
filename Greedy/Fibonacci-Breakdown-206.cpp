#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout(arr) for(auto x:arr)cout<<x<<' ';
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)
#define vi vector<int>

vi fib;

void fibo()
  {fib.push_back(1);
   fib.push_back(1);
   
   rep(i,2,50)
    fib.push_back(fib[i-1]+fib[i-2]);
  }

void solve()
  {int k,ans=0;
   cin>>k;

   while(k)
    {auto it=upper_bound(fib.begin(),fib.end(),k);
     it--;
     k-=*it,ans++;
    }

   cout<<ans<<'\n';
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);
 fibo();

 int _t;cin>>_t;while(_t--)
 solve();
}