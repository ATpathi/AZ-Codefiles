#include<bits/stdc++.h>
using namespace std;
// #define int long long

void solve()
    {int n,k;
     cin>>n>>k;
     long long sum=0;
     multiset<int> ms1,ms2;
     for(int i=0;i<n;i++)
        {int q;
         cin>>q;
         if(q==1)
            {int x;
             cin>>x;            
             if((int)ms2.size()==k)
                {if(*ms2.begin()<x)                   
                    {ms1.insert(*ms2.begin());
                     sum-=*ms2.begin();
                     ms2.erase(ms2.begin());
                     ms2.insert(x);
                     sum+=x;
                    }                   
                 else
                    ms1.insert(x);
                }
             else
               {ms2.insert(x);
                sum+=x;
               }
            }
         else if(q==2)
            {int x;
             cin>>x;
             if((int)ms2.size()==k)
                {if(ms1.find(x)!=ms1.end())
                    ms1.erase(ms1.find(x));
                 else
                    {if(ms2.find(x)!=ms2.end())
                        {ms2.erase(ms2.find(x));
                         sum-=x;
                         if(!ms1.empty())
                            {auto it=ms1.rbegin();                            
                             sum+=*it;
                             ms2.insert(*it);                        
                             ms1.erase(ms1.find(*it));
                            }
                        }
                    }
                }
             else 
                {if(ms2.find(x)!=ms2.end())
                    {ms2.erase(ms2.find(x));
                     sum-=x;
                    }
                }
            }
         else if(q==3)
            {char ch; 
             cin>>ch;
             cout<<sum<<'\n';
            }
         // for(auto i:ms2)
         //    cout<<i<<" ";
         // cout<<'\n';
        }
    }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

//  int _t;cin>>_t;while(_t--)
 solve();
}