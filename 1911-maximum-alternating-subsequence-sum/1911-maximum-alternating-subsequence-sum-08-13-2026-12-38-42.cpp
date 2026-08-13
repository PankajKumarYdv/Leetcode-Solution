class Solution {
public:
    typedef long long ll; 
    /* //  Recursion and memorization 
    int n; 
    long long t[1000001][2]; 

    ll solve(int idx, vector<int>& nums, bool flag){
        if(idx >= n) return 0; 
        if(t[idx][flag] != -1) return t[idx][flag]; 

        ll skip = solve(idx+1, nums, flag); 
        ll val = nums[idx]; 

        if(flag == false) val = -val; 
        ll take = solve(idx+1, nums, !flag) + val; 
        return t[idx][flag] = max(skip, take); 
    }


    long long maxAlternatingSum(vector<int>& nums) {
        n = nums.size(); 
        memset(t, -1, sizeof(t)); 
        return solve(0, nums, true); 
    }

    */ 


    // Bottom up 
    long long maxAlternatingSum(vector<int>& nums){
        int n = nums.size(); 
        vector <vector<long>> t(n+1, vector<long>(2,0)); 
        for(int i = 1; i < n+1; i++){
            t[i][0] = max(t[i-1][1] - nums[i-1], t[i-1][0]); 
            t[i][1] = max(t[i-1][0] + nums[i-1], t[i-1][1]); 
        }

        return max(t[n][0], t[n][1]); 
    }
};