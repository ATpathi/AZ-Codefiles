#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout() for(auto x:arr)cout<<x<<' ';
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)
#define vi vector<int>

set<string>store;
void swappy(string s,int k)
  {if(k==0)
    {store.insert(s);
     return;
    }

   rep(i,0,(int)s.size())
    {rep(j,i,(int)s.size())
      {string scopy=s;
       int find=i,sind=j;
       while(find!=sind && find<sind)
        {swap(scopy[find],scopy[sind]);
         find++;
         sind--;
        }
       swappy(scopy,k-1);
      }
    }

  }
void solve()
  {string S,T;
   cin>>S>>T;
   
   set<string> store1,store2;
   
   swappy(S,2);
   store1=store;
   store.clear();
   swappy(T,2);
   store2=store;
   store.clear();

  //  for(auto x:store2)
  //   cout<<x<<"\n";

   for(auto x:store1)
    {auto it=store2.lower_bound(x);
     if(*it==x)
      {cout<<"YES\n";
       return;
      } 
    }
   
   cout<<"NO\n";
   return;
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}