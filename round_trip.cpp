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

const int maxN = 1e5+1;
vector<int>adj[maxN];
bool vis[maxN];
int par[maxN];
int n,m; 

void dfs(int s,int parent){
	//write here
	vis[s] = true;
	par[s] = parent;
	for (int u: adj[s]){
		if (u == parent)continue;
		if (!vis[u]){
			dfs(u,s);
		}
		else{
			vi ans;
			int v = u;
			ans.pb(u);
			u = par[u];
			while (s!=u){
				ans.pb(s);
				s = par[s];
			}
			cout<<sz(ans)<<endl;
			rep(i,0,sz(ans))cout<<ans[i]<<" ";
			exit(0);
		}
	}
	return;
}

int32_t main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	//insert code
	memset(par,-1,sizeof(maxN));
	memset(vis,false,sizeof(maxN));
	cin>>n>>m;
	int u,v;
	rep(i,0,m){
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	rep(i,0,n){
		if (!vis[i])dfs(i,-1);
	}
	cout<<"IMPOSSIBLE"<<endl;
	return 0;
}