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

int getArea(int x,int y) {
	if(x < y) return (2*x >= y) ? (x+x)*(x+x) : y*y; 
	else if(y < x) return (2*y >= x) ? (y+y)*(y+y) : x*x;
	else return (x+y)*(x+y);
}

void solve() {
	int a, b;
	cin >> a >> b;
	cout << getArea(a,b) << endl;
	return;
}

int32_t main() {
	fastio(true);
	int t; cin >> t;
	while(t--) 
		solve();
	return 0;
}

// Sample Input :

// 8
// 3 2
// 4 2
// 1 1
// 3 1
// 4 7
// 1 3
// 7 4
// 100 100

// Sample Output :

// 16
// 16
// 4
// 9
// 64
// 9
// 64
// 40000