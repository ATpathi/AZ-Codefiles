#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n,k;
map<int,int> cols;

bool check(int x)
  {int sum=0;
   for(auto col:cols)
    sum+=min(col.second,x);
   return (sum>=x*k);
  }

//Finding last one in array

int binary_search(int lo,int hi)
  {int ans=0;
   while(lo<=hi)
    {int mid=lo+(hi-lo)/2;

     if(check(mid)==1)
      {ans=mid;
       lo=mid+1;
      }
     else
      hi=mid-1;
    }

   return ans;
  }
void solve()
  {cin>>n>>k;
   cols.clear();
   for(int i=0;i<n;i++)
    {int col;
     cin>>col;
     cols[col]++;
    }
   
   int lo=1,hi=n/k;
   cout<<binary_search(lo,hi)<<'\n';
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}