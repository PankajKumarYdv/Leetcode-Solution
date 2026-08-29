class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        
        // Step 1: Pair each number with its original index and sort by values
        vector<pair<int, int>> sorted_pairs(n);
        for (int i = 0; i < n; ++i) {
            sorted_pairs[i] = {nums[i], i};
        }
        sort(sorted_pairs.begin(), sorted_pairs.end());
        
        vector<int> ans(n);
        int i = 0;
        
        // Step 2: Identify and process connected components (groups)
        while (i < n) {
            int j = i + 1;
            // Extend the group as long as the difference between adjacent elements <= limit
            while (j < n && sorted_pairs[j].first - sorted_pairs[j - 1].first <= limit) {
                j++;
            }
            
            // Extract original indices for the current group
            vector<int> original_indices;
            for (int k = i; k < j; ++k) {
                original_indices.push_back(sorted_pairs[k].second);
            }
            
            // Sort indices so we can place smaller values in earlier positions
            sort(original_indices.begin(), original_indices.end());
            
            // Step 3: Reassign sorted values to sorted indices
            for (int k = 0; k < original_indices.size(); ++k) {
                ans[original_indices[k]] = sorted_pairs[i + k].first;
            }
            
            // Move pointer to the next group
            i = j;
        }
        
        return ans;
    }
};