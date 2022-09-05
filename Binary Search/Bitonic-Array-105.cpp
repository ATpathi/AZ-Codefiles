#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=1e6+10;
int arr[N],X;

int F0(int i)
	{return (arr[i]>arr[i-1]);
	}
int F1(int i)
	{return (arr[i]<=X);
	}
int F2(int i)
	{return (arr[i]>=X);
	}

void solve()
	{int n,q;
	 cin>>n>>q;
	 
	 for(int i=1;i<=n;i++)
		cin>>arr[i];
	 

	 int max=0,lo=1,hi=n;
	 while(lo<=hi)
	 	{int mid=lo+(hi-lo)/2;
		 if(F0(mid)==1)
		 	{max=mid;
			 lo=mid+1;
			}
		 else
		 	hi=mid-1;
		}
	//  cout<<max;
	 for(int i=0;i<q;i++)
	 	{cin>>X;
		 vector<int> v;

		 int ans=0;
		 lo=1,hi=max;
		 while(lo<=hi)
	 		{int mid=lo+(hi-lo)/2;
		 		if(F1(mid)==1)
		 			{ans=mid;
			 		 lo=mid+1;
					}
		 		else
		 			hi=mid-1;
			}
	 	 if(ans!=0 && arr[ans]==X)
			v.push_back(ans);

		//  cout<<ans<<" ";

		 ans=0,lo=max+1,hi=n;
		 while(lo<=hi)
	 		{int mid=lo+(hi-lo)/2;
		 		if(F2(mid)==1)
		 			{ans=mid;
			 		 lo=mid+1;
					}
		 		else
		 			hi=mid-1;
			}
	 	 if(ans!=0 && arr[ans]==X)
			v.push_back(ans);
			
		//  cout<<ans<<" ";

		 for(auto j:v)
		 	cout<<j<<" ";
		 cout<<'\n';
		}
	}

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);
 arr[0]=-1e9-10;
 int _t;cin>>_t;while(_t--)
 solve();
}