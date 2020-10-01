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
 
const int maxn = 1000001;
int numbers[maxn];
ll n;
 
ll sumtill(ll x){
    
    x = x%hell;
    ll sum = (x*(x+1));
    sum%=hell;
    sum*=((hell+1)/2);
    sum%=hell;
    return sum;
 
}
 
void solve(){
	//write here
    cin>>n;
    ll ans = 0;
    for(ll i=1;i*i<n;i++){
        if(i==n/i){
            continue;
        }
        ans+= n/i * i;
        ans%=hell;
    }
    for(ll i=1;i*i<=n;i++){
        ans+=(sumtill(n/i) - sumtill(n/(i+1)))*i;
        ans%=hell;
    }
    
    cout<<ans<<endl;
}
 
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	//insert code
    //build();
	
		solve();
	return 0;
}