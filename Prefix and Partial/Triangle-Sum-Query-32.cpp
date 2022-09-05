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
  {int n,m,q;
   cin>>n>>m>>q;
   int arr[n+1][m+1];
   memset(arr,0,sizeof(arr));
   for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      {cin>>arr[i][j];
       if(arr[i][j]<0)
        arr[i][j]+=MOD;
      }

   int pre[n+1][m+1];
   memset(pre,0,sizeof(pre));

   for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      add(arr[i][j],arr[i][j-1]);

   for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      add(arr[i][j],arr[i-1][j]);

   for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      {int ans=pre[i-1][j-1];
       add(ans,arr[i][j]);
       sub(ans,arr[i][j-1]);
       pre[i][j]=ans;
      }

  //  for(int i=1;i<=n;i++)
  //   {for(int j=1;j<=m;j++)
  //     cout<<pre[i][j]<<" ";
  //    cout<<'\n';
  //   }

   while(q--)
    {int x,y,l;
     cin>>y>>x>>l;
     
     if(x-l<0)
      {if(y-l<0)
        {int ans=pre[y][x];
         cout<<ans<<'\n';
        }
       else
        {int ans=pre[y][x];
         sub(ans,arr[y-l][x]);
         cout<<ans<<'\n';
        }
      }
     else if(y-l<0)
      {int ans=pre[y][x];
       cout<<ans<<'\n';
      }
     else
      {int ans=pre[y][x];
       sub(ans,pre[y-l][x-l]);
       sub(ans,arr[y-l][x]);
       add(ans,arr[y-l][x-l]);
       cout<<ans<<'\n';
      }
    }
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 //int _t;cin>>_t;while(_t--)
 solve();
}