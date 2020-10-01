#include <bits/stdc++.h>
#define ll          long long
#define int 		long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define ff           first
#define ss           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;

int n,m;
int dp[501][501];

int solve(int n,int m){
	//write here
	if (n==m)return 0;
	if (dp[n][m]!=-1)return dp[n][m];
	int ans = INT_MAX;
	rep(i,1,n)
		ans = min(ans,1+solve(i,m) + solve(n-i,m));
	rep(i,1,m)
		ans = min(ans,1 + solve(n,i) + solve(n,m-i));
	return dp[n][m] = ans;
}

int32_t main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	//insert code
	memset(dp,-1,sizeof(dp));
	cin>>n>>m;
	cout<<solve(n,m)<<endl;
}