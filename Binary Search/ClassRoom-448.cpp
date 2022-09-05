#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=1e5+10;
int n,k,arr[N];

bool check(int x)
  {int index=0;
   for(int i=1;i<k;i++)
    {index=lower_bound(arr,arr+n,arr[index]+x)-arr;
     
     if(index==n)
      return 0;
    }
   return 1;
  }

//Finding last one in array

int binary_search(int lo,int hi)
  {int ans=hi;
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
   for(int i=0;i<n;i++)
    cin>>arr[i];
   sort(arr,arr+n);
   int hi=arr[n-1],lo=0;

   cout<<binary_search(lo,hi)<<'\n';
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}