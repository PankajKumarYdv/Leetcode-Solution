class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        vector <int> resultArray; 
        if(n <= 1){
            return resultArray; 
        }
        sort(nums.begin(), nums.end()); 
        int smallestElemnt = nums[0]; 
        int largestElement = nums[n-1]; 
        int result = smallestElemnt+1; 
        int ptr = 1; 

        while(result < largestElement){
            if(result == nums[ptr]){
                result++; 
                ptr++; 
            }else{
                resultArray.push_back(result); 
                result++; 
            }
        }

        return resultArray; 
    }
};