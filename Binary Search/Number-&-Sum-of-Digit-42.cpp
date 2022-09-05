#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll s;
bool check(ll x)
  {ll no=x,s_o_d=0;
   while(no)
    {s_o_d+=no%10;
     no/=10;
    }
   return (x-s_o_d>=s);
  }

//Finding last one in array

ll binary_search(ll lo,ll hi)
  {ll ans=hi+1;
   while(lo<=hi)
    {ll mid=lo+(hi-lo)/2;

     if(check(mid)==1)
      {ans=mid;
       hi=mid-1;
      }
     else
      lo=mid+1;
    }

   return ans;
  }

void solve()
  {ll n;
   cin>>n>>s;
   ll lo=1,hi=n;
   cout<<n-binary_search(lo,hi)+1<<'\n';
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}