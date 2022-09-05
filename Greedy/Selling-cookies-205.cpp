#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout(arr) for(auto x:arr)cout<<x<<' ';
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)
#define vi vector<int>

void solve()
  {int n;
   cin>>n;
   vi arr;
   rep(i,0,n)
    {int x;
     cin>>x;
     arr.push_back(x);
    }
   sort(arr.begin(),arr.end());
   
   ll sum=0;
   rep(i,0,n)
    sum+=arr[i];
   
   ll sub=sum-arr.back();

   if(sub>=arr.back())
    cout<<(sub-arr.back())%2<<'\n';
   else
    cout<<arr.back()-sub<<'\n';
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}