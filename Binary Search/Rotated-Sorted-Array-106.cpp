#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=1e6+10;
int arr[N];

int F0(int i)
	{return (arr[i]>=arr[1]);
	}

void solve()
	{int n;
	 cin>>n;
	 
	 for(int i=1;i<=n;i++)
		cin>>arr[i];

	 int max=0,lo=1,hi=n;
	 while(lo<=hi)
	 	{int mid=lo+(hi-lo)/2;
		 if(F0(mid)==1)
		 	{max=mid;
			//  cout<<max<<" ";
			 lo=mid+1;
			}
		 else
		 	hi=mid-1;
		}
	//  cout<<'\n';
	 if(max!=n)
	 	cout<<max<<'\n';
	 else
	 	cout<<0<<'\n';
	}

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);
 arr[0]=-1e9-10;
 int _t;cin>>_t;while(_t--)
 solve();
}