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


bool canTravel(vector<ll> &buses,int day,int n,int lastDay) {
	int i = 1;
	while(day <= lastDay and i <= n) {
		if(day % buses[i] == 0) ++i;
		else if(day <= lastDay) day++;
	}
	return (i > n) ? true : false;
}

int main(){
	fastio(true);
	ll t;
	cin >> t;
	for(ll testCase = 1; testCase <= t; ++testCase) {
		ll n,d;
		cin >> n >> d;
		vector<ll> buses(n+1,0);
		for(ll i = 1; i <= n; ++i) {
			cin >> buses[i];
		}
		int startDate = INT_MIN;
		int s = d - (d % buses[1]);
		for(; s >= buses[1]; s -= buses[1]) {
			if(canTravel(buses,s,n,d)) {
				startDate = s;
				break;
			}
		}
		cout << "Case #" << testCase << ": " << startDate << endl;
	}
	return 0;
}

// Sample Input :

// 3
// 3 10
// 3 7 2
// 4 100
// 11 10 5 50
// 1 1
// 1

// Sample Output :

// Case #1: 6
// Case #2: 99
// Case #3: 1