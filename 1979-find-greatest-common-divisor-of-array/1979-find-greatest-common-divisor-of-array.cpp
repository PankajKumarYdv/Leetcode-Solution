class Solution {
public:
    int findGCD(vector<int>& nums) {
        auto [minElement, maxElement] = minmax_element(nums.begin(), nums.end()); 
        return gcd(*minElement, *maxElement); 
    }
};