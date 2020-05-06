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

bool compare(int a,int b) {
	return a > b;
}

vector<int> cutTheSticks(vector<int> arr) {
	vector<int> res;
	while(!arr.empty()) {
		sort(arr.begin(),arr.end(),compare);
		int count = 0;
		int n = arr.size();
		int min = arr[n-1];
		for(int i = n-1; i >= 0; --i) {
			arr[i] -= min;
			count += 1;
			if(arr[i] == 0) arr.pop_back();
		}
		res.pb(count);
	}
	return res;
}

int main() {
	fastio(true);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> arr(n,0);
		for(int i = 0; i < n; ++i) 
			cin >> arr[i];
		for(int e : cutTheSticks(arr))
			cout << e << " ";
		cout << endl;
	}
	return 0;
}

// Sample Input :

// 2
// 6
// 5 4 4 2 2 8
// 8
// 1 2 3 4 3 3 2 1

// Sample Output :

// 6 4 2 1 
// 8 6 4 1 