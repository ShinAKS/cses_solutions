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
	int n, m , k;
	cin>>n>>m>>k;
	vi applicant(n) , rooms(m);
	rep(i,0,n)cin>>applicant[i];
	rep(i,0,m)cin>>rooms[i];
	sort(all(applicant));
	sort(all(rooms));
	int i=0,j=0;
	int count = 0;
	while (i<n && j<m){
		if (abs(applicant[i] - rooms[j])<=k){
			i++;
			j++;
			count++;
		}
		else if (applicant[i] -rooms[j] > k)j++;
		else if (rooms[j] - applicant[i] >k )i++;
	}
	cout<<count<<endl;
	return 0;
}