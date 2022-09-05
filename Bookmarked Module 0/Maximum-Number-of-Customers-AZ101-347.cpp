#include<bits/stdc++.h>
using namespace std;

void solve()
    {int n;
     cin>>n;
     map<int,int> mp;
     for(int i=0;i<n;i++)
        {int a,d;
         cin>>a>>d;
         mp[a]++;
         mp[d+1]--;
        }
     int ans=0,max=0;
     for(auto i:mp)
        {ans+=i.second;
         max=(ans>max)?ans:max;
        }
     cout<<max<<'\n';
    }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}