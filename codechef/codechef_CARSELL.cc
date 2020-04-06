#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"
#define mod 1000000007

bool compare(int a,int b) {
	return a > b;
}

int maxProfit(vector<int>&cars) {
	int profit = 0;
	int n = cars.size();
	for(int i = 0; i < n; ++i) {  
		profit += (cars[i]-i >= 0) ? (cars[i]-i) : 0;
		profit%=mod;
	}
	return profit;	
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t,n;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> cars(n,0);
		for(int i = 0; i < n; ++i) 
			cin >> cars[i];
		sort(cars.begin(), cars.end(), compare);
		cout << maxProfit(cars) << endl;
	}
	return 0;
}

// Sample Input :

// 2
// 3
// 6 6 6
// 3
// 0 1 0

// Sample Output :

// 15
// 1