/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // A critical point requires a previous and a next node to exist
        if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }

        int firstCriticalIdx = -1;
        int prevCriticalIdx = -1;
        int minDistance = INT_MAX;
        int currentIndex = 1; // Index 1 belongs to head->next

        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr->next != nullptr) {
            ListNode* nextNode = curr->next;

            // Check if current node is a local maximum or minimum
            bool isLocalMaxima = (curr->val > prev->val && curr->val > nextNode->val);
            bool isLocalMinima = (curr->val < prev->val && curr->val < nextNode->val);

            if (isLocalMaxima || isLocalMinima) {
                if (firstCriticalIdx == -1) {
                    firstCriticalIdx = currentIndex;
                } else {
                    // Update minDistance with the distance from the immediate previous critical point
                    minDistance = min(minDistance, currentIndex - prevCriticalIdx);
                }
                prevCriticalIdx = currentIndex;
            }

            // Advance the pointers
            prev = curr;
            curr = nextNode;
            currentIndex++;
        }

        // If we found fewer than 2 critical points, return {-1, -1}
        if (firstCriticalIdx == prevCriticalIdx) {
            return {-1, -1};
        }

        // The maximum distance is always between the very first and very last critical point
        int maxDistance = prevCriticalIdx - firstCriticalIdx;
        return {minDistance, maxDistance};
    }
};
