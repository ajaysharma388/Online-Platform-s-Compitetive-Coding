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
}

int countElements(vector<int>& arr) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    unordered_map<int,int> mp;
    for(int e : arr) 
        if(mp.find(e) != mp.end()) mp[e]++;
        else mp[e] = 1;
    int res = 0;
    for(int e : arr)
        if(mp.find(e+1) != mp.end()) res++;
    return res;
}

int main(){
	fastio(true);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> arr(n,0);
		for(int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		cout << countElements(arr) << endl;
	}
	return 0;
}

// Sample Input :

// 3
// 8
// 1 1 3 3 5 5 7 7
// 3
// 1 2 3
// 6
// 1 3 2 3 5 0

// Sample Output :

// 0 
// 2 
// 3