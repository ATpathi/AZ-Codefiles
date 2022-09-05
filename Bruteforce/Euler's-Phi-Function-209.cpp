#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=1e7+10;
bool is_prime[N];

void sieve_of_eratosthenes()
  {for(int i=2;i<N;i++)
    is_prime[i]=1;

   for(int i=2;i<N;i++)
    {if(is_prime[i])
      {for(int j=i*i;j<N;j+=i)
        is_prime[j]=0;
      }
    }    
  }
void solve()
  {int n;
   cin>>n;
   int phi=n,no=n;

   for(int i=2;i*i<=no;i++)
    {if(is_prime[i])
      {if(!(n%i))
        {phi-=phi/i;
         n/=i;
        }
       while(!(n%i))
        n/=i;
      }
    }

    if(n!=1)
      phi-=phi/n;

   cout<<phi;
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 sieve_of_eratosthenes();
 solve();
}