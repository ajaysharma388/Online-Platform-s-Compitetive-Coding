#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'

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
	int n; cin >> n;
	std::vector<int> athleats(n,0);
	std::multiset<int> mx,mn;
	for(int i = 0; i < n; ++i) 
		cin >> athleats[i];
	sort(athleats.begin(), athleats.end());
	int mxp = n-1,mnp = mxp-1;
	int mxAth = athleats[mxp];
	int mnAth = athleats[mnp];
	bool flag;
	flag = (mxAth == mnAth) ? true : false;
	mn.insert(mnAth); mx.insert(mxAth);
	for(int i = mnp-1; i >= 0; --i) {
		int cur = athleats[i];
		if(flag and mnAth != cur) {
			flag = false;
			mx.insert(cur);
		} else if ((mxAth - mnAth) > (mnAth - cur)) mx.insert(cur);
		else mn.insert(cur); 
		mxAth = *mx.begin();
	}
	int res = abs(mnAth - *mx.begin());
	cout << res << endl;
	return;
}

int32_t main() {
	fastio();
	int t; cin >> t;
	while(t--) 
		solve();
	return 0;
}

// Sample Input :

// 5
// 5
// 3 1 2 6 4
// 6
// 2 1 3 2 4 3
// 4
// 7 9 3 1
// 2
// 1 1000
// 3
// 100 150 200

// Sample Output :

// 1
// 0
// 2
// 999
// 50