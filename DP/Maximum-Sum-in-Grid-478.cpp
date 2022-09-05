#include<bits/stdc++.h>
using namespace std;
#define int long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout() for(auto x:arr)cout<<x<<' ';
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)
#define vi vector<int>

void solve()
	{int n,m;
	 cin>>n>>m;
	 int grid[n][m];
	 rep(i,0,n)
	 	rep(j,0,m)
		 	cin>>grid[i][j];
	 
	 int temp[n],max_sum=-1000000;
	 if(n>=m)
		{for(int l=0;l<m;l++)
			{for(int r=l;r<m;r++)
				{rep(i,0,n)
					{temp[i]=0;
					 rep(k,l,r+1)
						temp[i]+=grid[i][k];
					}
				 int sum=0;
				 max_sum=max(max_sum,temp[0]);
				 if(temp[0]>0)
				 	sum=temp[0];
				 else
				 	sum=0;
				 rep(i,1,n)
				 	{if(sum+temp[i]>0)
					 	{sum+=temp[i];
						 max_sum=max(sum,max_sum);
						}
					 else
					 	{sum=0;
						 max_sum=max(temp[i],max_sum);
						}
					}
				}
			}
		}
	 else
	 	{for(int u=0;u<n;u++)
			{for(int d=u;d<n;d++)
				{rep(i,0,m)
					{temp[i]=0;
					 rep(k,u,d+1)
						temp[i]+=grid[k][i];
					}

				 max_sum=max(max_sum,temp[0]);
				 int sum;
                 if(temp[0]>0)
                	sum=temp[0];
                 else
                    sum=0;
				 rep(i,1,m)
				 	{if(sum+temp[i]>0)
					 	{sum+=temp[i];
						 max_sum=max(sum,max_sum);
						}
					 else
					 	{sum=0;
						 max_sum=max(temp[i],max_sum);
						}
					}
				}
			}
		}
	 cout<<max_sum<<'\n';
	}

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}