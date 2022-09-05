#include<bits/stdc++.h>
using namespace std;
#define ll long long

int MOD=1e9+7;

int binary_exp(int a,int p)
    {int ans=1;
     while(p)
         {if(p%2)
              ans=(1LL*ans*a)%MOD;
          a=(1LL*a*a)%MOD;
          p/=2;
         }
     return ans;
    }
/*All the inline functions are written with the assumption that the arguments
passed will in the range [0,MOD-1]*/
/*An inline function must preferably be written with void return type as
otherwise the compiler might ignore it*/
inline void add(int &a,int b)
    {a+=b;
     if(a>=MOD)
         a-=MOD;
    }
inline void sub(int &a,int b)
    {a-=b;
     if(a<0)
         a+=MOD;
    }
inline void mul(int &a,int b)
    {a=(int)((1LL*a*b)%MOD);
    }
inline void divi(int &a,int b)
    {a=(int)((1LL*a*(binary_exp(b,MOD-2)))%MOD);
    }
// const int N=1e6+1;
// int facto[N];
// void factorial()
//     {facto[0]=1;
//      for(int i=1;i<=N;i++)
//         {int ans=facto[i-1];
//          mul(ans,i);
//          facto[i]=ans;
//         }
//     }

void solve()
    {int n,q,k;
     cin>>n>>q>>k;
     int kpow[n+1],arr[n+2];
     memset(arr,0,sizeof(arr));
     kpow[0]=1;
     for(int i=1;i<=n;i++)
        {int ans=k;
         mul(ans,kpow[i-1]);
         kpow[i]=ans;
        }
     for(int i=0;i<q;i++)
        {int a,l,r;
         cin>>a>>l>>r;
         add(arr[l],a);
         int pou=kpow[r-l+1];
         mul(pou,a);
         sub(arr[r+1],pou);
        }
     cout<<arr[1]<<" ";
     for(int i=2;i<=n;i++)
        {int ans=k;
         mul(ans,arr[i-1]);
         add(arr[i],ans);
         
         cout<<arr[i]<<" ";
        }
    }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 //int _t;cin>>_t;while(_t--)
 solve();
}