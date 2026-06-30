class Solution {
public:
    /**
     * Calculates the length of the longest square-increasing subsequence.
     * The pattern follows a mountain shape: x, x^2, x^4, ... , x^(2^k), ... ,
     * x^4, x^2, x.
     */
    int maximumLength(vector<int>& nums) {
        // Find the upper bound to prevent unnecessary calculations beyond array
        // values
        const int ceiling = ranges::max(nums);

        // Map to track the frequency of each number for O(1) lookups
        unordered_map<int, int> freq;
        for (const int val : nums) {
            freq[val]++;
        }

        // Special handling for 1: Any even number of 1s forms a valid sequence,
        // but an odd number is required for the "peak" of the mountain.
        int longestSubseq =
            freq.contains(1) ? (freq[1] % 2 == 0 ? freq[1] - 1 : freq[1]) : 1;

        for (const int startNode : nums) {
            // 1 is handled separately; skip it here
            if (startNode == 1)
                continue;

            int chainDepth = 0;
            long currentVal = startNode;

            // Traverse the chain: x -> x^2 -> x^4 -> ...
            // We need at least two of each number to build the sides of the
            // mountain
            while (currentVal <= ceiling && freq.contains(currentVal) &&
                   freq[currentVal] >= 2) {
                chainDepth += 2;
                currentVal *= currentVal;
            }

            // After exiting the loop, currentVal is the potential peak.
            // If currentVal exists in the array, we add it as the peak (+1).
            // If not, the previous number in the sequence must serve as the
            // peak, effectively reducing the length by 1.
            int currentLength =
                chainDepth + (freq.contains(currentVal) ? 1 : -1);
            longestSubseq = max(longestSubseq, currentLength);
        }

        return longestSubseq;
    }
};