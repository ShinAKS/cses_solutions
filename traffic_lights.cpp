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
	set<int>st;
	multiset<int,greater<int>>mst;
	int n,k;
	cin>>n>>k;
	st.insert(0);
	st.insert(n);
	int x;
	set<int>::iterator it1;
	set<int>::iterator it2;
	multiset<int,greater<int>>::iterator it3;
	while (k--){
		cin>>x;
		it1 = st.lower_bound(x);
		it2 = st.upper_bound(x);
		if (*it1>x)it1--;
		if (*it2<=x)it2++;
		int val = *it2 - *it1;
		if (mst.empty()){
			mst.insert(x-*it1);
			mst.insert(*it2-x);
		}

		else{
			it3 = mst.find(val);
			mst.erase(it3);
			mst.insert(x-*it1);
			mst.insert(*it2-x);
			
		}
		it3 = mst.begin();
		cout<<*it3<<" ";
		st.insert(x);
	}
	return 0;
}