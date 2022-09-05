#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
    {int n;
     cin>>n;
     int a[n];
     for(int i=0;i<n;i++)
        cin>>a[i];
     stack<int> s;
     for(int i=0;i<n;i++)
        {while(!s.empty() && a[s.top()]>=a[i])  //Clearing out stack upto the element lesser than a[i]
            s.pop();    
         if(s.empty())
            cout<<0<<" ";
         else
            cout<<s.top()+1<<" ";
         s.push(i);
        }
     cout<<'\n';
    }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}