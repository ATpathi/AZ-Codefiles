#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
    {int n;
     cin>>n;
     vector<int> a,b,c;
     for(int i=0;i<n;i++)
        {int x;
         cin>>x;
         a.push_back(x);
        }
     for(int i=0;i<n;i++)
        {int x;
         cin>>x;
         a[i]-=x;
        }
     
     sort(a.begin(),a.end());
     int count=0;
     for(int i=0;i<n;i++)
        {auto it=lower_bound(a.begin(),a.end(),(1-a[i]));
         int gap=distance(it,a.end());
         if(a[i]>0)
            count--;
         count+=gap;
        }
     count/=2;
     cout<<count<<'\n';
    }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}