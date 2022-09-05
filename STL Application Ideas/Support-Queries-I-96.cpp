#include<bits/stdc++.h>
using namespace std;
// #define int long long

void solve()
    {int n;
     cin>>n;
     long long sum=0;
     multiset<int> ms;
     for(int i=0;i<n;i++)
        {int q;
         cin>>q;
         if(q==1)
            {int x;
             cin>>x;
             ms.insert(x);
             sum+=x;
            }
         else if(q==2)
            {int x;
             cin>>x;
             if(ms.count(x))
                {ms.erase(ms.find(x));
                 sum-=x;
                }
            }
         else if(q==3)
            {char ch;
             cin>>ch;
             if(ms.empty())
                cout<<-1<<'\n';
             else
                cout<<*ms.begin()<<'\n';
            }
         else if(q==4)
            {char ch;
             cin>>ch;
             if(ms.empty())
                cout<<-1<<'\n';
             else
                cout<<*ms.rbegin()<<'\n';
            }
         else if(q==5)
            {char ch;
             cin>>ch;
             cout<<sum<<'\n';
            }
        }
     
    }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

//  int _t;cin>>_t;while(_t--)
 solve();
}