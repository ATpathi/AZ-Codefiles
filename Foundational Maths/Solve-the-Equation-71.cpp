#include<bits/stdc++.h>
using namespace std;

int MOD;

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
// const int N=1e9+1;
// int facto[N];
// void factorial()
//     {facto[0]=1;
//      for(int i=1;i<=N;i++)
//         facto[i]=i*facto[i-1];
//     }

void solve()
   {string s;
    getline(cin,s);
    vector<int> val;
    vector<char> op;
    int curr=0;
    for(int i=0;i<(int)s.length();i++)
      {if(s[i]>='0' && s[i]<='9')
         {curr*=10;
          curr+=(s[i]-'0');
         }
       else if((s[i]=='+') || (s[i]=='-') || (s[i]=='*') || (s[i]=='/'))
          op.push_back(s[i]);
       else if(s[i]==' ')
         {if(curr)
            {val.push_back(curr);
             curr=0;
            }
         }
      }
    val.push_back(curr);
    // cout<<(int)val.size();
    // cout<<(int)op.size();
    
    int ans=val[0]; 
    MOD=val[3];
    for(int i=0;i<3;i++)
      val[i]%=MOD;
    ans%=MOD;
    // cout<<MOD<<'\n';
    if(((op[0]=='+') || (op[0]=='-')) && ((op[1]=='+') || (op[1]=='-')))
      {if(op[0]=='+')
        {add(ans,val[1]);
         //cout<<ans<<" ";
        }
       else
        {sub(ans,val[1]);
         //cout<<ans<<" ";
        }

       if(op[1]=='+')
        {add(ans,val[2]);
         //cout<<ans<<" ";
        }
       else
        {sub(ans,val[2]);
         //cout<<ans<<" ";
        }
      }
    if(((op[0]=='*') || (op[0]=='/')) && ((op[1]=='*') || (op[1]=='/')))
      {if(op[0]=='*')
        {mul(ans,val[1]);
         //cout<<ans<<" ";
        }
       else
        {divi(ans,val[1]);
         //cout<<ans<<" ";
        }

       if(op[1]=='*')
        {mul(ans,val[2]);
         //cout<<ans<<" ";
        }
       else
        {divi(ans,val[2]);
         //cout<<ans<<" ";
        }
      }
    if(((op[0]=='*') || (op[0]=='/')) && ((op[1]=='+') || (op[1]=='-')))
      {if(op[0]=='*')
        {mul(ans,val[1]);
         //cout<<ans<<" ";
        }
       else
        {divi(ans,val[1]);
         //cout<<ans<<" ";
        }

       if(op[1]=='+')
         add(ans,val[2]);
       else
        {sub(ans,val[2]);
         //cout<<ans<<" ";
        }
      }
    if(((op[1]=='*') || (op[1]=='/')) && ((op[0]=='+') || (op[0]=='-')))
      {ans=val[1];
       if(op[1]=='*')
        {mul(ans,val[2]);
         //cout<<ans<<" ";
        }
       else
        {divi(ans,val[2]);
         //cout<<ans<<" ";
        }

       if(op[0]=='+')
        {add(ans,val[0]);
         //cout<<ans<<" ";
        }
       else
        {sub(ans,val[0]);
         //cout<<ans<<" ";
        }
      }
    

    cout<<"\n"<<ans<<'\n';
   }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);
 int _t;cin>>_t;
 string ss;
 getline(cin,ss);
 while(_t--)
 solve();
}