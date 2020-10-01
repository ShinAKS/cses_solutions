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

bool cmp(pii a,pii b){
	return a.ss<b.ss;
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	//insert code
	int n;
	cin>>n;
	vector<pii>v(n);
	rep(i,0,n){
		cin>>v[i].ff;
		cin>>v[i].ss;
	}
	sort(all(v),cmp);
	int ans = 1;
	int end = v[0].ss;
	for (int i =1;i<sz(v);i++){
		if (v[i].ff>=end){
			ans++;
			end = v[i].ss;
		}
	}
	cout<<ans<<endl;
	return 0;
}