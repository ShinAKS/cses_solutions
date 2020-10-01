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
	stack<int>st;
	int n;
	cin>>n;
	vi arr(n);
	rep(i,0,n)cin>>arr[i];
	vi ans(n);
	cout<<0<<" ";
	st.push(0);
	rep(i,1,n){
		while (!st.empty() && arr[st.top()]>=arr[i])st.pop();
		if (st.empty()){
			cout<<0<<" ";
		}
		else{
			cout<<st.top()+1<<" ";
		}
		st.push(i);
	}
	return 0;
}