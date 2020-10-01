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

bool possible(vector<ll> &arr,ll k,ll mid){
	ll s = 0;
	for (int i=0;i<sz(arr);i++){
		s+=mid/arr[i];
	//	cout<<k<<endl;
		if (s>=k)return true;
	}
	return false;
}
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	//insert code
	ll n,k;
	cin>>n>>k;
	vector<ll> arr(n);
	rep(i,0,n)cin>>arr[i];
	sort(all(arr));
	ll start =1,end = 1e18;
	ll ans;
	while (start<=end){
		ll mid = (start+end)/2;
		if (possible(arr,k,mid)){
			ans = mid;
			end = mid-1;
		}
		else start = mid+1;
	}
	cout<<ans<<endl;
	return 0;
}