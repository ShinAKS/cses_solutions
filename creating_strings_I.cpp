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

set<string>st;

void process(string s, string temp, vector<bool>&vis, int n){
	if (temp.size() == n){
		st.insert(temp);
		return;
	}
	for (int i=0;i<sz(s);i++){
		if (!vis[i]){
			vis[i]=true;
			temp += s[i];
			process(s,temp,vis,n);
			temp.pop_back();
			vis[i] = false;
		}
	}
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	//insert code
	string s;
	cin>>s;
	vector<bool>vis(sz(s),false);
	process(s,"",vis,sz(s));
	
	set<string>::iterator it;
	cout<<st.size()<<endl;
	for (it = st.begin() ; it!= st.end() ; it++){
		cout<<*it<<endl;
	}
	return 0;
}