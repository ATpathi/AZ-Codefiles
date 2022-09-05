#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout(arr) for(auto x:arr)cout<<x<<' ';
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)
#define vi vector<int>

void solve()
   {int n;
    cin>>n;
    string s;
    cin>>s;

    vector<int> rec;
    int plast[26],last[26],ans=0;
    rep(i,0,26)
      last[i]=-1;

    rep(i,0,n)
      {int ch=s[i]-'a';
       if(last[ch]!=-1)
         ans+=(i-last[ch])*(last[ch]-plast[ch]);
       else
         rec.push_back(ch);
       plast[ch]=last[ch];
       last[ch]=i;     
      }

    for(auto x:rec)
      ans+=(n-last[x])*(last[x]-plast[x]);

    cout<<ans<<'\n';
   }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}