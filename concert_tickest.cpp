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
	int n,k;
	cin>>n>>k;
	multiset<int>m;
	multiset<int>::iterator it;
	int x;
	rep(i,0,n){
		cin>>x;
		m.insert(x);
	}
	while(k--){
		cin>>x;
		if (!m.empty())it = m.upper_bound(x);
		if (m.empty() || it == m.begin()){
			cout<<-1<<endl;
		}
		else{
			it--;
			cout<<*it<<endl;
			m.erase(it);
		}
	}
	return 0;
}