class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int prefix_sum = nums[0];
        
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1] + 1) {
                break;
            }
            prefix_sum += nums[i];
        }
        
        unordered_set<int> presence_map(nums.begin(), nums.end());
        
        while (presence_map.count(prefix_sum)) {
            prefix_sum++;
        }
        
        return prefix_sum;
    }
};


// Java Code 
