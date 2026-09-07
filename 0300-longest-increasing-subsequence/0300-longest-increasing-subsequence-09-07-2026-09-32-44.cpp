class Solution {
public:
    int t[2501][2501]; 
    int n; 
    int lengthOfLIS(vector<int>& nums) {
        memset(t, -1, sizeof(t)); 
        n = nums.size(); 
        return solve(nums, -1, 0); 
    }

    int solve(vector<int>& nums, int prev, int curr){
        if(curr == n) return 0; 
        if(prev != -1 && t[prev][curr] != -1){
            return t[prev][curr]; 
        }

        int taken = 0; 
        if(prev == -1 || nums[curr] > nums[prev]){
            taken = 1 + solve(nums, curr, curr+1); 
        }
        int notTaken = solve(nums, prev, curr+1); 
        if(prev != -1){
            t[prev][curr] = max(taken, notTaken); 
        }

        return max(taken, notTaken);
    }
};