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
	int n;
	cin>>n;
	vi arr(n);
	rep(i,0,n)cin>>arr[i];
	sort(all(arr));
	vector<ll> pref(n);
	if (n == 1){
		cout<<2*arr[0]<<endl;
		return 0;
	}
	pref[0] = arr[0];
	for (int i=1;i<n;i++)pref[i] = arr[i] + pref[i-1];
	if (pref[n-2]<=arr[n-1]){
		cout<<2*arr[n-1]<<endl;
		return 0;
	}
	else{
		cout<<pref[n-1]<<endl;
		return 0;
	}
	return 0;
}