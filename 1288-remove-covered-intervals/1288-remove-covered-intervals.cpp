class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        auto compareIntervals = [](const vector<int>& left, const vector<int>& right) {
            return left[0] == right[0] ? left[1] > right[1]: left[0] < right[0];
        };

        sort(intervals.begin(), intervals.end(), compareIntervals);

        int totalRemaining = intervals.size();
        int maxRightBoundary = 0;

        for (const auto& current : intervals) {
            if (current[1] <= maxRightBoundary) {
                totalRemaining--;
            } else {
                maxRightBoundary = current[1];
            }
        }

        return totalRemaining;
    }
};