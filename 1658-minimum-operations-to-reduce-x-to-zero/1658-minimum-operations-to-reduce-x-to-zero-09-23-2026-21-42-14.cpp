class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        
        // The sum we want to find in the middle subarray
        int target = totalSum - x;
        
        // If target is 0, we need to remove all elements
        if (target == 0) return nums.size();
        // If target is negative, it's impossible because all nums[i] >= 1
        if (target < 0) return -1;
        
        int currentSum = 0;
        int maxLen = -1;
        int left = 0;
        
        // Sliding window to find the longest subarray that sums to 'target'
        for (int right = 0; right < nums.size(); right++) {
            currentSum += nums[right];
            
            // Shrink the window from the left if the sum exceeds the target
            while (currentSum > target && left <= right) {
                currentSum -= nums[left];
                left++;
            }
            
            // If we find a valid subarray, record its maximum length
            if (currentSum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }
        
        // If maxLen was updated, the remaining elements are our answer
        return (maxLen == -1) ? -1 : nums.size() - maxLen;
    }
};
