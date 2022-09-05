#include<bits/stdc++.h>
using namespace std;
// #define int long long

class bees
{private: 
   multiset<int> s;
   long long curr=0;
   
 public: 
   void add(int x)
      {if(curr<x)      //(curr<x)
         s.insert(x);
       return;
      }
   void print()
      {if(s.size()<*s.begin() && s.size()>curr)
          curr=s.size();
       else if(s.size()==*s.begin() && !s.empty())
         {curr=*s.begin();
          s.erase(*s.begin());
         }
       cout<<curr<<" ";
       return;
      }
};

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
   {int n;
    cin>>n;
    bees bee;
    for(int i=0;i<n;i++)
      {int x;
       cin>>x;
       bee.add(x);
       bee.print();
      }
    cout<<'\n';
   }
}