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
    {int n,q;
     cin>>n>>q;
     int A[n+2],B[n+2];
     
     memset(A,0,sizeof(A));
     memset(B,0,sizeof(B));

     while(q--)
        {int a,l,d,r;
         cin>>a>>d>>l>>r;

         int ans=d,ans1=a;
         mul(ans,l);
         sub(ans1,ans);
         add(A[l],ans1);
         sub(A[r+1],ans1);

         add(B[l],d);
         sub(B[r+1],d);
        }

     for(int i=1;i<=n;i++)
        {add(A[i],A[i-1]);
         add(B[i],B[i-1]);
         int ans=B[i],ans1=A[i];
         mul(ans,i);
         add(ans1,ans);
         cout<<ans1<<" ";
        }
    }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 //int _t;cin>>_t;while(_t--)
 solve();
}