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

bool dfs(int s,vector<vi>&adj,vector<bool>&vis,vi &color,int par){
	if (par == -1)color[s] = 0;
	else color[s] = 1 - color[par];
	vis[s] = true;
	rep(i,0,sz(adj[s])){
		if (adj[s][i] == par)continue;
		if (vis[adj[s][i]]){
			if (color[adj[s][i]] == color[s])return false;
			else continue;
		}
		else{
			if (!dfs(adj[s][i],adj,vis,color,s))return false;
		}
	}
	//write here
	return true;
}

int32_t main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	//insert code
	int n,m;
	cin>>n>>m;
	vector<vector<int>>adj(n);
	vector<bool>vis(n,false);
	vector<int>color(n,-1);
	int u,v;
	rep(i,0,m){
		cin>>u>>v;
		u--;v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	rep(i,0,n){
		if (!vis[i]){
			if (!dfs(i,adj,vis,color,-1)){
				cout<<"IMPOSSIBLE"<<endl;
				return 0;
			}
		}
	}
	rep(i,0,n)cout<<color[i]+1<<" ";
	return 0;
}