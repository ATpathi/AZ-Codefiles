#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout() for(auto x:arr)cout<<x<<' ';
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)
int n;
string ans="";
void dfs(int curr,int op)
  {if(curr==n)
    {ans+=")";
     cout<<ans<<'\n';
     ans.pop_back();
    //  cout<<"curr: "<<curr<<" op: "<<op<<" ans: "<<ans<<'\n';
     return;
    }

   if(!op)
    {ans+="(";
    //  cout<<"op=0:curr: "<<curr<<" op: "<<op<<" ans: "<<ans<<'\n';
     dfs(curr+1,op+1);
     ans.pop_back();
    //  cout<<"op=0:curr: "<<curr<<" op: "<<op<<" ans: "<<ans<<'\n';
    }
   else
    {int rem=n-curr+1;
     if(rem>op)
      {ans+="(";
      //  cout<<"rem>op:curr: "<<curr<<" op: "<<op<<" ans: "<<ans<<'\n';
       dfs(curr+1,op+1);
       ans.pop_back();
      //  cout<<"rem>op:curr: "<<curr<<" op: "<<op<<" ans: "<<ans<<'\n';
      }
     ans+=")";
    //  cout<<"curr: "<<curr<<" op: "<<op<<" ans: "<<ans<<'\n';
     dfs(curr+1,op-1);
     ans.pop_back();
    //  cout<<"curr: "<<curr<<" op: "<<op<<" ans: "<<ans<<'\n';
    }
  }
void solve()
  {cin>>n;

   dfs(1,0);
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 //int _t;cin>>_t;while(_t--)
 solve();
}