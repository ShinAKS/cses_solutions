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
const int maxn = 2e6+5;
ll fact[maxn];
ll invfact[maxn];

ll binpow(ll x,ll p){
    ll res = 1;
    while (p>0){
        if (p & 1)res = (res*x)%hell;
        x = (x*x)%hell;
        p = p>>1;
    }
    return res;
}

void solve(){
	fact[0] = 1;
    rep(i,1,maxn)fact[i] = (fact[i-1]*i)%hell;
    invfact[maxn-1] = binpow(fact[maxn-1],hell-2);
    for (ll i = maxn-2 ; i>=0 ; i--){
        invfact[i] = ((i+1) * invfact[i+1])%hell;
    }
	return;
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	//insert code
    solve();
	ll n;
    cin>>n;
    ll ans = 0;
    rep(i,0,n+1){
        ans = (ans + (i%2==0?1:-1)*invfact[i])%hell;
        ans = (ans+hell)%hell;
    }
    ans = (ans * fact[n])%hell;
    cout<<ans<<endl;
}