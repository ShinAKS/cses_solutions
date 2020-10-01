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
    ll a[6][6]= {{0,0,0,0,0,0},
                 {0,0,0,0,0,0},
                 {0,0,0,0,0,0},
                 {0,0,0,0,0,0},
                 {0,0,0,0,0,0},
                 {0,0,0,0,0,0}};
    Matrix operator *(const Matrix &other){
        Matrix product;
        rep(i,0,6){
            rep(j,0,6){
                rep(k,0,6){
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
    if (n<=6){
        if (n==1)cout<<1<<endl;
        if (n==2)cout<<2<<endl;
        if (n==3)cout<<4<<endl;
        if (n==4)cout<<8<<endl;
        if (n==5)cout<<16<<endl;
        if (n==6)cout<<32<<endl;
        return 0;
    }
    vector<ll>init = {1,2,4,8,16,32};
    reverse(all(init));
    Matrix single;
    rep(i,1,6){
        single.a[i][i-1] = 1;
    }
    rep(i,0,6)single.a[0][i] = 1;
    /* rep(i,0,6){
        rep(j,0,6)cout<<single.a[i][j]<<" ";
        cout<<endl;
    } */
    Matrix ans = expo_power(single,n-6);
    ll res = 0;
    rep(i,0,6){
        res += ans.a[0][i]*init[i];
        res%=hell;
    }
    cout<<res<<endl;
    
}