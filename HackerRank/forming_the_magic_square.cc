#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"


bool isMagicSquare(vector<int> sq){
	int a[3][3]={};
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			a[i][j] = sq[3*i+j];
		}
	}
	int sum = 0;
	// evaluating the sum of first row.
	for(int j=0;j<3;++j){
		sum+=a[0][j];
	}
	// checking sum of each row.
	for(int i=1;i<3;++i){
		int tmp=0;
		for(int j=0;j<3;++j){
			tmp+=a[i][j];
		}
		if(tmp!=sum) return 0;
	}
	// checking sum of each column.
	for(int j=0;j<3;++j){
		int tmp=0;
		for(int i=0;i<3;++i){
			tmp+=a[i][j];
		}
		if(tmp!=sum) return 0;
	}
	// checking sum of diagonal 1.
	int tmp=0;
	for(int i=0;i<3;++i){
		tmp+=a[i][i];
	}
	if(tmp!=sum) return 0;
	tmp=0;
	for(int i=0;i<3;++i){
		tmp+=a[2-i][i];
	}
	if(tmp!=sum) return 0;
	return 1;
}

void find_magic_squares(vector<vector<int>> &magicSquares){
	vector<int> sq(9);
	for(int i=0;i<9;++i){
		sq[i] = i+1;
	}
	do{
		if(isMagicSquare(sq)){
			magicSquares.push_back(sq);
		}
	}while(next_permutation(sq.begin(),sq.end()));
}

int diff(vector<int> a,vector<int> b){
	int res=0;
	for(int i=0;i<9;++i){
		res+=abs(a[i]-b[i]);
	}
	return res;
}

int formingMagicSquare(vector<vector<int>> sq){
	int res = INT_MAX;
	vector<int> v;
	for(int i=0;i<sq.size();++i){
		for(int j=0;j<sq[i].size();++j){
			v.push_back(sq[i][j]);
		}
	}
	vector<vector<int>> magicSquares;
	// generating all the magic squares.
	find_magic_squares(magicSquares);
	for(int i=0;i<magicSquares.size();++i){
		// computing the diff.
		res = min(res,diff(v,magicSquares[i]));
	}
	return res;
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<vector<int>> sq;
	for(int i=0;i<3;++i){
		vector<int> v;
		for(int j=0;j<3;++j){
			int data;
			cin >> data;
			v.push_back(data);
		}
		sq.push_back(v);
	}	
	cout<<formingMagicSquare(sq)<<endl;
	return 0;
}

// Sample Input : 

// 8 3 4
// 1 5 9
// 6 7 2

// 4 9 2
// 3 5 7
// 8 1 5


// Sample Output : 

// 0
// 1