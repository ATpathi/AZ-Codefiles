#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout(arr) for(auto x:arr)cout<<x<<' ';
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)
#define vi vector<int>

void solve()
  {string s,s1="ab",s2="ba";
   ll x,y; //x:ab y:ba
   cin>>s>>x>>y;
   
   if(y>x)
    {swap(x,y);
      
     string temp=s1;
     s1=s2;
     s2=temp;
    }

   ll ans=0;

   rep(i,0,(int)s.length()-1)
    {while(i<(int)s.length()-1 && s[i]==s1[0] && s[i+1]==s1[1])
      {s.erase(s.begin()+i,s.begin()+i+2);
       ans+=x;
       i--;
      }
    }
   rep(i,0,(int)s.length()-1)
    {while(i<(int)s.length()-1 && s[i]==s2[0] && s[i+1]==s2[1])
      {s.erase(s.begin()+i,s.begin()+i+2);
       ans+=y;
       i--;
      }
    }
   cout<<ans<<'\n';
  }


signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}