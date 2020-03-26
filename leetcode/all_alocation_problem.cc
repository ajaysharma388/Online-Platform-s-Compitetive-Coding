#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define endl "\n"

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin >> t;
	for(int testcase = 1; testcase <= t; ++testcase) {
		ll n,k;
		cin >> n >> k;
		vector<ll> data(n,0);
		for(ll i = 0; i < n; ++i) {
			cin >> data[i];
		}
		sort(data.begin(),data.end());
		ll i = 0;
		ll count = 0;
		while(data[i] <= k and i < n) {
			k -= data[i];
			count++;
			i++;
		}
		cout << "Case #" << testcase<< ": " << count << endl;
	}		
	return 0;
}

// Sample Input :

// 3
// 4 100
// 20 90 40 90
// 4 50
// 30 30 10 10
// 3 300
// 999 999 999

// Sample Output :

// Case #1: 2
// Case #2: 3
// Case #3: 0