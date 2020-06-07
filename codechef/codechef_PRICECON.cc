/*==========================
Author : Ajay Sharma
date : 04.05.2020
============================*/
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

int main() {
	fastio(true);
	int t; cin >> t;
	while(t--) {
		int n, k, loss = 0;
		cin >> n >> k;
		for(int i = 0; i < n; ++i) {
			int p; cin >> p;
			loss += (p > k) ? p-k : 0;
		}
		cout << loss << endl;
	}
	return 0;
}