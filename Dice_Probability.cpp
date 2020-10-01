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

// Most important thing in CP - Have Fun :)
int n,a,b;

void solve(){
	//write here
    cin>>n>>a>>b;
    vector<vector<double>>dp(n+1,vector<double>(6*(n+1),0));
    dp[0][0] = 1;
    for (ll i = 1 ; i<=n ; i++){
        for (ll j = i ; j<= 6*i ; j++){
            for (ll k = 1 ; k<=6 ;k++){
               if (j-k>=0) dp[i][j]+=dp[i-1][j-k];
            }
            dp[i][j]/=6;
        }
    }
    double num = 0;
    double den = 0;
    for (int i = a ; i<=b ; i++)num+=dp[n][i];
    cout<<fixed<<setprecision(6)<<num<<endl;
	return;
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	//insert code
		solve();
	return 0;
}