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
	ll n;
	cin>>n;
	vi arr(n);
	rep(i,0,n)cin>>arr[i];
	if (n == 1){
		cout<<0<<endl;
		return 0;
	}
	ll count =0;
	rep (i,1,n){
		if (arr[i]<arr[i-1]){
			count += abs(arr[i]-arr[i-1]);
			arr[i] = arr[i-1];
		}
	}
	cout<<count<<endl;
	return 0;
}