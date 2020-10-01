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

ll power(ll a,ll b,ll p){
    if (b == 0)return 1;
    ll res = 1;
    while (b>0){
        if (b &  1)res = (res*a)%p;
        a = (a*a)%p;
        b = b>>1;
    }
    return res;
}
void solve(){
	//write here
    ll a,b,c;
    cin>>a>>b>>c;
    ll temp = power(b,c,hell-1);
    cout<<power(a,temp,hell)<<endl;
	return;
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	//insert code
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}