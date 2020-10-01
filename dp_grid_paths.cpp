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


int32_t main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	//insert code
	int n;
	cin>>n;
	vector<vector<char>>v(n,vector<char>(n));
	rep(i,0,n)rep(j,0,n)cin>>v[i][j];
	if (v[0][0]=='*'){
		cout<<0<<endl;
		return 0;
	}
	vector<vector<ll>>dp(n,vector<ll>(n,0));
	dp[0][0] = 1;
	rep(i,1,n){
		if (dp[0][i-1]==0)dp[0][i] = 0;
		else if (v[0][i] == '*')dp[0][i] = 0;
		else dp[0][i] = 1;
	}
	rep(i,1,n){
		if (dp[i-1][0]==0)dp[i][0] = 0;
		else if (v[i][0]=='*')dp[i][0] = 0;
		else dp[i][0] = 1;
	}
	rep(i,1,n){
		rep(j,1,n){
			if (v[i][j] == '*')dp[i][j] = 0;
			else{
				dp[i][j] = (dp[i][j]+dp[i-1][j]+dp[i][j-1])%hell;
			}
		}
	}
	
	cout<<dp[n-1][n-1]<<endl;
	
	return 0;
}