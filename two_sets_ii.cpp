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

const int P = (500*501)/2+1;
ll dp[501][P];

int32_t main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	//insert code
	int n;
	cin>>n;
	ll s = (n*(n+1))/2;
	if (s%2){
		cout<<0<<endl;
		return 0;
	}
	memset(dp,0,sizeof(dp));
	dp[0][0] = 1;
	rep(i,1,n+1){
		rep(j,0,s/2+1){
			if (j == 0)dp[i][j] = 1;
			else{
				dp[i][j] = dp[i-1][j];
				if (j>=i-1)dp[i][j] = (dp[i][j]+dp[i-1][j-i+1])%hell;
			}
		}
	}	
	/*
	rep(i,0,n+1){
		rep(j,0,s/2+1)cout<<dp[i][j]<<" ";
		cout<<endl;
	}
	*/
	cout<<dp[n][s/2]<<endl;
}