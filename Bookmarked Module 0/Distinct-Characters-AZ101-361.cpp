#include<bits/stdc++.h>
using namespace std;

void solve()
  {string s;
   cin>>s;
   int q;
   cin>>q;
   set<int> mp[26];
   for(int i=0;i<s.size();i++)
    mp[s[i]-'a'].insert(i+1);

   while(q--)
    {int z;
     cin>>z;
     if(z==1)
      {int i;
       cin>>i;
       char ccontainer;
       cin>>ccontainer;
       mp[s[i-1]-'a'].erase(i);
       mp[ccontainer-'a'].insert(i);
       s[i-1]=ccontainer;      
      }
     else if(z==2)
      {int l,r,ans=0;
       cin>>l>>r;
       for(int i=0;i<26;i++)
        {auto itl=mp[i].lower_bound(l);
         if(itl==mp[i].end())
          continue;
         else
          {if(*itl<=r)
            ans++;
          }
        }
       cout<<ans<<'\n';
      }
    }
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}