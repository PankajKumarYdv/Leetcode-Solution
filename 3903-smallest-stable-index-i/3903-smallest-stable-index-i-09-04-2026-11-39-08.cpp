class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size(); 
        vector<int> minFromIndex(n);

        // Storing Minimum element
        int MIN = INT_MAX; 
        for(int i = n-1; i >= 0; i--){
            MIN = min(MIN, nums[i]); 
            minFromIndex[i] = MIN; 
        }

        
        int MAX = 0;
        for(int i = 0; i < n; i++){
            MAX = max(MAX, nums[i]); 
            if(MAX - minFromIndex[i] <= k){
                return i; 
            }
            
        }
        return -1; 
    }
};