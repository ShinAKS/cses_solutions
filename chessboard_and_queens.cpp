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



bool isSafe(int r, int c, vector<vector<char>>&board){
	if (board[r][c] =='*')return false;
	for (int a = 0 ; a<r ; a++){
		if (board[a][c] =='Q')return false;
	}
	for (int a=r-1,b=c-1 ; a>=0 && b>=0; a--,b--){
		if (board[a][b] == 'Q')return false;
	}
	for (int a=r-1,b=c+1; a>=0 && b<8 ;a--,b++){
		if (board[a][b] == 'Q')return false;
	}
	return true;
}

void process(vector<vector<char>>&board, int i,int &count){
	if (i == 8){
		count++;
		return;
	}
	for (int j = 0;j<8;j++){
		if (isSafe(i,j,board)){
			board[i][j]='Q';
			process(board, i+1,count);
			board[i][j]='.';
		}
	}
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	//insert code
	vector<vector<char>>board(8,vector<char>(8));
	int count =0;
	rep(i,0,8)rep(j,0,8)cin>>board[i][j];
	
	process(board, 0,count);
	cout<<count<<endl;
	
	return 0;
}