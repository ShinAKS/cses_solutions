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
int rnk[maxN];
int parent[maxN];

int find(int u){
	if (u!=parent[u])return find(parent[u]);
	return u;
}

void unite(int u,int v){
	int a = find(u);
	int b = find(v);
    if (a != b) {
        if (rnk[a] < rnk[b])
            swap(a, b);
        parent[b] = a;
        rnk[a] += rnk[b];
    }
}

int32_t main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	//insert code
	int n,m;
	cin>>n>>m;
	rep(i,1,n)rnk[i] = 1;
	rep(i,1,n)parent[i] = i;
	int u,v;
	rep(i,0,m){
		cin>>u>>v;
		unite(u,v);
	}
	vector<pii>ans;
	rep(i,2,n+1){
		if (find(1)!=find(i)){
			ans.pb({1,i});
			unite(1,i);
		}
	}
	cout<<sz(ans)<<endl;
	rep(i,0,sz(ans))cout<<ans[i].ff<<" "<<ans[i].ss<<endl;
}