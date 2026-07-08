class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // Sort the weights in ascending order
        sort(people.begin(), people.end()); 
        
        int l = 0; 
        int r = people.size() - 1; 
        int ans = 0; 

        // Process until the pointers cross
        while (l <= r) {
            // If the lightest and heaviest can share a boat
            if (people[l] + people[r] <= limit) {
                l++; // Lightest person gets on the boat
            }
            // The heaviest person always gets on a boat
            r--; 
            ans++; // Increment boat count
        }
        return ans; 
        
    }
};
