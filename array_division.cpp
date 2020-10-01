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

bool possible(ll mid,vector<ll>&arr,int n,int k){
	int count = 0;
	ll sm = 0;
	for (int i=0;i<n;i++){
		
		if (sm+arr[i]>mid){
			count++;
			sm = 0;
		}
		sm+=arr[i];
	}
	count++;
//	if (sm>mid)count++;
	if (count>k)return false;
	return true;
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	//insert code
	int n,k;
	cin>>n>>k;
	vector<ll> arr(n);
	rep(i,0,n)cin>>arr[i];
	ll start = *max_element(all(arr));
	ll end = 1e18;
	ll ans;
	while(start<=end){
		ll mid = (start+end)/2;
		if (possible(mid,arr,n,k)){
			ans = mid;
			end = mid-1;
		}
		else start = mid+1;
	}
	cout<<ans<<endl;
	return 0;
}