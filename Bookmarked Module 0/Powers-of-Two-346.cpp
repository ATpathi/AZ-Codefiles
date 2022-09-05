#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve()
    {int n;
     cin>>n;
     int a[n];
     map<int,int> mp;
     for(int i=0;i<n;i++)
        {cin>>a[i];
         mp[a[i]]++;
        }
     int x=1,count=0;
     for(int i=0;i<32;i++)
        {for(int j=0;j<n;j++)
            {mp[a[j]]--;   //to delete one occurrence of a[i] from the map as it traverses the array L2R
             if(mp.count(x-a[j]))
                count+=mp[x-a[j]];
            }
         for(int j=0;j<n;j++)
            mp[a[j]]++;
         x*=2;
        }
     cout<<count<<'\n';
    }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}