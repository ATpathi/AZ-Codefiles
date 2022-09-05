#include<bits/stdc++.h>
using namespace std;
# define ll long long
void solve()
  {int n,k;
   cin>>n>>k;
   map<int,int> m;
   for(int i=0;i<n;i++)
    {int x;cin>>x;
     m[x]++;
    }
   ll ans=1LL*n*(n-1)/2;
   priority_queue<pair<int,int>> pq;
   for(auto i:m)
    {if(i.second>1)
    	{pq.push(make_pair(i.second,i.first));
      	 ans-=1LL*i.second*(i.second-1)/2;
        }
    }
   for(int i=0;i<k;i++)
    {if(pq.empty())
      break;
     
     auto it=pq.top();
     pq.pop();
     it.first--;
     ans+=it.first;

     if(it.first>1)
      pq.push(it);
    }
   cout<<ans<<'\n';
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}