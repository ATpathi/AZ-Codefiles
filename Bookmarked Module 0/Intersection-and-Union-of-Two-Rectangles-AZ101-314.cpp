#include<bits/stdc++.h>
using namespace std;

void solve()
   {int x1,y1,x2,y2,x3,y3,x4,y4,area;
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
    int cx1,cx2,cy1,cy2,uneon,inter=0;

    
    cx2=min(x2,x4);
    cy2=min(y2,y4);
    cx1=max(x1,x3);
    cy1=max(y1,y3);
    
    if(cx1<=cx2 && cy1<=cy2)
       inter=abs((cx1-cx2)*(cy1-cy2));
    
    uneon=abs((x1-x2)*(y1-y2))+abs((x3-x4)*(y3-y4))-inter;
      
    cout<<inter<<" "<<uneon<<endl;
   }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);
 int _t;cin>>_t;
 while(_t--)
 solve();
}