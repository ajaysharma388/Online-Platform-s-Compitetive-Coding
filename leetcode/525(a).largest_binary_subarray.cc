#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vc vector<char>
#define vcc vector<vector<char>>
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
	cin.tie(0);
	cout.tie(0);
	return;
}

int findMaxLength(vector<int>& nums) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	unordered_map<int,int> mp;
	int max_length = 0;
	int count = 0;
	int n = nums.size();
	mp[0] = -1;
	for(int i = 0; i < n; ++i) {
		if(nums[i] == 1) count += 1;
		else count -= 1;
		if(mp.find(count) != mp.end()) max_length = max(max_length,(i-mp[count]));
		else mp[count] = i;
	}
	return max_length;
}

int findMaxLength2(vector<int>& nums) {
	int s,e=0;
	int sum = 0;
	int n = nums.size();
	while(e < n) {
		sum+=nums[e];
		e++;
	}
	if(sum == n) return 0;
	if(n >= 2*sum) return 2*sum;
    int ans = INT_MIN;
    sum = 0;
    e = 0;
    while(e < n) {
        sum+=nums[e];
        if(sum == 0) s = e;
        else if((e-s+1)%2 == 0 and 2*sum == (e-s+1)) ans = max(ans,(e-s+1)); 
        e++;
    }
    return ans;
}

int main() {
	fastio(true);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> nums(n,0);
		for(int i = 0; i < n; ++i) {
			cin >> nums[i];
		}
		cout << findMaxLength(nums) << endl;
	}
	return 0;
}

// Sample Input :

// 8
// 8 
// 1 1 1 1 1 1 1 1
// 8 
// 0 1 1 0 1 1 1 0
// 3 
// 0 1 1
// 7 
// 0 0 0 1 1 1 0
// 5 
// 0 0 0 0 0 
// 2 
// 0 1
// 9  
// 0 1 1 0 1 1 0 0 0 
// 10 
// 0 0 0 0 1 1 0 1 0 0 

// Sample Output :

// 0
// 4
// 2
// 6
// 0
// 2
// 8
// 6