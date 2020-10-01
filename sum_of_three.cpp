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

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	//insert code
	int n,k;
	cin>>n>>k;
	vii arr(n);
	rep(i,0,n){
		cin>>arr[i].ff;
		arr[i].ss = i+1;
	}
	sort(all(arr));
	if (n<=2){
		cout<<"IMPOSSIBLE"<<endl;
		return 0;
	}
	rep(i,0,n-2){
		int p = arr[i].ff;
		int start = i+1;
		int end = n-1;
		while (start<end){
			int q = arr[start].ff;
			int r = arr[end].ff;
			if (p+q+r == k ){
				cout<<arr[i].ss<<" "<<arr[start].ss<<" "<<arr[end].ss<<endl;
				return 0;
			}
			else if (p+q+r<k){
				while (start<end && arr[start].ff == q )start++;
				if (p+arr[start].ff+r<k)start++;
			}
			else{
				while (start<end && arr[end].ff == r)end--;
				if (p+q+arr[end].ff>k)end--;
			}
			if (start>=end)break;
		}
	}
	cout<<"IMPOSSIBLE"<<endl;
	return 0;
}