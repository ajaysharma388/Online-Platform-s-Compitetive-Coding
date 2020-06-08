/*==========================
Author : Ajay Sharma
date : 08.05.2020
============================*/
#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define vi(n) vector<long long int>
#define vii(m,n) vector<m, vector<long long int>(n,0)>
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

void solve() {
	int pairs = 0, n;
	string s;
	cin >> s;
	n = s.length();
	for(int i = 0; i < n-1; ) {
		if(s[i] == 'x' and s[i+1] == 'y' or s[i] == 'y' and s[i+1] == 'x'){ 
			pairs++;
			i += 2;
		} else {
			i++;
		}
	}
	cout << pairs << endl;
	return;
}

int main() {
	fastio(true);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}