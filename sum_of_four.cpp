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
	int n,x;
	map<ll,pair<int,int>>mp;
	cin>>n>>x;
	vi arr(n);
	rep(i,0,n)cin>>arr[i];
	
	rep(i,0,n-1){
		rep(j,i+1,n){
			if (mp.find(x-arr[i]-arr[j])!=mp.end()){
				cout<<i+1<<" "<<j+1<<" "<<mp[x-arr[i]-arr[j]].first+1<<" "<<mp[x-arr[i]-arr[j]].second+1<<endl;
				return 0;
			}
		}
		rep(j,0,i){
			mp[arr[i]+arr[j]] = make_pair(j,i);
		}
		
	}
	cout<<"IMPOSSIBLE"<<endl;
	return 0;
}