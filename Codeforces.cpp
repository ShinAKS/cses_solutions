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

int mxN = 2e5;



int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	//insert code
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		//if (n==1){
		//	cout<<0<<endl;
		//	continue;
		//}
		vector<int>count(n+1,0);
		int distinct = 0;
		int p;
		rep(i,0,n){
			cin>>p;
			if (count[p]==0)distinct++;
			count[p]++;
		}
		int maxcount = 0;
		rep(i,0,n+1)maxcount=max(maxcount, count[i]);
		//cout<<maxcount<<" "<<distinct<<endl;
		if (maxcount>distinct){
			cout<<distinct<<endl;
			continue;
		}
		else if (maxcount == distinct){
			cout<<distinct-1<<endl;
			continue;
		}
		else {
			cout<<maxcount<<endl;
			continue;
		}
		
		
	}
	return 0;
}