#include<bits/stdc++.h>
using namespace std;
#define int long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout() for(auto x:arr)cout<<x<<' ';
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)
#define vi vector<int>

int n;
string s;
int cost[100100];
int dp[100100][4];
int rec(int level,int state)        //returns the min cost required to rid string of subsequence "hard"
    {//pruning 
     
     //base case check
     if(level==n)
        return 0;
     //cache check
     if(dp[level][state]!=-1)
        return dp[level][state];
     //transition 
     int ans=1e9;
     if(state==0 && s[level]=='h')
        ans=min(rec(level+1,1),cost[level]+rec(level+1,0));

     else if(state==1 && s[level]=='a')
        ans=min(rec(level+1,2),rec(level+1,1)+cost[level]);

     else if(state==2 && s[level]=='r')
        ans=min(rec(level+1,3),rec(level+1,2)+cost[level]);

     else if(state==3 && s[level]=='d')
        ans=rec(level+1,3)+cost[level];

     else
        ans=rec(level+1,state);
     //save and return 
     return dp[level][state]=ans;
    }

void solve()
    {cin>>n;
     cin>>s;
     rep(i,0,n)
        cin>>cost[i];
     memset(dp,-1,sizeof(dp));
     cout<<rec(0,0)<<'\n';
    }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}