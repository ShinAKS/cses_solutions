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
	map<ll,ll>mp;
	mp[0]++;
	int n;
	cin>>n;
	vi arr(n);
	rep(i,0,n)cin>>arr[i];
	ll s= 0;
	ll count = 0;
	rep(i,0,n){
		s=((s+arr[i])%n+n)%n;
		mp[s]++;
	}
	for (auto x: mp){
		count+=(x.second*(x.second-1))/2;
	}
	
	cout<<count<<endl;
	return 0;
}