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
	string s,t;
	cin>>s>>t;
	int n = s.size();
	int m = t.size();
	int dp[n+1][m+1];
	rep(i,0,n+1){
		rep(j,0,m+1){
			if (i==0)dp[i][j] = j;
			else if (j == 0)dp[i][j] = i;
			else{
				if (s[i-1]==t[j-1])dp[i][j] = dp[i-1][j-1];
				else
					dp[i][j] = 1+ min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
			}
		}
	}
	cout<<dp[n][m]<<endl;
	return 0;
}