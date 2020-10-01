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
	int n,x;
	cin>>n>>x;
	vector<ll>dp(x+1,0);
	vi arr(n);
	vi pages(n);
	rep(i,0,n)cin>>arr[i];
	rep(i,0,n)cin>>pages[i];
	rep(i,0,n){
		for (int j = x;j>=arr[i];j--){
			dp[j] = max(dp[j],dp[j-arr[i]]+pages[i]);
		}
	}
	cout<<dp[x]<<endl;
	return 0;
}