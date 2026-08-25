class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
         unordered_set<int> num_set(nums.begin(), nums.end());
        
        int current_multiple = k;
        // Iterate through positive multiples of k
        while (num_set.count(current_multiple)) {
            current_multiple += k;
        }
        
        return current_multiple;
    }
};