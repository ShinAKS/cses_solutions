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
//int numbers[maxn];
int n;

void factorise(int x,vector<int>&numbers){
    for (int i = 1; i<sqrt(x)+1;i++){
       // cout<<i<<endl;
        if (x%i==0){
            //cout<<i<<endl;
            if (x == i*i)numbers[i]++;
            else {
                numbers[i]++;
                numbers[x/i]++;
            }
        }
    }
}
void solve(){
	//write here

    vector<int>numbers(maxn,0);
    cin>>n;
    vi arr(n);
    rep(i,0,n)cin>>arr[i];
    rep(i,0,n){
        factorise(arr[i],numbers);
    }
    int val = 1;
    for (int i = 1;  i<maxn ; i++){
        //cout<<numbers[i]<<" ";
        if (numbers[i]>=2)val = i;
    }
    cout<<val<<endl;
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	//insert code
    //build();
	
		solve();
	return 0;
}