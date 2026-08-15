class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int total_xor = 0;
        bool has_non_zero = false;
        
        for (int num : nums) {
            total_xor ^= num;
            if (num != 0) {
                has_non_zero = true;
            }
        }
        
        if (!has_non_zero) return 0;
        if (total_xor != 0) return nums.size();
        
        return nums.size() - 1;
    }
};