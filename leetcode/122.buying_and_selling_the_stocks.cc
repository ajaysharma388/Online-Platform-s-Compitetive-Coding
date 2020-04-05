#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vii vector<vector<int>>
#define pb(x) push_back(x)
#define ppb() pop_back()
#define endl "\n"

int n = 4;

void fastio() {
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	return;
}

int calculate(vector<int>& prices,int s) {
	int n = prices.size();
	if(s >= n-1) return 0;
	int maxProfit = INT_MIN;
	for(int start = s; start < n; ++start) {
		int profit_now = 0;
		for(int end = start+1; end < n; ++end) {
			int profit = calculate(prices,end+1) + (prices[end] - prices[start]);
			profit_now = max(profit_now,profit);
		}
		maxProfit = max(maxProfit,profit_now);
	}
	return maxProfit;
}

int maxProfit1(vector<int>& prices) {
	return calculate(prices,0);
}

int maxProfit2(vector<int> prices) {
    int i = 0;
    int n = prices.size();
    int valley = prices[0];
    int peak = prices[0];
    int maxprofit = 0;
    while (i < n - 1) {
        while (i < n - 1 and prices[i] >= prices[i + 1])
            i++;
        valley = prices[i];
        while (i < n - 1 and prices[i] <= prices[i + 1])
            i++;
        peak = prices[i];
        maxprofit += peak - valley;
    }
    return maxprofit;
}

int maxProfit(vector<int>& prices) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int res = 0;
    int n = prices.size();
    for(int i = 1; i < n; ++i) 
        if(prices[i] > prices[i-1]) 
            res += prices[i] - prices[i-1];
    return res;
}

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        
        int P = 0;
        for (int i =1; i<prices.size(); i++){
            if (prices[i]>prices[i-1]){
                P = P + prices[i] - prices[i-1];
            }
        }
        return P;
    }
};

int main(){
	fastio();
	int t,n;
	cin >> t;
	while(t--) {
		cin >> n;
		vector<int> prices(n,0);
		for(int i = 0; i < n; ++i) {
			cin >> prices[i];
		}
		cout << maxProfit(prices) << endl;
	}
	return 0;
}

// Sample Input :

// 3
// 6
// 7 1 5 3 6 4
// 5
// 1 2 3 4 5
// 5
// 7 6 4 3 1

// Sample Output :

// 7 
// 4 
// 0