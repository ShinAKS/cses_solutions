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
	vector<vii>adj(n+1);
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
	vector<ll>dist(n+1,LONG_MAX);
	vector<bool>vis(n+1,false);
	vii from(n+1);
	int u,v,w;
	rep(i,0,m){
		cin>>u>>v>>w;
		adj[u].pb({v,w});
	}
	//vis[1] = true;
	pq.push(make_pair(0,1));
	dist[1] = 0;
	while (!pq.empty()){
		pair<ll,ll> t = pq.top();
		pq.pop();
		int v = t.ss;
		if (vis[v])continue;
		vis[v] = true;
		if (v == n)break;
		ll price = dist[v];
		rep(i,0,sz(adj[v])){
			int u = adj[v][i].ff;
			if (dist[u] > price + adj[v][i].ss){
				dist[u] = price + adj[v][i].ss;
				from[u] = {v,adj[v][i].ss};
				pq.push({dist[u],u});
			}
		}
	}
	int mxval = 0;
	int start = n;
	while (start!=1){
		pii p = from[start];
		start = p.ff;
		mxval = max(mxval,p.ss);
	}
	cout<<dist[n]-mxval + mxval/2<<endl;
	return 0;
}