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

struct person{
	int time;
	int val;
	int index;
};

bool cmp(person a,person b){
	if (a.time == b.time)return a.val>b.val;
	return a.time<b.time;
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	//insert code
	int n;
	cin>>n;
	int a,b;
	vector<person> cus;
	rep(i,0,n){
		cin>>a>>b;
		cus.pb({a,1,i});
		cus.pb({b,-1,i});
	}
	sort(all(cus),cmp);
	int val = 0;
	vector<int>ans(n);
	int maxval = 0;
	priority_queue<int,vector<int>,greater<int>>pq;
	set<int>st;
	rep(i,0,sz(cus)){
		int prev = val;
		if (cus[i].val==1){
			if (pq.empty()){
				val++;
				ans[cus[i].index] = val;
			}
			else{
				ans[cus[i].index] = pq.top();
				pq.pop();
			}
		}
		else{
			pq.push(ans[cus[i].index]);
		}
		maxval = max(maxval,val);
	}
	cout<<maxval<<endl;
	rep(i,0,sz(ans))cout<<ans[i]<<" ";
	return 0;
}