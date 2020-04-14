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

string shiftList(string s,int dir,int amt) {
	int length = s.length();
	if(length == 0 or length == 1) return s;
	if(amt == length) return s;
	int i = 0, j = length-1;
	switch(dir){
		case 0:
			while(amt--) {
				j = i;
				i++;
				i%=length;
			} 
			break;
		case 1:
			while(amt--) {
				i = j;
				j--;
				j = (j == 0) ? length-1 : j; 
			}
			break;
		default: break;
	}
	string res = "";
	int len = 0;
	while(len!=length) {
		res+=s[i];
		i++;
		if(i == length) i%=length;
		len++;
	}
	return res;
}

string stringShift(string s, vector<vector<int>>& shift) {
	int n = shift.size();
	if(n == 0) return s;
	int count = 0;
	for(int i = 0;i < n; ++i) 
		s = shiftList(s,shift[i][0],shift[i][1]);
	return s;
}

int main() {
	fastio(true);
	string s;
	cin >> s;
	int n;
	cin >> n;
	vector<vector<int>> shifts(n,vector<int>(2,0));
	for(int i = 0; i < n; ++i) 
		for(int j = 0; j < 2; ++j) 
			cin >> shifts[i][j];
	cout << stringShift(s,shifts) << endl;
	return 0;
}

// Sample Input :

// wpdhhcj
// 7
// 0 7
// 1 7
// 1 0 
// 1 3
// 0 3
// 0 6
// 1 2

// Sample Output :

// hcjwpdh