class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // rec = [x1, y1, x2, y2]
        
        // Check if rec2 is completely to the left of rec1
        bool isLeft = rec2[2] <= rec1[0];
        
        // Check if rec2 is completely to the right of rec1
        bool isRight = rec2[0] >= rec1[2];
        
        // Check if rec2 is completely below rec1
        bool isBelow = rec2[3] <= rec1[1];
        
        // Check if rec2 is completely above rec1
        bool isAbove = rec2[1] >= rec1[3];
        
        // If any of these are true, they do NOT overlap.
        // We also must ensure neither rectangle has an area of 0 (lines/points don't overlap)
        bool hasNoArea = (rec1[0] == rec1[2] || rec1[1] == rec1[3] || 
                          rec2[0] == rec2[2] || rec2[1] == rec2[3]);
        
        return !(isLeft || isRight || isBelow || isAbove || hasNoArea);
    }
};
