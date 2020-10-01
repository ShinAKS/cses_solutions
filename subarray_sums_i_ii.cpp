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
	int n,k;
	cin>>n>>k;
	map<ll,ll>mp;
	vi arr(n);
	rep(i,0,n){
		cin>>arr[i];
	}
	mp[0] =1 ;
	ll sm = 0;
	ll count = 0;
	rep(i,0,n){
		sm+=arr[i];
		if (mp.find(sm-k)!=mp.end()){
			count+=mp[sm-k];
		}
		mp[sm]++;
	}
	cout<<count<<endl;
	return 0;
}