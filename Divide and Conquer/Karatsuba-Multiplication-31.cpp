#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define CUTOFF 32

vector<ll> karatsuba(vector<ll> &X,vector<ll> &Y)
   {int n=X.size();
    vector<ll> ans(2*n-1);

    if(n<=CUTOFF)
      {for(int i=0;i<n;i++)
         for(int j=0;j<n;j++)
            ans[i+j]+=X[i]*Y[j];
       return ans;
      }

    int k=n>>1;

    vector<ll> Xl(X.begin(),X.begin()+k);
    vector<ll> Yl(Y.begin(),Y.begin()+k);
    vector<ll> Xr(X.begin()+k,X.end());
    vector<ll> Yr(Y.begin()+k,Y.end());

    vector<ll> Zl=karatsuba(Xl,Yl);
    vector<ll> Zr=karatsuba(Xr,Yr);

    for(int i=0;i<(int)Xl.size();i++)
      Xl[i]+=Xr[i];
    for(int i=0;i<(int)Yl.size();i++)
      Yl[i]+=Yr[i];
      
    vector<ll> Zm=karatsuba(Xl,Yl);
    for(int i=0;i<(int)Zm.size();i++)
      Zm[i]-=(Zl[i]+Zr[i]);
      
    for(int i=0;i<Zl.size();i++)
      ans[i]+=Zl[i];
    for(int i=0;i<Zm.size();i++)
      ans[i+k]+=Zm[i];
    for(int i=0;i<Zr.size();i++)
      ans[i+n]+=Zr[i];
   

    return ans;
   }

void solve()
   {int n;
    cin>>n;
    vector<ll> X(n+1),Y(n+1);
    for(int i=0;i<n+1;i++)
      cin>>X[i];
    for(int i=0;i<n+1;i++)
      cin>>Y[i];
    
    //although it is guaranteed that n+1 is of the form 2^k, we do the following operation to make 
    //a generalised program to solve this problem even when n+1!=2^k
    //We do this so that Zl and Zr (and Zm) always have an equal number of elements of the order 2^m
    while((int)X.size()&(n-1))
      {X.emplace_back(0);
       Y.emplace_back(0);
      }

    vector<ll> ans=karatsuba(X,Y);
    ans.resize(2*n+1);
    for(auto i:ans)
      cout<<i<<" ";
    cout<<'\n';
   }
signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);
 
 int _t;cin>>_t;while(_t--)
 solve();
}