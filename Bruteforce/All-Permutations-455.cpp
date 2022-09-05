#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i]
#define arrout(arr) for(auto x:arr)cout<<x<<" "
#define rep(i,a,b) for(int i=a;i<b;i++)

int n;
map<int,int> perm;
vector<int> soln;

void rec(int level)
  {if(level==n)
    {arrout(soln);
     cout<<'\n';    
     return;
    }
   
   for(auto x:perm)
    {if(x.second)
      {perm[x.first]--;
       soln.push_back(x.first);
      
       rec(level+1);

       soln.pop_back();
       perm[x.first]++;
      }
    }
  }

void solve()
  {cin>>n;
   int arr[n];
   arrin(n,arr);
   rep(i,0,n)
    perm[arr[i]]++;
      
   rec(0);
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 //int _t;cin>>_t;while(_t--)
 solve();
}