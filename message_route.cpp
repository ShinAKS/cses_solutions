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
	int n,m;
	cin>>n>>m;
	vector<vi>adj(n+1);
	vector<bool>vis(n+1,false);
	vector<int>from(n+1);
	int u,v;
	rep(i,0,m){
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	queue<int>q;
	q.push(1);
	while (!q.empty()){
		int t = q.front();
		q.pop();
		if (t == n)break;
		for (int i =0 ;i <adj[t].size();i++){
			int x = adj[t][i];
			if (vis[x])continue;
			vis[x] = true;
			from[x] = t;
			q.push(x);
		}
	}
	if (!vis[n]){
		cout<<"IMPOSSIBLE"<<endl;
		return 0;
	}
	vector<int>arr;
	int end = n;
	while (end!=1){
		arr.pb(end);
		end = from[end];
	}
	arr.pb(1);
	reverse(all(arr));
	cout<<sz(arr)<<endl;
	rep(i,0,sz(arr))cout<<arr[i]<<" ";
	return 0;
}