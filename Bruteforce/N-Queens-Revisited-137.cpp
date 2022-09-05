#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n;
vector<int> queens;
// vector<vector<int>> solns;
int ans=0;

bool check(int level,int col)
  {for(int prow=0;prow<level;prow++)
    {if(queens[prow]==col || abs(level-prow)==abs(col-queens[prow]) || abs(level-prow)+abs(col-queens[prow])==3)
      return 0;
    }
   return 1;
  }

void rec(int level)
  {if(level==n)
    {ans++;
    //  solns.push_back(queens);
    //  cout<<"Answer found: ";
    //  for(auto x:queens)
    //   cout<<x<<" ";
    //  cout<<'\n';
     return;
    }
   
   for(int col=0;col<n;col++)
    {if(check(level,col))
      {queens.push_back(col);
      //  cout<<"Level: "<<level<<" Col: "<<col<<'\n';
      //  cout<<"Queens cols: [ ";
      //  for(auto x:queens)
      //   cout<<x<<" ";
      //  cout<<"]"<<'\n';
       rec(level+1);
      //  cout<<"Col removed: "<<col<<" from Level: "<<level<<'\n';
       queens.pop_back();
      }
    }
  }

void solve()
  {cin>>n;

   rec(0);
   cout<<ans;
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 //int _t;cin>>_t;while(_t--)
 solve();
}