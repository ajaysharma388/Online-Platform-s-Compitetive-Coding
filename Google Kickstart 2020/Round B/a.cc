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

int main(){
	fastio(true);
	ll t;
	cin >> t;
	for(ll testCase = 1; testCase <= t; ++testCase) {
		ll n;
		cin >> n;
		vector<ll> mountain(n+1,0);
		for(ll i = 1; i <= n; ++i) {
			cin >> mountain[i];
		}
		ll peakCount = 0;
		for(ll i = 2; i < n; ++i) {
			if(mountain[i-1] < mountain[i] and mountain[i] > mountain[i+1]) {
				peakCount += 1;
			} 
		}
		cout << "Case #" << testCase << ": " << peakCount << endl;
	}
	return 0;
}

// Sample Input :

// 4
// 3
// 10 20 14
// 4
// 7 7 7 7
// 5
// 10 90 20 90 10
// 3
// 10 3 10


// Sample Output :

// Case #1: 1
// Case #2: 0
// Case #3: 2
// Case #4: 0