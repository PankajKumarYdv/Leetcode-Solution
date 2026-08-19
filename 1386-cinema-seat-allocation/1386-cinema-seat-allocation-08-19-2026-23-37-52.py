class Solution:
    def maxNumberOfFamilies(self, n: int, reservedSeats: List[List[int]]) -> int:
        row_masks = defaultdict(int)
        for row, col in reservedSeats:
            if 2 <= col <= 9:
                row_masks[row] |= (1 << (col - 2))
        
        # Any fully empty row can fit exactly 2 groups
        max_groups = (n - len(row_masks)) * 2
        
        # Bitmasks for checking the three valid blocks
        # 11110000 -> columns 2,3,4,5
        # 00111100 -> columns 4,5,6,7
        # 00001111 -> columns 6,7,8,9
        left_mask = 0b11110000
        mid_mask  = 0b00111100
        right_mask = 0b00001111
        
        for mask in row_masks.values():
            left_free = (mask & left_mask) == 0
            right_free = (mask & right_mask) == 0
            
            if left_free and right_free:
                max_groups += 2
            elif left_free or right_free or (mask & mid_mask) == 0:
                max_groups += 1
                
        return max_groups