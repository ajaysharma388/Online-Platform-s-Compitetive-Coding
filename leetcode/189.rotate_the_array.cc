#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

void shift(vector<int>&nums) {
    int n = nums.size();
    int t = nums[n-1];
    for(int i = n-2; i >= 0; --i) {
        nums[i+1] = nums[i];
    }
    nums[0] = t;
    return;
}
    
void rotate(vector<int>& nums, int k) {
    for(int i = 0; i < k; ++i) {
        shift(nums);
    }
    return;
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> nums(n,0);
	for(int i = 0; i < n; ++i) {
		cin >> nums[i];
	}
	rotate(nums,1);
	for(int i = 0; i < n; ++i) {
		cout << nums[i] << " ";
	}
	return 0;
}

// Sample Input :

// 4
// {{(([]))}}}
// ({)}
// ()
// (((({[]})))){{{[()]}}}

// Sample Output :

// No
// No
// Yes
// Yes