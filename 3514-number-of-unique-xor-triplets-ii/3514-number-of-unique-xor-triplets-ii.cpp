#include <unordered_set>
#include <vector>

class Solution {
public:
    int uniqueXorTriplets(std::vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s1; 
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                s1.insert(nums[i] ^ nums[j]); 
            }
        }

        unordered_set<int> s2; 
        for(int ele : s1){
            for(int i = 0; i < n; i++){
                s2.insert(nums[i] ^ ele); 
            }
        }

        return s2.size(); 
    }
};
