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

const int maxN = 501;

int32_t main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	//insert code
	vector<vector<ll>>dist(maxN,vector<ll>(maxN,LONG_MAX));
	int n,m,q;
	cin>>n>>m>>q;
	int u,v,w;
	rep(i,0,m){
		cin>>u>>v>>w;
		dist[u][v] = min(dist[u][v],w);
		dist[v][u] = min(dist[u][v],w);
	}
	rep(i,1,n+1)dist[i][i] = 0;
/*	rep(i,1,n+1){
		rep(j,1,n+1)cout<<(dist[i][j] == LONG_MAX?-1:dist[i][j])<<"     ";
		cout<<endl;
	}*/
	//cout<<endl;
	rep(k,1,n+1){
		rep(i,1,n+1){
			rep(j,1,n+1){
				if (dist[i][k]!=LONG_MAX && dist[k][j]!=LONG_MAX)
					dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	rep(i,0,q){
		cin>>u>>v;
		cout<<(dist[u][v]==LONG_MAX?-1:dist[u][v])<<endl;
	}
	return 0;
}