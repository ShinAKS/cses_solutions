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

bool legal(int x,int y){
    if ((x<0 || x>=8) || (y<0 || y>=8) )return false;
    return true;
}
void solve(){
	//write here
    int n;
    cin>>n;
    double dp[n+1][8][8];
    for (int i = 0 ; i<n ; i++){
        for (int j = 0 ; j<8 ; j++){
            for (int k = 0 ; k<8 ; k++){
                dp[i][j][k] = 0;
                if (i == 0)dp[i][j][k] = 1;
            }
        }
    }
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,-1,0,1};
    for (int i = 1 ; i<n ; i++){
        for (int j = 0 ; j<8 ; j++){
            for (int k = 0 ; k<8 ; k++){
                int dir = 0 ;
                for (int l = 0 ; l<4 ; l++){
                    int x = j + dx[l];
                    int y = k + dy[l];
                    if (legal(x,y))dir++;
                }
                for (int l = 0 ; l<4 ; l++){
                    int x = j + dx[l];
                    int y = k + dy[l];
                    if (legal(x,y))dp[i][x][y] += dp[i-1][j][k]/dir;
                }
            }
        }
    }
    double ans[8][8];
    for (int i = 0 ; i<8 ; i++)for (int j = 0 ; j<8 ; j++)ans[i][j] = 1;
    for (int i = 0 ; i<8 ; i++){
        for (int j = 0 ; j<8  ;j++){
            ans[i][j]*=(1 - dp[n][i][j]);
        }
    }
    double exp = 0;
    for (int i = 0 ; i<8 ; i++){
        for (int j = 0 ; j<8 ; j++)exp+=ans[i][j];
    }
    cout<<fixed<<setprecision(6)<<exp<<endl;
    return;
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	//insert code
    
		solve();
	return 0;
}