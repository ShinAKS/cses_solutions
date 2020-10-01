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

typedef pair<int,pair<int,int>> ipair;

char checkdir(int dx,int dy,int sx,int sy){
	if (dx == sx && dy==sy-1)return 'L';
	if (dx == sx && dy == sy+1)return 'R';
	if (dx == sx-1 && dy == sy)return 'U';
	if (dx == sx+1 && dy == sy)return 'D';
}

bool valid(int x,int y,int n,int m,vector<vector<char>>&arr,vector<vector<bool>>&vis){
	if (x<0 || x>=n || y<0 || y>=m || arr[x][y]== 'M' || arr[x][y] == '#' || vis[x][y])return false;
	return true;
}
void solve(){
	//write here
	int n,m;
	cin>>n>>m;
	priority_queue<ipair,vector<ipair>,greater<ipair>>pq;
	vector<vector<char>>arr(n,vector<char>(m));
	vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
	vector<vector<bool>>vis(n,vector<bool>(m,false));
	vector<vector<int>>distA(n,vector<int>(m,INT_MAX));
	priority_queue<ipair,vector<ipair>,greater<ipair>>pq2;
	vector<vector<char>>direction(n,vector<char>(m,'1'));
	vector<vii>from(n,vii(m));
	int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
	int xa,ya ;
	rep(i,0,n){
		rep(j,0,m){
			cin>>arr[i][j];
			if (arr[i][j]=='M'){
				pq.push(make_pair(0,make_pair(i,j)));
				dist[i][j] = 0;
			}
			if (arr[i][j] == 'A'){
				xa = i; ya = j;
				pq2.push({0,{i,j}});
				distA[i][j] = 0;
			}
		}
	}
	while (!pq.empty()){
		ipair p = pq.top();
		pq.pop();
		int val = p.ff;
		int x = p.ss.ff;
		int y = p.ss.ss;
		if (val==INT_MAX)continue;
		if (valid(x+1,y,n,m,arr,vis)){
			if (dist[x+1][y]>dist[x][y]+1){
				dist[x+1][y] = 1+ dist[x][y];
				pq.push(make_pair(1+dist[x][y],make_pair(x+1,y)));
			}
		}
		if (valid(x-1,y,n,m,arr,vis)){
			if (dist[x-1][y]>dist[x][y]+1){
				dist[x-1][y] = 1+ dist[x][y];
				pq.push(make_pair(1+dist[x][y],make_pair(x-1,y)));
			}
		}
				if (valid(x,y+1,n,m,arr,vis)){
			if (dist[x][y+1]>dist[x][y]+1){
				dist[x][y+1] = 1+ dist[x][y];
				pq.push(make_pair(1+dist[x][y],make_pair(x,y+1)));
			}
		}
		if (valid(x,y-1,n,m,arr,vis)){
			if (dist[x][y-1]>dist[x][y]+1){
				dist[x][y-1] = 1+ dist[x][y];
				pq.push(make_pair(1+dist[x][y],make_pair(x,y-1)));
			}
		}
	}
	while (!pq2.empty()){
		ipair p = pq2.top();
		pq2.pop();
		int val = p.ff;
		int xc = p.ss.ff,yc = p.ss.ss;
	//	cout<<xc<<" "<<yc<<endl;
		rep(i,0,4){
			int a = xc + dir[i][0];
			int b = yc + dir[i][1];
			if (valid(a,b,n,m,arr,vis)){
				vis[a][b] = true;
				from[a][b] = {xc,yc};
				direction[a][b] = checkdir(a,b,xc,yc);
				distA[a][b] = 1+val;
				pq2.push({distA[a][b],{a,b}});
			}
		}
	}
/*	rep(i,0,n){
		rep(j,0,m)cout<<direction[i][j]<<" ";
		cout<<endl;
	}
	exit(0);*/
	string ans = "";
	int xe,ye;
	rep(i,0,m){
		if (arr[0][i] == '.' && distA[0][i]<dist[0][i]){
			cout<<"YES"<<endl;
			xe = 0;ye = i;
			while (true){
				ans+= direction[xe][ye];
				pii p = from[xe][ye];
				xe = p.ff;ye = p.ss;
				if (xe == xa && ye == ya)break;
			}
			reverse(all(ans));
			cout<<sz(ans)<<endl;
			rep(i,0,sz(ans))cout<<ans[i];
			return ;
			
		}
	}
	rep(i,0,m){
		if (arr[n-1][i] == '.' && distA[n-1][i]<dist[n-1][i]){
			cout<<"YES"<<endl;
			xe = n-1;ye = i;
			while (xe!=xa && ye!=ya){
				ans+= direction[xe][ye];
				pii p = from[xe][ye];
				xe = p.ff;ye = p.ss;
				if (xe == xa && ye == ya)break;
			}
			reverse(all(ans));
			cout<<sz(ans)<<endl;
			rep(i,0,sz(ans))cout<<ans[i];
			return ;
			
		}
	}
	rep(i,0,n){
		if (arr[i][0] == '.' && distA[i][0]<dist[i][0]){
			cout<<"YES"<<endl;
			xe = i;ye = 0;
			while (xe!=xa && ye!=ya){
				ans+= direction[xe][ye];
				pii p = from[xe][ye];
				xe = p.ff;ye = p.ss;
				if (xe == xa && ye == ya)break;
			}
			reverse(all(ans));
			cout<<sz(ans)<<endl;
			rep(i,0,sz(ans))cout<<ans[i];
			return ;
			
		}
	}
	//cout<<xa<<" "<<ya<<1<<endl;
	rep(i,0,n){
		if (arr[i][m-1] == '.' && distA[i][m-1]<dist[i][m-1]){
			cout<<"YES"<<endl;
			xe = i;ye = m-1;
			while (true){
				ans+= direction[xe][ye];
				pii p = from[xe][ye];
				xe = p.ff;ye = p.ss;
				if (xe == xa && ye == ya)break;
			}
			reverse(all(ans));
			cout<<sz(ans)<<endl;
			rep(i,0,sz(ans))cout<<ans[i];
			return ;
			
		}
	}
	cout<<"NO"<<endl;
	
	return;
}

int32_t main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	//insert code
	solve();
	return 0;
}