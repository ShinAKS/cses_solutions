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

const int maxN = 1001;
char arr[maxN][maxN];
char direc[maxN][maxN];

char checkdir(int dx,int dy,int sx,int sy){
	if (dy == sy && dx==sx-1)return 'U';
	if (dy == sy && dx == sx+1)return 'D';
	if (dy == sy-1 && dx == sx)return 'L';
	if (dy == sy+1 && dx == sx)return 'R';
}

int32_t main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	//insert code
	memset(arr,'#',sizeof(arr));
	vector<vii>from(maxN,vector<pii>(maxN,{-1,-1}));

	int n,m;
	cin>>n>>m;
	int x ,y;
	int tx,ty;
	rep(i,0,n){
		rep(j,0,m){
			cin>>arr[i][j];
			if (arr[i][j] == 'A'){
				x = i;y = j;
			}
			if(arr[i][j] == 'B'){
				tx = i;ty = j;
			}
		}
	}
	vector<vector<bool>>vis(n,vector<bool>(m,false));
	vis[x][y] = true;
	queue<pii>q;
	int dir[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0}}; 
	q.push({x,y});
	while (!q.empty()){
		pii t = q.front();
		q.pop();
		int xc = t.ff,yc =t.ss;
	//	cout<<xc<<" "<<yc<<endl;
	
		if(xc == tx && yc == ty)break;
		for (int i = 0;i<4;i++){
			int a = xc + dir[i][0];
			int b = yc + dir[i][1];
			if ((a>=0 && a<n) && (b>=0 && b<m)){
				if(vis[a][b] || (arr[a][b]=='#'))continue;
				vis[a][b] = true;
				from[a][b] = {xc,yc};
				direc[a][b] = checkdir(a,b,xc,yc);
				q.push({a,b});
			}
		}
		
	}
	/*
	rep(i,0,n){
		rep(j,0,m)cout<<vis[i][j]<<" ";
		cout<<endl;
	}
	*/
	if (!vis[tx][ty]){
		cout<<"NO"<<endl;
		return 0;
	}
	string ans = "";
	int xe = tx,ye = ty;
	while(arr[xe][ye]!='A'){
		ans += direc[xe][ye];
		pii r = from[xe][ye];
	//	cout<<r.ff<<" "<<r.ss<<endl;
		xe = r.ff;ye=r.ss;
	}
	reverse(all(ans));
	cout<<"YES"<<endl;
	cout<<sz(ans)<<endl;
	cout<<ans<<endl;
	return 0;
}