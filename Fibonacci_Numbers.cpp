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
int m = 2;
struct Matrix{
    ll a[2][2]= {{0,0},{0,0}};
    Matrix operator *(const Matrix &other){
        Matrix product;
        rep(i,0,2){
            rep(j,0,2){
                rep(k,0,2){
                    product.a[i][k] += a[i][j] * other.a[j][k];
                    product.a[i][k]%=hell;
                }
            }
        }
        return product;
    }
};

Matrix expo_power(Matrix single,ll p){
    Matrix res;
    rep(i,0,2)res.a[i][i] = 1;
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
	ll n;
    cin>>n;
    if (n<=1){
        cout<<n<<endl;
        return 0;
    }
    Matrix single;
    single.a[0][0] = single.a[0][1] = 1;
    single.a[1][0] = 1;
    Matrix ans = expo_power(single,n-1);
    cout<<(ans.a[0][0])<<endl; 
    
}