#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
    {int h,w,n;
     cin>>h>>w>>n;
     set<int> ho,ve;
     multiset<int> hor,ver;
     ho={0,h};
     ve={0,w};
     hor={h};
     ver={w};
     for(int i=0;i<n;i++)
        {char ch;
         int cut;
         cin>>ch>>cut;
         if(ch=='V')
            {ve.insert(cut);
             auto it=ve.lower_bound(cut);
             auto it1=it,it2=it;
             it1--; it2++;
             ver.erase(ver.find(*it2-*it1)); //find is used to avoid deletion of all elements in multiset with value=*it2-*it1
             ver.insert(cut-*it1);
             ver.insert(*it2-cut);
            }
         else 
            {ho.insert(cut);
             auto it=ho.lower_bound(cut);
             auto it1=it,it2=it;
             it1--; it2++;
             hor.erase(hor.find(*it2-*it1));
             hor.insert(cut-*it1);
             hor.insert(*it2-cut);
            }
         int maxarea=*prev(ver.end())*(*prev(hor.end()));
         cout<<maxarea<<'\n';
        }
    }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}