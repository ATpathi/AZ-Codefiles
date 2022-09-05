#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define arrin(n,arr) for(int i=0;i<n;i++)cin>>arr[i];
#define arrout() for(auto x:arr)cout<<x<<' ';
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>b;i--)
#define vi vector<int>
int MOD=1e9+7;

int binary_exp(int a,int p)
	{int ans=1;
	 while(p)
		 {if(p%2)
			  ans=(1LL*ans*a)%MOD;
		  a=(1LL*a*a)%MOD;
		  p/=2;
		 }
	 return ans;
	}
/*All the inline functions are written with the assumption that the arguments
passed will in the range [0,MOD-1]*/
/*An inline function must preferably be written with void return type as
otherwise the compiler might ignore it*/
inline void add(int &a,int b)
	{a+=b;
	 if(a>=MOD)
		 a-=MOD;
	}
inline void sub(int &a,int b)
	{a-=b;
	 if(a<0)
		 a+=MOD;
	}
inline void mul(int &a,int b)
	{a=(int)((1LL*a*b)%MOD);
	}
inline void divi(int &a,int b)
	{a=(int)((1LL*a*(binary_exp(b,MOD-2)))%MOD);
	}
// const int N=1e6+1;
// int facto[N];
// void factorial()
//     {facto[0]=1;
//      for(int i=1;i<=N;i++)
//         {int ans=facto[i-1];
//          mul(ans,i);
//          facto[i]=ans;
//         }
//     }


int n,m;
int grid[205][205];
int dp[205][205][405];

int rec(int x,int y,int kleft)
	{//pruning
	 if(x>=n || y>=m || kleft<0)
	 	return 0;
	 //base case 
	 if(x==n-1 && y==m-1)
	 	return 1;
	 //cache check
	 if(dp[x][y][kleft]!=-1)
	 	return dp[x][y][kleft];
	 //transition
	 int ans=0;
	 if(grid[x+1][y])
	 	add(ans,rec(x+1,y,kleft-1));
	 else
		add(ans,rec(x+1,y,kleft));

	 if(grid[x][y+1])
	 	add(ans,rec(x,y+1,kleft-1));
	 else
		add(ans,rec(x,y+1,kleft));
	 //save and return
	 return dp[x][y][kleft]=ans;
	}

void solve()
	{int k;
	 cin>>n>>m>>k;
	 rep(i,0,n)
	 	rep(j,0,m)
		 	{cin>>grid[i][j];
			 rep(a,0,k+1)
			 	dp[i][j][a]=-1;
			}

	 if(grid[0][0])
	 	cout<<rec(0,0,k-1)<<'\n';
	 else
	    cout<<rec(0,0,k)<<'\n';
	}

signed main()
{ios_base::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);

 int _t;cin>>_t;while(_t--)
 solve();
}