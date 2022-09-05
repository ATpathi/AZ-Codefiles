#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout() for(auto x:arr)cout<<x<<' ';
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)
#define vi vector<int>

void solve()
  {string s;
   cin>>s;
   int n=s.length();
   int dp[n];
   rep(i,0,n)
    {dp[i]=0;
     
     if(s[i]=='(')
      continue;
     else
      {int j=i-1;
       bool found=0;
       do
        {if(dp[j])
          {if(found==1)
            dp[i]+=dp[j];
           j-=dp[j];
          }
         else if(s[j]=='(' && found==0)
          {j--;
           found=1;
           dp[i]=i-j;
          }
         else if((dp[j]==0 && s[j]==')') || (s[j]=='(' && found==1))
          break;
        } while (j>=0);
      }
    }
   
   int max=dp[0],count=1;

   rep(i,1,n)
    if(dp[i]>max)
      {max=dp[i];
       count=1;
      }
    else if(dp[i]==max)
      count++;

   if(max==0)
    count=1;

   cout<<max<<" "<<count<<'\n';
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}