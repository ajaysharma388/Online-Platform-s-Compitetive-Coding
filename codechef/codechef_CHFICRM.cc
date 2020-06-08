/*==========================
Author : Ajay Sharma
date : 08.05.2020
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

void solve() {
	int _5rs = 0, _10rs = 0, _15rs = 0;
	int n, amt; cin >> n;
	std::vector<int> persons(n);
	for(int i = 0 ; i < n; ++i) cin >> persons[i];
	bool possible = true;
	for(int p = 0; p < n; ++p) { 
		if(persons[p] == 10 and _5rs == 0) possible = false;
		else if(persons[p] == 15 and (_10rs == 0 and _5rs < 2)){
			possible = false;	
		} 
		else {
			if(persons[p] == 10) --_5rs;
			else if(persons[p] == 15) {
				if(_10rs) --_10rs;
				else _5rs -= 2;
			}
		}
		if(!possible) break;
		if(persons[p] == 5) _5rs++;
		else if(persons[p] == 10) _10rs++;
		else _15rs++;  
		// cout << "Rs. 5 : "<< _5rs << ", Rs. 10 : "<< _10rs << ", Rs. 15 : "<< _15rs << endl;
	}
	if(possible) cout << "YES" << endl;
	else cout << "NO" << endl;
	return;
}

int main() {
	fastio(true);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}

// Sample Input :

// 4
// 6
// 5 5 5 10 15 15
// 2
// 5 10
// 2
// 10 5
// 2
// 5 15

// Sample Output :

// YES
// YES
// NO
// NO