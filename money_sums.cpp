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
	vi arr(n);
	rep(i,0,n)cin>>arr[i];
	int s = accumulate(all(arr),0);
	bool dp[n+1][s+1];
	memset(dp,false,sizeof(dp));
	dp[0][0] = true;
	rep(i,1,n+1){
		rep(j,0,s+1){
			if (j == 0)dp[i][j] = true;
			else{
				dp[i][j] = dp[i-1][j];
				if (j>=arr[i-1])dp[i][j] = dp[i][j] || dp[i-1][j-arr[i-1]];
			}
		}
	}
	vector<int>ans;
	rep(i,1,s+1)if (dp[n][i])ans.pb(i);
	cout<<sz(ans)<<endl;
	rep(i,0,sz(ans))cout<<ans[i]<<" ";
}