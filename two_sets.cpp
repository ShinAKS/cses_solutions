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
	ll val = (n*(n+1))/2;
	if (val%2)cout<<"NO"<<endl;
	else{
		cout<<"YES"<<endl;
		ll currsum = 0 , curr = 1;
		while (currsum<val/2){
			currsum += curr;
			curr++;
		}
		ll diff = currsum - val/2;
		vi l,r;
		rep(i,1,curr){
			if (i!=diff)l.pb(i);
		}
		if (diff!=0)r.pb(diff);
		rep(i,curr,n+1){
			r.pb(i);
		}
 
		cout<<sz(l)<<endl;
		rep(i,0,sz(l))cout<<l[i]<<" ";
		cout<<endl;
		cout<<sz(r)<<endl;
		rep(i,0,sz(r))cout<<r[i]<<" ";
	}
	return 0;
}