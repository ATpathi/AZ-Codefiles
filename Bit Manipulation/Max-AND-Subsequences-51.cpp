#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
   {int N,X;
    cin>>N>>X;
    vector<int> arr(N);
    for(int i=0;i<N;i++)
      cin>>arr[i];

    int ans=0;
    for(int i=29;i>=0;i--)
      {vector<int> setElemBit;
       
       for(int j=0;j<(int)arr.size();j++)
         {if(arr[j]&(1<<i))
            setElemBit.push_back(arr[j]);
         }

       if(setElemBit.size()>=X)
         {ans+=(1<<i);
          arr=setElemBit;
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