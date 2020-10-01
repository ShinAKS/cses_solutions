#include <bits/stdc++.h>
#define ll          long long
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

// Most important thing in CP - Have Fun :)
int n,m,k;
struct Matrix{
    vector<vector<ll>>a = vector<vector<ll>>(n,vector<ll>(n,INT_MAX));
    Matrix operator *(const Matrix &other){
        Matrix product;
        rep(i,0,n){
            rep(j,0,n){
                rep(k,0,n){
                    product.a[i][k] = min(product.a[i][k],a[i][j] + other.a[j][k]);
                }
            }
        }
        return product;
    }
};

Matrix expo_power(Matrix single,ll p){
    Matrix res;
    rep(i,0,n)res.a[i][i] = 1;
    while (p>0){
        if (p & 1)res = res*single;
        single = single*single;
        p = p>>1;
    }
    return res;
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	//insert code
    cin>>n>>m>>k;
    Matrix single;
    for (int i = 0 ; i<m ; i++){
        ll u,v,w;
        cin>>u>>w;
        single.a[u-1][v-1] = min(single.a[u-1][v-1],w);
        //single.a[v-1][u-1] = 1;
    }
    rep(i,0,n){
        rep(j,0,n)cout<<single.a[i][j]<<" ";
        cout<<endl;
    }
    Matrix ans = expo_power(single,k);
    cout<<ans.a[0][n-1]<<endl;
    
}