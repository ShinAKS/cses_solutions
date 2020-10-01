#include <bits/stdc++.h>
#define ll          long long
#define int 		long long
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

int32_t main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	//insert code
	int n;
	cin>>n;
	int x;
	multiset<int>st;
	rep(i,0,n){
		cin>>x;
		st.insert(x);
		auto it = st.find(x);
		it++;
		if (it!=st.end())st.erase(it);
	}
//	for (auto p: st)cout<<p<<" ";
	cout<<sz(st)<<endl;
}