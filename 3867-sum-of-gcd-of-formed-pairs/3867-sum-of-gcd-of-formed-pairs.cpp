class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size(); 
        vector<int> prefixSum; 

        int maxOfi = nums[0]; 
        for(int i = 0; i < n; i++){
            maxOfi = max(maxOfi, nums[i]); 
            prefixSum.push_back(gcd(nums[i], maxOfi)); 
        }

        sort(prefixSum.begin(), prefixSum.end()); 
        int l = 0; 
        int r = n-1; 
        long long sum = 0; 
        while(l < r){
            sum += gcd(prefixSum[l], prefixSum[r]); 
            l++; 
            r--; 
        }
        return sum; 
    }
};