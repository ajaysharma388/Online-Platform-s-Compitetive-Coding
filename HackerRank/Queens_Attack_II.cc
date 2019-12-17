#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

char board[1000][1000];

int queensAttack(int n, int k, int r, int c, vector<vector<int>> obs) {
	memset(board,'_',sizeof board);
	board[r-1][c-1]='Q';
	for(int c=0;c<k;++c){
		board[obs[c][0]-1][obs[c][1]-1] = 'X';
	}
	int count=0;
	int x=c;
	while(x<n){
		if(board[r-1][x]=='X') break;
		count++;// +ve x direction.
		x++;
	}
	x=c-2;
	while(x>-1){
		if(board[r-1][x]=='X') break;
		count++;// -ve x direction.
		x--;
	}
	x=r;
	while(x<n){
		if(board[x][c-1]=='X') break;
		count++;// -ve y direction.
		x++;
	}
	x=r-2;
	while(x>-1){
		if(board[x][c-1]=='X') break;
		count++;// +ve y direction.
		x--;
	}
	int y=c;
	x=r;
	while(x<n && x>-1 && y<n && y>-1){
		if(board[x][y]=='X') break;
		count++;
		x++;y++;
	}
	y=c-2;
	x=r-2;
	while(x<n && x>-1 && y<n && y>-1){
		if(board[x][y]=='X') break;
		count++;
		x--;y--;
	}
	y=c-2;
	x=r;
	while(x<n && x>-1 && y<n && y>-1){
		if(board[x][y]=='X') break;
		count++;
		x++;y--;
	}
	y=c;
	x=r-2;
	while(x<n && x>-1 && y<n && y>-1){
		if(board[x][y]=='X') break;
		count++;
		x--;y++;
	}
	return count;
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k,r,c;
	cin >> n >> k >> r >> c;
	vector<vector<int>> obs(k);
	for(int i=0;i<k;++i){
		for(int j=1;j<=2;++j){
			int data;
			cin >> data;
			obs[i].push_back(data);
		}
	}
	cout<<queensAttack(n,k,r,c,obs);
	return 0;
}

// Sample Input :

// 5 3
// 4 3
// 5 5
// 4 2
// 2 3

// 4 0
// 4 4

// Sample Output :

// 10
// 9