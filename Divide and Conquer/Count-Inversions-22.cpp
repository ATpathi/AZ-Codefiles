#include<bits/stdc++.h>
using namespace std;

long long inv;

void merge(int arr[],int l,int m,int r)
   {int lsz=m-l+1;
    int rsz=r-m;

    int larr[lsz],rarr[rsz];     //temp arrays that store values

    for(int i=0;i<lsz;i++)
      larr[i]=arr[l+i];
    for(int i=0;i<rsz;i++)
      rarr[i]=arr[m+i+1];

    int i=0,j=0,k=l;  //pointers for larr and rarr respectively
    
    while(i<lsz && j<rsz)
      {if(larr[i]<=rarr[j])
         arr[k++]=larr[i++];
       else
         {arr[k++]=rarr[j++];
          inv+=lsz-i;
         }
      }
    while(i<lsz)
      arr[k++]=larr[i++];
    while(j<rsz)
      arr[k++]=rarr[j++];
   }

void msort(int arr[],int l,int r)
   {if(l>=r)
      return;
    
    int m=l+(r-l)/2;
    msort(arr,l,m);
    msort(arr,m+1,r);
    merge(arr,l,m,r);
   }

void solve()
   {int sz;
    cin>>sz;
    int arr[sz];
    for(int i=0;i<sz;i++)
      cin>>arr[i];
    msort(arr,0,sz-1);

    cout<<inv<<"\n";
   }
signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);
 
 int _t;cin>>_t;while(_t--)
 {solve();
  inv=0;
 }
}