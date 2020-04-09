class Solution {
public:
    // We ahve been using the unordered map to keep track of 
    // Previously read elements and there index.
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        vector<int> res;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            if(mp.find(target-nums[i]) != mp.end()) {
                res.push_back(mp[target-nums[i]]);
                res.push_back(i);
                break;
            } else {
                mp[nums[i]] = i;
            }
        }
        return res;
    }
};