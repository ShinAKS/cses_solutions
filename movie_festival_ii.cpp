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
	int n,k;
	cin>>n>>k;
	multiset<int,greater<int>>st;
	vii arr(n);
	rep(i,0,n)cin>>arr[i].ss>>arr[i].ff;
	sort(all(arr));
	ll ans = 0;
	rep(i,0,n){
		if (st.empty()){
			st.insert(arr[i].ff);
			ans++;
			k--;
		}
		else{
			auto it = st.lower_bound(arr[i].ss);
			if (it == st.end()){
				if (k>0){
					k--;
					ans++;
					st.insert(arr[i].ff);
				}
			}
			else{
				st.erase(it);
				st.insert(arr[i].ff);
				ans++;
			}
		}
	}
	cout<<ans<<endl;
}