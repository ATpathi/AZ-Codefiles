#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout(arr) for(auto x:arr)cout<<x<<' ';
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)
#define vi vector<int>
const int N=1e4;

void solve()
  {int n,max_freq=0;
   cin>>n;
   map<int,int> freq;

   rep(i,0,n)
    {int num;
     cin>>num;
     freq[num]++;
     max_freq=max(max_freq,freq[num]);
    }

   if(max_freq>n-max_freq)
    cout<<2*(n-max_freq)<<'\n';
   else
    cout<<n<<'\n';   
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}