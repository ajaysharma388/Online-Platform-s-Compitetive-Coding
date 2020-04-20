#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

void fastio(bool read = false){	
	if(read){
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

int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while(left <= right){
        int mid = (left + right)/2;
        int midElement = nums[mid], curLeft = nums[left], curRight = nums[right];
        
        // if target found, return the index
        if(midElement == target) return mid;
            
        // if middle element is less than the current left (mid element is in the right section of the rotation)
        if(midElement < curLeft){
            if (target <= curRight and target > midElement){
                // target is in the right of midElement
                left = mid +1;
            }
            else right = mid-1;
        }
            
        // if middle element is greater than the current right (mid element is in the left section of the rotation)
        else if(midElement > curRight){
            if (target >= curLeft and target < midElement){
                // target is in the left of midElement
                right = mid -1;
            }
            else left = mid +1;
        }
        // no rotation
        else{
            if(target > midElement) left = mid + 1;
            else right = mid -1;
        }
    }
    // value does not exist
    return -1;
}


int main(){
	fastio(true);
	int n,t;
	cin >> n;
	vector<int> nums(n,0);
	for(int i = 0; i < n; ++i) {
		cin >> nums[i];
	}	
	cin >> t;
	while(t--) {
		int target;
		cin >> target;
		cout << search(nums,target) << endl;
	}
	return 0;
}