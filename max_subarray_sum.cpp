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
	vector<ll> arr(n);
	rep(i,0,n){
		cin>>arr[i];	
	}
	ll currbest = INT_MIN;
	ll currval = -99999999;
	rep(i,0,n){
		currval = max(currval+arr[i],arr[i]);
		currbest = max(currbest,currval);
	}
	cout<<currbest<<endl;
	return 0;
}