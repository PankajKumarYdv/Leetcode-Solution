class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: (x[0], -x[1]))
        
        total_remaining = len(intervals)
        max_right_boundary = 0
        
        for current in intervals:
            current_end = current[1]
            
            if current_end <= max_right_boundary:
                total_remaining -= 1
            else:
                max_right_boundary = current_end
                
        return total_remaining