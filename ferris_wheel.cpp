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
	int n, k;
	cin>>n>>k;
	vi arr(n);
	rep(i,0,n)cin>>arr[i];
	sort(arr.begin(),arr.end());
	if (n == 1){
		cout<<1<<endl;
		return 0;
	}
	int j = n-1;
	int i = 0;
	int count =0;
	while (i<j){
		if (arr[i]+arr[j]<=k){
			count++;
			i++;
			j--;
		}
		else j--;
	}
	cout<<count+n-2*count<<endl;
	return 0;
}