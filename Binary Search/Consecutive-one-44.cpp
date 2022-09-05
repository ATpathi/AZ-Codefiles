#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=1e5+10;
int n,k,arr[N];

bool check(int start,int x)
  {return (x-start+1-(arr[x]-((start==0)?0:arr[start-1]))<=k);
  }

//Finding last one in array

int binary_search(int start,int lo,int hi)
  {int ans=start-1;
   while(lo<=hi)
    {int mid=lo+(hi-lo)/2;

     if(check(start,mid)==1)
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
    {cin>>arr[i];
     arr[i]+=((i==0)?0:arr[i-1]);
    }

   int maxi=0;
   for(int start=0;start<n;start++)
    {int lo=start,hi=n-1;
     maxi=max(binary_search(start,lo,hi)-(start-1),maxi);
    }
   cout<<maxi<<'\n';
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}