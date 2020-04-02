#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

bool canPlace(vector<vector<char>>& board,char data,int i,int j) {
	for(int k = 0; k < 9; ++k) {
		if(data == board[i][k]) return false;
		if(data == board[k][j]) return false;
	}
	int row = i/3;
	int col = j/3;
	for(int m = row*3; m < row*3+3; ++m) 
		for(int n = col*3; n < col*3+3; ++n) 
			if(data == board[m][n]) return false;
	return true;
}


bool solve(vector<vector<char>>& board,int i,int j) {
	// if we have already solved the entire board.
	if(i == 9) return true;
	// if we have processed the current row.
	if(j == 9){
		i++;
		j = 0;
		return solve(board,i,j);
	}
	// if the current place is not empty
	if(board[i][j] != ' ') return solve(board,i,j+1);
	// try to fill the current row;
	
	for(int c = 1; c <= 9; ++c) {
		char cur = '0'+c;
		if(canPlace(board,cur,i,j)){
			board[i][j] = cur;
			bool result = solve(board,i,j+1);
			if(result) return true;
			board[i][j] = ' ';
		} 
	}
	return false;
}


void solveSudoku(vector<vector<char>>& board) {
	solve(board,0,0);
}


int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<vector<char>> board;
	board.reserve(9);
	for(int i = 0; i < 9; ++i) {
		board[i].reserve(9);
	}
	for(int i = 0 ; i < 9; ++i) {
		for(int j = 0; j < 9; ++j) {
			char data;
			cin >> data;
			if(data == '0') board[i][j] = ' ';
			else board[i][j] = data;
		}
	}
	solveSudoku(board);
	for(int i = 0 ; i < 9; ++i) {
		for(int j = 0; j < 9; ++j) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

// Sample Input :

// 5 3 0 0 7 0 0 0 0
// 6 0 0 1 9 5 0 0 0
// 0 9 8 0 0 0 0 6 0
// 8 0 0 0 6 0 0 0 3
// 4 0 0 8 0 3 0 0 1
// 7 0 0 0 2 0 0 0 6
// 0 6 0 0 0 0 2 8 0
// 0 0 0 4 1 9 0 0 5
// 0 0 0 0 8 0 0 7 9

// Sample Output :

// 5 3 4 6 7 8 9 1 2 
// 6 7 2 1 9 5 3 4 8 
// 1 9 8 3 4 2 5 6 7 
// 8 5 9 7 6 1 4 2 3 
// 4 2 6 8 5 3 7 9 1 
// 7 1 3 9 2 4 8 5 6 
// 9 6 1 5 3 7 2 8 4 
// 2 8 7 4 1 9 6 3 5 
// 3 4 5 2 8 6 1 7 9 