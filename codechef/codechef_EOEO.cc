/*==========================
Author : Ajay Sharma
date : 04.05.2020
============================*/
#include <bits/stdc++.h>
using namespace std;

#define int long long int
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
	int TS;
	cin >> TS;
	if(TS & 1) {
		cout << TS/2 << endl;
	} else {
		while(TS%2==0) {
			TS /= 2;
		}
		cout << TS/2 << endl;
	}
	return;
}

int32_t main() {
	fastio(true);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}

// Sample Input :

// 5
// 22
// 12
// 18
// 1
// 11

// Sample Output :

// 5
// 1
// 4
// 0
// 5