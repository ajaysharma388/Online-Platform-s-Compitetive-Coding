#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

// editorial
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int n1 = nums.size();
        vector <int>::iterator pos; 
        pos = remove (nums.begin(), nums.end() , 0); 
        for(auto i = pos; i != nums.end(); ++i)
            *i = 0;
    }
};

void moveZeroes(vector<int>& nums) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n = nums.size();
	if(n == 0 or n == 1) return;
	int i = 0,j = 1;
	while(j < n) 
	if(nums[i] == 0 and nums[j]) {
		nums[i] = nums[j];
		nums[j] = 0;
	} else if(nums[i] and nums[j]){
		i++;
		j = i+1;
	} else j++;
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> vi;
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		int data; cin >> data;
		vi.push_back(data);
	}	
	moveZeroes(vi);
	for(int i = 0; i < n; ++i) {
		cout << vi[i] << " ";
	}
	return 0;
}