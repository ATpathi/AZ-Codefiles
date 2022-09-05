#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout() for(auto x:arr)cout<<x<<' ';
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)
#define vi vector<int>
#define f first
#define s second

void solve()
  {int n;
   cin>>n;
   map<int,vector<pair<int,int>>> mp; //first integer: no on the no line pair's 1st integer: indicator->1:insert 2->remove 0:query
   rep(i,0,n)
    {int l,r,x;
     cin>>l>>r>>x;
     mp[l].push_back({1,x});
     mp[r+1].push_back({2,x});
    }
   int q; 
   cin>>q;
   rep(i,0,q)
    {int y,z;
     cin>>y>>z;
     mp[y].push_back({3+i,z});
    }
   
   int ans[q];
   multiset<int> ms;
   for(auto m:mp)
    {for(auto v:m.s)
      {if(v.f==1)
        ms.insert(v.s);
       else if(v.f==2)
        ms.erase(ms.find(v.s));
       else 
        {auto it=ms.upper_bound(v.s);
         if(it==ms.begin())
          ans[v.f-3]=-1;
         else
          {it--;
           ans[v.f-3]=*it;
          }
        }
      }
    }
   
   for(auto anso:ans)
    cout<<anso<<'\n';
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 //int _t;cin>>_t;while(_t--)
 solve();
}