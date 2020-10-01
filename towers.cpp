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
	multiset<int>st;
	int k;
	
	cin>>k;
	int x;
	multiset<int>::iterator it;
	int cnt = 0;
	rep(i,0,k){
		cin>>x;
		if (st.empty()){
			cnt++;
			st.insert(x);
			continue;
		}
		it = st.upper_bound(x);
		if (it==st.end()){
			cnt++;
			st.insert(x);
		}
		else if (x>=*it){
			cnt++;
			st.insert(x);
		}
		else{
			st.erase(it);
			st.insert(x);
		}
		
 
	}
	
	cout<<cnt<<endl;
	return 0;
}