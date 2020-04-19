#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"
#define vb vector<vector<bool>>
#define vc vector<vector<char>>

void fastio(bool read = false) {
	if(read) {
		#ifndef ONLINE_JUGDE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		freopen("error.txt","w",stderr);
		#endif	
	}
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	return;
}

void visitAllconnectedNode(vc& grid,vb& isConsidered,int i,int j,int m,int n) {
	if(i >= m or j >= n or i < 0 or j < 0) return;
	if(isConsidered[i][j] or grid[i][j] == '0') return;
	isConsidered[i][j] = true;
	// Call On next col
	visitAllconnectedNode(grid,isConsidered,i,j+1,m,n);
	// call on next row
	visitAllconnectedNode(grid,isConsidered,i+1,j,m,n);
	// Call On prev col
	visitAllconnectedNode(grid,isConsidered,i,j-1,m,n);
	// call on prev row
	visitAllconnectedNode(grid,isConsidered,i-1,j,m,n);
	return;
}


int numIslands(vc& grid) {
	int m = grid.size();
	int n = grid[0].size();
	vb isConsidered(m,vector<bool>(n,false));
	int count = 0;
	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j) {
			if(!isConsidered[i][j] and grid[i][j] == '1') {
				visitAllconnectedNode(grid,isConsidered,i,j,m,n);
				count++;
			}
		}
	}        
	return count;
}

int main(){	
	fastio(true);
	int t;
	cin >> t;
	while(t--) {
		int m,n;
		cin >> m >> n;
		vc grid(m,vector<char>(n,' '));
		for(int i = 0; i < m; ++i) {
			for(int j = 0; j < n; ++j) {
				cin >> grid[i][j];
			}
		}
		cout << numIslands(grid) << endl; 
	}
	return 0;
}