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
	int n,target;
	cin>>n>>target;
	vi arr(n);
	rep(i,0,n)cin>>arr[i];
	vector<ll>dp(target+1,INT_MAX);
	dp[0] = 0;
	rep(i,0,target+1){
		rep(j,0,n){
			if (i>=arr[j] && dp[i-arr[j]]!=INT_MAX)dp[i] = min(dp[i],1+dp[i-arr[j]]);
		}
	}
	cout<<(dp[target]==INT_MAX?-1:dp[target])<<endl;
	return 0;
}