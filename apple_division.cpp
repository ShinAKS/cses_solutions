#include <bits/stdc++.h>
 
#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
 
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	//insert code
	int n;
	cin>>n;
	vector<ll>arr(n);
	rep(i,0,n)cin>>arr[i];
	ll currmin = INT_MAX;
	rep(i,0,1<<n){
		ll left=0,right = 0;
		rep(j,0,n){
			if (i & (1<<j))left+=arr[j];
			else right+= arr[j];
		}
		currmin = min(currmin, abs(left-right));
	}
	cout<<currmin<<endl;
	return 0;
}