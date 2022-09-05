#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout() for(auto x:arr)cout<<x<<' ';
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)

void solve()
  {int n;
   cin>>n;
   string st;
   cin>>st;

   int al[26],cnt=0;
   vector<int> rec;
   memset(al,0,sizeof(al));
   ll ans=0;

   rep(i,0,st.size())
    {int ch=st[i]-'a';
     if(rec.empty() || (al[ch]==0 && rec[0]!=ch))
      {cnt++;
       rec.push_back(ch);
      }
     int prev=al[ch];
     al[ch]=i;
     int l=((prev==0 && rec[0]!=ch)?i-prev+1:i-prev);
     ans+=(1LL*((l-1)*l))/2;
    //  cout<<ans<<'\n';
    }

   for(auto x:rec)
    {int prev=al[x];
     int l=n-prev;
     ans+=(1LL*((l-1)*l))/2;
    }

   ll subo=(1LL*((n+1)*n))/2;
   subo*=cnt;
  //  cout<<"subo: "<<subo<<'\n';

   ans=subo-ans;

   cout<<ans<<'\n';
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}