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
	int n;
	cin>>n;
	vi dp(n+1,INT_MAX);
	dp[0] = 0;
	for (int i=1;i<=n;i++){
		vi digits;
		int temp  = i;
		while (temp>0){
			digits.pb(temp%10);
			temp/=10;
		}
		rep(j,0,sz(digits)){
			if (digits[j]==0)continue;
			dp[i] = min(dp[i],1+dp[i-digits[j]]);
		}
	}
	cout<<dp[n]<<endl;
}