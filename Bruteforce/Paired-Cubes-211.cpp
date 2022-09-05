#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int N=1e6+10;
int sp[N];

void smallest_prime()
  {for(int i=0;i<N;i++)
    sp[i]=i;

   for(int i=2;i*i<=N;i++)
    {if(sp[i]==i)
      {for(int j=i*i;j<=N;j+=i)
        {if(sp[j]==j)
          sp[j]=i;
        }
      }
    }
  }
map<int,int> prime_facto(int x)
  {map<int,int> ans;

   while(x>1)
    {ans[sp[x]]++;
     if(ans[sp[x]]==3) 
      ans.erase(sp[x]);
     x/=sp[x];
    }
   if(ans.empty())
    ans[1]=0;

   return ans;
  }
void solve()
  {int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++)
    cin>>arr[i];
   
   int ans=0;
   map<map<int,int>,int> directory;
   for(int i=0;i<n;i++)
    {map<int,int> fact=prime_facto(arr[i]);
     
     map<int,int> tar;
     for(auto i:fact)
      {if(i.second!=3)
        tar[i.first]=(3-i.second)%3;
      }

     ans+=directory[tar];
     directory[fact]++;
    }

   cout<<ans;
  }
signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 smallest_prime();
 solve();
//  map<int,int> answ=prime_facto(125);
//  for(auto i:answ)
//   cout<<i.first<<":"<<i.second<<'\n';
}