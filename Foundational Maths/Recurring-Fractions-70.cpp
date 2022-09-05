#include<bits/stdc++.h>
using namespace std;
#define int long long
// int MOD=1e9+7;

// int binary_exp(int a,int p)
//     {int ans=1;
//      while(p)
//          {if(p%2)
//               ans=(1LL*ans*a)%MOD;
//           a=(1LL*a*a)%MOD;
//           p/=2;
//          }
//      return ans;
//     }
// /*All the inline functions are written with the assumption that the arguments
// passed will in the range [0,MOD-1]*/
// /*An inline function must preferably be written with void return type as
// otherwise the compiler might ignore it*/
// inline void add(int &a,int b)
//     {a+=b;
//      if(a>MOD)
//          a-=MOD;
//     }
// inline void sub(int &a,int b)
//     {a-=b;
//      if(a<0)
//          a+=MOD;
//     }
// inline void mul(int &a,int b)
//     {a=(int)((1LL*a*b)%MOD);
//     }
// inline void divi(int &a,int b)
//     {a=(int)((1LL*a*(binary_exp(b,MOD-2)))%MOD);
//     }
// const int N=1e9+1;
// int facto[N];
// void factorial()
//     {facto[0]=1;
//      for(int i=1;i<N;i++)
//         facto[i]=(1LL*i*facto[i-1])%MOD;
//      return;
//     }

void solve()
    {int n,d;
     cin>>n>>d;
     if((1LL*n*d)<0)
        cout<<"-";
     n=abs(n);
     d=abs(d);
     cout<<n/d;
     int quo=n/d,rem=n%d,sor;
     if(rem)
        cout<<".";
     else 
        {cout<<'\n';
         return;
        }
     string quotient;
     unordered_map<int,int> um;
     um[rem]=0;
     int i=0;
    //  quotient.push_back('0'+quo);
     while(rem)
        {sor=10*rem;
         rem=sor%d;
         quo=sor/d;
         if(um.find(rem)==um.end())
            {um[rem]=i++;
             quotient.push_back(quo+'0');
            }
         else
            {int pos=um[rem];
             quotient.push_back(quo+'0');
             auto it=quotient.begin();
             for(int i=0;i<pos;i++)
                it++;
             quotient.insert(it,'(');
             quotient.push_back(')');
             break;
            }
        }
     cout<<quotient<<'\n';
    }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);
 //  factorial();
 int _t;cin>>_t;while(_t--)
 solve();
}