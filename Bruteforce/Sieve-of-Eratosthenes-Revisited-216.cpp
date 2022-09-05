#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=1e7+10;
bool is_prime[N];

void sieve_of_eratosthenes(int r)
  {for(int i=2;i*i<=r;i++)
    is_prime[i]=1;

   for(int i=2;i<N;i++)
    {if(is_prime[i])
      {for(int j=i*i;j<N;j+=i)
        is_prime[j]=0;
      }
    }    
  }
void solve()
  {int l,r;
   cin>>l>>r;
   sieve_of_eratosthenes(r);
   
   bool a2b[r-l+1];
   memset(a2b,1,sizeof(a2b));

   for(int i=2;i*i<=r;i++)
    {if(is_prime[i])
      {int curMul=((l+i-1)/i)*i;
       
       for(;curMul<=r;curMul+=i)
        if(curMul!=i)
          a2b[curMul-l]=0;
      }
    }
   
   int count=0;
   vector<int> primes;
    for(int i=0;i<r-l+1;i++)
      if(a2b[i] && i+l!=1)
        {count++;
         primes.push_back(i+l);
        }

    cout<<count<<'\n';
    for(auto i:primes)
      cout<<i<<" ";
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 solve();
}