#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
    {int N;
     cin>>N;
     int arr[N];
     for(int i=0;i<N;i++)
        cin>>arr[i];

     int preon[31][N+1];
     memset(preon,0,sizeof(preon));

     for(int i=1;i<=N;i++)
        {for(int j=29;j>=0;j--)
            {preon[j][i]+=preon[j][i-1];
             if(arr[i-1]&(1<<j))
                preon[j][i]+=1;
            }
        }

    //  for(int j=29;j>=0;j--)
    //     cout<<preon[j][5];
     int q;
     cin>>q;

     while(q--)
        {int l,r;
         cin>>l>>r;
         ll xory=0,andy=0,ory=0;

         //XOR
         for(int i=30;i>=0;i--)
            {int nones=preon[i][r]-preon[i][l-1];
             if(nones<(r-l+1-nones))
                xory+=(1LL<<i);
            }
         //AND
         for(int i=30;i>=0;i--)
            {int nones=preon[i][r]-preon[i][l-1];
             if(nones!=0)
                andy+=(1LL<<i);
            }
         //OR
         for(int i=30;i>=0;i--)
            {int nones=preon[i][r]-preon[i][l-1];
             if(nones!=(r-l+1))
                ory+=(1LL<<i);
            }

         cout<<xory+ory+andy<<'\n';
         // cout<<"x1: "<<xory<<"\n";
         // cout<<"x2: "<<ory<<"\n";
         // cout<<"x3: "<<andy<<"\n";
        }
    }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}