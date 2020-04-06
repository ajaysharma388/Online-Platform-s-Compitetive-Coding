#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

bool check(bitset<1> arr[],int n) {
	int dis = 0;
	int i = 0;
	while(arr[i]!=1) i++;
	for(int j = i+1; j < n; ++j) 
		if(arr[j] != 1) dis++;
		else if(dis < 5) return false;
		else dis = 0;
	return true;
}

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
	while(t--) {
		ll n;
		cin >> n;
		bitset<1> arr[n];
		for(int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		if(check(arr,n)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}

// Sample Input :

// 3
// 3
// 1 0 1
// 7
// 1 0 0 0 0 0 1
// 11
// 0 1 0 0 0 0 0 1 0 0 1

// Sample Output :

// NO
// YES
// NO