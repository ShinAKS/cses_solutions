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
	vii arr(n);
	rep(i,0,n){
		cin>>arr[i].ff;
		cin>>arr[i].ss;
	}
	sort(all(arr));
	ll val = 0;
	ll last= 0;
	rep(i,0,n){
		last += arr[i].ff;
		val += arr[i].ss-last;
	}
	cout<<val<<endl;
	
	return 0;
}