#include<iostream>
using namespace std;

// The first line contains two space-separated integers N, Q where 1<=N<=10^6, 1<=Q<=10^6.

// Next line contains N space-separated integers (-1e9<=Ai<=1e9).

// Next Q lines contain two space-separated integers L, R where 1<=L<=R<=N.

#define mod 1000000007
typedef long long ll;

int main()
{int n,q;
 cin>>n>>q;

 ll arr[n],pre[n];

 for(int i=0;i<n;i++)
    {cin>>arr[i];
     if(i==0)
        pre[i]=arr[i];
     else
        pre[i]=pre[i-1]+arr[i];
    }

 ll sum;

 for(int i=0;i<q;i++)
    {int l,r;
     cin>>l>>r;
     
     if(l==1)
        sum=pre[r-1];
     else if(l==r)
        sum=pre[r-1]-pre[l-2];
     else
        sum=pre[r-1]-pre[l-2];
     
     if(sum>=mod)
         sum-=mod;
     else if(sum<0)
         sum+=mod;

     cout<<sum<<endl;
    }
 
 return 0;
}