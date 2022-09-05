#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define EPS 1e-9

const int N=1e4+10;
int A[N],B[N],n,k;

ld binary_search(ld lo,ld hi)
  {ld sum,mid;
   while(abs(hi-lo)>=EPS)
    {mid=lo+(hi-lo)/2;
     priority_queue<ld,vector<ld>,greater<ld>> pq;

     for(int i=0;i<n;i++)
      {pq.push(A[i]-mid*B[i]);
       if(pq.size()>k)
        pq.pop();
      }
     
     sum=0;
     while(!pq.empty())
      {sum+=pq.top();
       pq.pop();
      }

     if(sum>=0)
      lo=mid;
     else
      hi=mid;
    }
   
   return mid;
  }

void solve()
  {cin>>n>>k;
   ld hi=0;
   for(int i=0;i<n;i++)
    {cin>>A[i];
     hi+=A[i];
    }
   for(int i=0;i<n;i++)
    cin>>B[i];
   
   ld lo=0;
   cout<<fixed<<setprecision(6)<<binary_search(lo,hi)<<'\n';
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}