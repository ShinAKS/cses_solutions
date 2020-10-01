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

multiset<int>larger;
multiset<int>smaller;

void balance(){
	//write here
	if (abs(sz(smaller)- sz(larger))<=1)return;
	if (sz(smaller)>sz(larger)){
		int shift = *(smaller.rbegin());
		smaller.erase(smaller.lower_bound(shift));
		larger.insert(shift);
	}
	else{
		int shift = *(larger.begin());
		larger.erase(larger.lower_bound(shift));
		smaller.insert(shift);
	}
	
}

int32_t main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	//insert code
	int n,k;
	cin>>n>>k;
	vi arr(n);
	rep(i,0,n)cin>>arr[i];
	int median ;
	rep(i,0,k){
		if (smaller.empty()){
			smaller.insert(arr[i]);
		}
		else{
			if (arr[i]<=median)smaller.insert(arr[i]);
			else larger.insert(arr[i]);
			balance();
		}
		//cout<<*(smaller.end())<<endl;
		//exit(0);
		if (sz(larger)>sz(smaller))median = *(larger.begin());
		else median = *(smaller.rbegin());
	}

	rep(i,k,n){
		cout<<median<<" ";
		if (smaller.find(arr[i-k])!=smaller.end()){
			smaller.erase(smaller.lower_bound(arr[i-k]));
		}
		else{
			larger.erase(larger.lower_bound(arr[i-k]));
		}
		if (arr[i]<=median)smaller.insert(arr[i]);
		else larger.insert(arr[i]);
		balance();
		if (sz(larger)>sz(smaller))median = *(larger.begin());
		else median = *(smaller.rbegin());
	}
	cout<<median<<endl;
}