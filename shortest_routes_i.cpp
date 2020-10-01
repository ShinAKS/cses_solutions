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
	vector<ll>dist(n,LONG_MAX);
	vector<vii>adj(n);
	vector<bool>vis(n,false);
	int u,v,w;
	rep(i,0,m){
		cin>>u>>v>>w;
		u--;v--;
		adj[u].pb({v,w});
	}
	dist[0] = 0;
	priority_queue<pii,vector<pii>,greater<pii>>pq;
	pq.push({0,0});
	while(!pq.empty()){
		pii t = pq.top();
		pq.pop();
		if (vis[t.ss])continue;
		vis[t.ss] = true;
		for (pii v: adj[t.ss]){
			if (dist[v.ff]>dist[t.ss]+v.ss){
				dist[v.ff] = dist[t.ss] + v.ss;
				pq.push({dist[v.ff],v.ff});
			}
		}
	}
	rep(i,0,n)cout<<dist[i]<<" ";
	return 0;
}