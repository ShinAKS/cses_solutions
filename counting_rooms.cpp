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

void dfs(int x,int y,int n,int m,vector<vector<char>>&v){
	if (x<0 || x >=n || y<0 || y>=m || v[x][y]=='#')return;
	v[x][y] = '#';
	dfs(x+1,y,n,m,v);
	dfs(x-1,y,n,m,v);
	dfs(x,y+1,n,m,v);
	dfs(x,y-1,n,m,v);
}

int32_t main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	//insert code
	int n,m;
	cin>>n>>m;
	vector<vector<char>>v(n,vector<char>(m));
	rep(i,0,n){
		rep(j,0,m)cin>>v[i][j];
	}
	int ans = 0;
	rep(i,0,n){
		rep(j,0,m){
			if (v[i][j]=='.'){
				ans++;
				dfs(i,j,n,m,v);
			}
		}
	}
	cout<<ans<<endl;
}