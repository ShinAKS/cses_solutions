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

int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int n, target;
  cin >> n >> target;
  vector<int> arr(n);
  for (int i=0;i<n;i++)cin>>arr[i];

  vector<int> dp(target+1,0);
  dp[0] = 1;
  for (int i = 1; i <= target; i++) {
    for (int j = 0; j < n; j++) {
      if (i-arr[j] >= 0) {
		dp[i]= (dp[i-arr[j]] + dp[i])%hell;
      }
    }
  }
  cout << dp[target] << endl;
}