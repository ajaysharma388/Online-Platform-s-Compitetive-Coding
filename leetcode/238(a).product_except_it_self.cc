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
	cout.tie(NULL);
	return;
}


vector<int> productExceptSelf2(vector<int>& nums) {
	int n = nums.size(); 
	vector<int> result(n,1);
	int p = 1;
	for(int i = 0; i < n; ++i) {
		result[i] = p;
		p *= nums[i]; 
	}
	p = 1;
	for(int i = n-1; i >= 0; --i) {
		result[i] *= p;
		p *= nums[i];
	}         
	return result;
}

vector<int> productExceptSelf1(vector<int>& nums) {
	int n = nums.size(); 
	vector<int> pre(n,1);
	vector<int> suf(n,1);
	vector<int> result(n,0);
	int p = 1;
	int s = 1;
	for(int i = 0; i < n; ++i) {
		pre[i] = p;
		suf[n-i-1] = s;
		p*=nums[i];
		s*=nums[n-i-1]; 
	}
	for(int i = 0; i < n; ++i) {
		result[i] = pre[i]*suf[i];
	}         
	return result;
}

int main(){
	fastio(true);
	int n;
	cin >> n;
	vector<int> nums(n,0);
	for(int i = 0; i < n; ++i) {
		cin >> nums[i];
	}
	nums = productExceptSelf2(nums);
	for(int i = 0; i < n; ++i) {
		cout << nums[i] << " ";
	}
	cout << endl;
	return 0;
}