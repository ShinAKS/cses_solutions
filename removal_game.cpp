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

ll dp[5001][5001];
ll arr[5001];

int solve(int start, int end){
	//write here
	if (start>end)return 0;
	if (dp[start][end]!=-1)return dp[start][end];
	ll ans = LONG_MIN;
	ans = max({ans,arr[start]+min(solve(start+2,end),solve(start+1,end-1)),arr[end]+min(solve(start,end-2),solve(start+1,end-1))});
	return dp[start][end] = ans;
	//return;
}

int32_t main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	//insert code
	memset(dp,-1,sizeof(dp));
	int n;
	cin>>n;
	rep(i,0,n)cin>>arr[i];
	cout<<solve(0,n-1)<<endl;
	return 0;
}