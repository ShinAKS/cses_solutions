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
	sort(all(arr));
	vector<int>dp(target+1,0);
	dp[0] = 1;
	rep(i,0,n){
		rep(j,1,target+1){
			if(j>=arr[i]){
				dp[j] = (dp[j] + dp[j-arr[i]])%hell;
			}
		}
	}
	cout<<dp[target]<<endl;
	return 0;
}