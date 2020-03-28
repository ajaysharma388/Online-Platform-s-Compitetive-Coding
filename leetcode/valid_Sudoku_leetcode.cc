#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

bool validateCell(vector<vector<char>>& board,int i,int j) {
    char data = board[i][j];
    // Doing the checks on the Row and Column         
    for(int k = 0; k < 9; ++k) {
        if(k != i and board[k][j] == data) return false;
        if(k != j and board[i][k] == data) return false;
    }
    int rStart = i/3*3;
    int cStart = j/3*3;
    int rEnd = rStart+3;
    int cEnd = cStart+3;
    // Doing Checks on the current 3*3 grid.         
    for(int r = rStart; r < rEnd; ++r) {
        for(int c = cStart; c < cEnd; ++c) {
            if((r != i and c != j) and board[r][c] == data) return false;
        }    
    }
    return true;
}
    
bool isValidSudoku(vector<vector<char>>& board) {
    for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) {
            if(board[i][j] != ' ' and !validateCell(board,i,j)) {
                return false;
            }       
        }
    }
    return true;
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
	if(isValidSudoku(board)) {
		cout << "Valid : true" << endl;
	} else {
		cout << "Valid : false" << endl;
	}
	return 0;
}

// Sample Input :

// 0 8 7 6 5 4 3 2 1 
// 2 0 0 0 0 0 0 0 0
// 3 0 0 0 0 0 0 0 0
// 4 0 0 0 0 0 0 0 0
// 5 0 0 0 0 0 0 0 0
// 6 0 0 0 0 0 0 0 0
// 7 0 0 0 0 0 0 0 0
// 8 0 0 0 0 0 0 0 0
// 9 0 0 0 0 0 0 0 0

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

// Valid : true
// Valid : true