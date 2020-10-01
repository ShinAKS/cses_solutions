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

const int maxn = 1e6+1;
vector<int>nos(maxn,0);
void build(){
    for (int i = 2 ; i<maxn ; i++){
        for (int j = i ; j<maxn ; j*=i){
            nos[j]++;
        }
    }
    nos[1] = 1;
} 
void solve(){
	//write here
    int n;
    cout<<nos[n]<<endl;
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	//insert code
    build();
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}