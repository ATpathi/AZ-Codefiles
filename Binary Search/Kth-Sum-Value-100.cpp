#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,m,k;
vector<int> A,B;

bool check(int x)
  {int needed=0;
   for(int i=0;i<n;i++)
    {if(A[i]<x)
      needed+=upper_bound(B.begin(),B.end(),x-A[i])-B.begin();
     else 
      break;
    }

   return (needed>=k);
  }

int binary_search(int lo,int hi)
  {int ans=lo;
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
  {cin>>n>>m>>k;
   A.resize(n);
   B.resize(m);
   for(int i=0;i<n;i++)
    cin>>A[i];
   sort(A.begin(),A.end());
   for(int i=0;i<m;i++)
    cin>>B[i];
   sort(B.begin(),B.end());

   if(n>m)
    {swap(n,m);
     swap(A,B);
    }

   int hi=A.back()+B.back(),lo=A[0]+B[0];
   cout<<binary_search(lo,hi)<<'\n';   
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}