#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout(arr) for(auto x:arr)cout<<x<<' ';
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)
#define vi vector<int>

void solve()
    {map<int,int> mp;
     int n,max=0;
     cin>>n;
     rep(i,1,n)
        {int n1,n2;
         cin>>n1>>n2;
         mp[n1]++;
         mp[n2]++;
         if(max<mp[n1])
            max=mp[n1];
         
         if(max<mp[n2])
            max=mp[n2];
        }
     cout<<max+1<<'\n';
    }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 //int _t;cin>>_t;while(_t--)
 solve();
}