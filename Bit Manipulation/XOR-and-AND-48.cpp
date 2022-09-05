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
const int NO=1e5+1;
int p2[NO];
void pow2()
    {p2[0]=1;
     for(int i=1;i<=NO;i++)
        {int ans=p2[i-1];
         mul(ans,2);
         p2[i]=ans;
        }
    }

void solve()
   {int N;
    cin>>N;
    int arr[N];
    for(int i=0;i<N;i++)
      cin>>arr[i];

    int xorpa=0,xorsu=0,andpa=0,andsu=0;
    for(int i=29;i>=0;i--)
      {int none=0;
       for(int j=0;j<N;j++)
         {if(arr[j]&(1<<i))
            none++;
         }
       int xorp=0,xors=0,andp=0,ands=0;
       ands=p2[none];sub(ands,1);mul(ands,p2[i]);
       xorp=none;mul(xorp,(N-none));mul(xorp,p2[i]);
       andp=none-1;mul(andp,none);divi(andp,2);mul(andp,p2[i]);
       if(none)
         {xors=p2[none-1];
          mul(xors,p2[N-none]);mul(xors,p2[i]);
         }

       add(xorpa,xorp);
       add(xorsu,xors);
       add(andpa,andp);
       add(andsu,ands);
      }
    cout<<xorpa<<" "<<xorsu<<" "<<andpa<<" "<<andsu<<'\n';
   }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);
 pow2();
 int _t;cin>>_t;while(_t--)
 solve();
}