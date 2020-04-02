#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"


int shipWithinDays(vector<int>& weights, int D) {
	int totalWeight = 0;
	int minSingleWeight = INT_MIN;
	for(auto w : weights) {
		totalWeight += w;
		minSingleWeight = max(minSingleWeight,w);
	}        
	while(minSingleWeight < totalWeight) {
		int capacity = minSingleWeight + (totalWeight - minSingleWeight)/2;
		int currentWeight = 0;
		int days = 1;
		for(auto w : weights) {
			if(currentWeight + w > capacity) {
				++days;
				currentWeight = 0;
			}
			currentWeight += w;
		}
		if(days > D) minSingleWeight = capacity + 1;
		else totalWeight = capacity;
	}
	return minSingleWeight;
}


int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,d;
	cin >> n >> d;
	vector<int> weights(n,0);
	for(int i = 0; i < n; ++i) {
		cin >> weights[i];
	}	
	cout << shipWithinDays(weights,d) << endl;
	return 0;
}

// Sample Input :

// 10 5
// 1 2 3 4 5 6 7 8 9 10

// Sample Output :

// 15