/*==========================
Author : Ajay Sharma
date : 04.05.2020
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

int main() {
	fastio(true);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int *arr = new int[n]();
		for(int i = 0; i < n; ++i) 
			cin >> arr[i];
		vector<int> group;
		int j = 0;
		int k = 1;
		int prev = arr[j];
		while(k < n) {
			if(abs(prev - arr[k]) <= 2) prev = arr[k];
			else {
				group.pb(k-j);
				j = k;
				prev = arr[j];
			}
			k++;
		}
		group.pb(k-j);
		sort(group.begin(),group.end());
		int f = group[0];
		int l = group[group.size()-1];
		cout << f << " " << l << endl;
	}
	return 0;
}

// Sample Input :

// 3
// 2
// 3 6
// 3
// 1 3 5
// 5
// 1 2 5 6 7

// Sample Output :

// 1 1
// 3 3
// 2 3