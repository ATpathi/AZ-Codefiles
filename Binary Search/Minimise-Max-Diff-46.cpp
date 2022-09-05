#include<bits/stdc++.h>
using namespace std;
#define ll int

const int N=1e5+10; 
int arr[N],n,k;

bool check(int i)
  {int reqno=0;

   for(int j=1;j<n;j++)
    reqno+=((arr[j]-arr[j-1]+i-1)/i)-1;
      
   return (reqno<=k);
  }

int binary_search(int lo,int hi)
  {int ans=0;
   while(lo<=hi)
    {int mid=lo+(hi-lo)/2;
     
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
   
   int lo=1;
   int hi=1;
   for(int i=0;i<n;i++)
    cin>>arr[i];
   sort(arr,arr+n);
   
   for(int i=1;i<n;i++)
    hi=max(arr[i]-arr[i-1],hi);

   cout<<binary_search(lo,hi)<<'\n';
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}