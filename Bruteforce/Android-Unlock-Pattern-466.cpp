#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout() for(auto x:arr)cout<<x<<' ';
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)

int n,cnt=0;
vector<pair<int,int>> pat;
vector<pair<int,int>> ops;
int board[3][3];

bool check(int row,int col)
  {if(!pat.empty())
    {for(auto x:pat)
      {if(x.first==row && x.second==col)
        return 0;
      }
    }
   else
    return 1;

   int lrow=pat.back().first,lcol=pat.back().second;
   if(abs(lcol)+abs(lrow)==2)
    {if(abs(row)+abs(col)==1 || abs(row)+abs(col)==0)
      return 1;
     if(board[1][1] && (lcol==-col && lrow==-row))
      return 1;
     if((board[lrow+1][1] && row==lrow) || (board[1][lcol+1] && col==lcol))
      return 1;   
    }
   else if(abs(lcol)+abs(lrow)==1)
    {if(!(abs(lrow)==abs(row)) || !(abs(lcol)==abs(col)))
      return 1;
     if(board[1][1])
      return 1;
    }
   else if(lcol==0 && lrow==0)
    return 1;

   return 0;
  }

void droid(int dotc)
  {if(dotc==n)
    {cnt++;
     return;
    }
   
   for(auto x:ops)
    {if(check(x.first,x.second))
      {pat.push_back(x);
       board[x.first+1][x.second+1]=1;
       droid(dotc+1);
       board[x.first+1][x.second+1]=0;
       pat.pop_back();
      }
    }
  }

void solve()
  {cin>>n;
   memset(board,0,sizeof(board));
   droid(0);
   cout<<cnt;
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 rep(i,-1,2)
  rep(j,-1,2)
    ops.push_back(make_pair(i,j));

 //int _t;cin>>_t;while(_t--)
 solve();
}