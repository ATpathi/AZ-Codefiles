#include<bits/stdc++.h>
using namespace std;

void solve()
    {int m,n,p;
     cin>>n>>m>>p;
    
     for(int i=0;i<((p+1)*n)+1;i++)
        {for(int j=0;j<((p+1)*m)+1;j++)
            {if((i%(2*(p+1)))==(j%(2*(p+1))) && i%(p+1))
                cout<<"\\";
             else if((2*(p+1)-(i%(2*(p+1))))==j%(2*(p+1)) && i%(p+1))
                cout<<'/';
             else if(i%(p+1)==0 || j%(p+1)==0)
                cout<<"*";
             else
                cout<<".";
            }
         cout<<'\n';
        }
    }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();

}