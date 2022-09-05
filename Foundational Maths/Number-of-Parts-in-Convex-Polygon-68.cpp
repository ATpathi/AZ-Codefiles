#include<bits/stdc++.h>
using namespace std;

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
     if(a>MOD)
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
// const int N=1e9+1;
// int facto[N];
// void factorial()
//     {facto[0]=1;
//      for(int i=1;i<N;i++)
//         facto[i]=(1LL*i*facto[i-1])%MOD;
//      return;
//     }

void solve()
    {int n,v;
     cin>>n;
     int num=binary_exp(n,4);
     v=binary_exp(n,3); 
     mul(v,6);
     sub(num,v);
     v=binary_exp(n,2); 
     mul(v,23);
     add(num,v);
     v=n;
     mul(v,42);
     sub(num,v);
     divi(num,24);
     add(num,1);
     cout<<num<<"\n";
    }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);
 //  factorial();
 int _t;cin>>_t;while(_t--)
 solve();
}