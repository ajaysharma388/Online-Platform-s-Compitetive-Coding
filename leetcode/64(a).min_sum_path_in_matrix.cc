#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

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

void findMinPath(vector<vector<int>>& grid,int **dp,int i,int j,int m,int n) {
    // sucess case.
    if(i == m-1 and j == n-1) {
        dp[i][j] = grid[i][j];
        return;
    }
    // runned out of the grid.
    if(j == n or i == m) return;
    if(dp[i][j] != -1) return;
    findMinPath(grid,dp,i,j+1,m,n);
    findMinPath(grid,dp,i+1,j,m,n);
    if(i < m-1 and j < n-1) dp[i][j] = min(dp[i][j+1],dp[i+1][j]) + grid[i][j];
    else if(i == m-1 and j < n-1) dp[i][j] = dp[i][j+1] + grid[i][j];
    else dp[i][j] = dp[i+1][j] + grid[i][j];
    return;
}

int minPathSum(vector<vector<int>>& grid) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m = grid.size();
    if(m == 0) return 0;
    int n = grid[0].size();
    int **dp = new int*[m];
    for(int i = 0; i < m; ++i) 
        dp[i] = new int[n];
    for(int i = 0; i < m; ++i) 
        for(int j = 0; j < n; ++j) 
            dp[i][j] = -1;
    findMinPath(grid,dp,0,0,m,n);
    int ans = dp[0][0];
    for(int i = 0; i < m; ++i) 
        delete []dp[i];
    delete []dp;
    return ans;
}

int main(){
	fastio(true);
	int m,n;
	cin >> m >> n;
	vector<vector<int>> grid(m,vector<int>(n,0));
	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j) {
			cin >> grid[i][j];
		}
	}
	cout << minPathSum(grid) << endl;
	return 0;
}

// Sample Input :

// 3 3
// 1 3 1
// 1 5 1
// 4 2 1

// Sample Output :

// 3 3
// 1 3 1
// 1 5 1
// 4 2 1