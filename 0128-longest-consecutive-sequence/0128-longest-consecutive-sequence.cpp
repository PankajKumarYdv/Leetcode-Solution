class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Insert all numbers into a hash set
        unordered_set<int> num_set(nums.begin(), nums.end());
        int longest_streak = 0;

        for (int num : num_set) {
            // Check if 'num' is the start of a sequence
            // If num - 1 exists, 'num' is not the start
            if (num_set.find(num - 1) == num_set.end()) {
                int current_num = num;
                int current_streak = 1;

                // Count the length of the sequence
                while (num_set.find(current_num + 1) != num_set.end()) {
                    current_num += 1;
                    current_streak += 1;
                }

                // Update the maximum length found
                longest_streak = max(longest_streak, current_streak);
            }
        }

        return longest_streak;
    }
};
