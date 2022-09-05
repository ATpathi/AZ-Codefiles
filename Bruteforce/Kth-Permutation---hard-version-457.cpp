#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout(arr) for(auto x:arr)cout<<x<<" ";
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)

void solve()
  {int n;
   ll k;
   cin>>n>>k;
   int a[n];
   rep(i,0,n)
    a[i]=i+1;

   while(k>1)
    {ll temp=1;         // temp=x! (here x=0)
     int j=n-1;         // j+1=x+n  

     for(int i=1; ;i++)
      {if(temp*i>=k)
        break;

       temp*=i;
       j--;
      }

     int val=(k+temp-1)/temp;

     swap(a[j],a[j+val-1]);
     sort(a+j+1,a+n);
     k-=(val-1)*temp;
    }

   arrout(a)
   cout<<'\n';
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 //int _t;cin>>_t;while(_t--)
 solve();
}