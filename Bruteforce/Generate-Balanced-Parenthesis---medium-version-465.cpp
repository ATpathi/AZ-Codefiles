#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout() for(auto x:arr)cout<<x<<' ';
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)
int n,k;
string ans="";
void dfs(int curr,int op,int maxdep)
  {if(curr==n)
    {ans+=")";
     if(maxdep==k)
      cout<<ans<<'\n';
     ans.pop_back();
    //  cout<<"curr: "<<curr<<" op: "<<op<<" ans: "<<ans<<'\n';
     return;
    }

   if(!op)
    {ans+="(";
    //  cout<<"op=0:curr: "<<curr<<" op: "<<op<<" ans: "<<ans<<'\n';
     dfs(curr+1,op+1,max(op+1,maxdep));
     ans.pop_back();
    //  cout<<"op=0:curr: "<<curr<<" op: "<<op<<" ans: "<<ans<<'\n';
    }
   else
    {int rem=n-curr+1;
     if(rem>op && op<k)
      {ans+="(";
      //  cout<<"rem>op:curr: "<<curr<<" op: "<<op<<" ans: "<<ans<<'\n';
       dfs(curr+1,op+1,max(op+1,maxdep));
       ans.pop_back();
      //  cout<<"rem>op:curr: "<<curr<<" op: "<<op<<" ans: "<<ans<<'\n';
      }
     ans+=")";
    //  cout<<"curr: "<<curr<<" op: "<<op<<" ans: "<<ans<<'\n';
     dfs(curr+1,op-1,maxdep);
     ans.pop_back();
    //  cout<<"curr: "<<curr<<" op: "<<op<<" ans: "<<ans<<'\n';
    }
  }
void solve()
  {cin>>n>>k;

   dfs(1,0,0);
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 //int _t;cin>>_t;while(_t--)
 solve();
}