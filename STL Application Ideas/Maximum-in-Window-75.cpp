#include<bits/stdc++.h>
using namespace std;

void solve()
  {int n,k;
   cin>>n>>k;
   int a[n];

   for(int i=0;i<n;i++)
    cin>>a[i];

   deque<int> d;

  //An element is inserted in d iff a[d.back()]<a[i]
  /*This loop runs from 0 to k-2 and the other one runs from k-1 to n-1, this has to be done because
    the operation of printing a[d.front()] is not required in this loop*/
   for(int i=0;i<k-1;i++)
    {while(!d.empty() && a[d.back()]<=a[i])
      d.pop_back();
     d.push_back(i);
    }

   for(int i=k-1;i<n;i++)
    {//Check whether d.front() is still part of the window, if not, it must be removed from d
     if(i-d.front()>=k)
      d.pop_front();

     while(!d.empty() && a[d.back()]<=a[i])
      d.pop_back();
     d.push_back(i);

     cout<<a[d.front()]<<" ";
    }
   cout<<'\n';
  }

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}