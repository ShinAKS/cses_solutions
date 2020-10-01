#include <bits/stdc++.h>
#define ll          long long
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

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	//insert code
	ll n;
	cin>>n;
	vector<ll>dp(n+1,0);
	dp[0] = 1;
	
	for (ll i=1;i<=n;i++){
		for (ll j=1;j<=6;j++){
			if (i>=j)dp[i] = (dp[i-j]%hell+dp[i]%hell)%hell;
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}