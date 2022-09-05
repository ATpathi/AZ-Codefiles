#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long


const int N=1e5+10; 
int arr[N],n,k;

int check(ll i)
  {ll left=i;
   int reqno=1;
   
   for(int j=0;j<n;j++)
    {if(left>=arr[j])
      left-=arr[j];
     else
      {left=i-arr[j];
       reqno++;
      }
     if(reqno>k)
      return 0;
    }
   
   return 1;
  }


int binary_search(int lo,ll hi)
  {ll ans=0;
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
  {cin>>n>>k;
   
   int lo=0;
   ll hi=0;
   for(int i=0;i<n;i++)
    {cin>>arr[i];
     hi+=arr[i];
     lo=max(lo,arr[i]);
    }

   cout<<binary_search(lo,hi)<<'\n';
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}