#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	//insert code
	int t;
	cin>>t;
	while (t--){
		ll x,y;
		cin>>x>>y;
		if (x==1 && y ==1 ){
			cout<<1<<endl;
			continue;
		}
		else if (x==y){
			cout<<x*x-(x-1)<<endl;
			continue;
		}
		else{
			if (y>x){
				if (y%2){
					cout<<(y*y-abs(x-1))<<endl;
					continue;
				}
				else{
					cout<<(y-1)*(y-1)+x<<endl;
					continue;
				}
			}
			else{
				if (x%2==0){
					cout<<(x*x-abs(y-1))<<endl;
					continue;
				}
				else{
					cout<<(x-1)*(x-1)+y<<endl;
					continue;
				}
			}
		}
	}
	return 0;
}