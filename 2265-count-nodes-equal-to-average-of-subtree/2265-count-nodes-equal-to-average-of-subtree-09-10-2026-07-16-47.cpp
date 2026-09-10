/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int matchingNodesCount = 0;

    // Helper function that returns a pair: {sum_of_subtree, count_of_nodes_in_subtree}
    pair<int, int> calculateSubtree(TreeNode* node) {
        if (!node) {
            return {0, 0};
        }

        // Post-order traversal: Process left and right subtrees first
        auto [leftSum, leftCount] = calculateSubtree(node->left);
        auto [rightSum, rightCount] = calculateSubtree(node->right);

        // Calculate total sum and node count for the current subtree
        int totalSum = leftSum + rightSum + node->val;
        int totalCount = leftCount + rightCount + 1;

        // Perform integer division to find the average
        if (node->val == (totalSum / totalCount)) {
            matchingNodesCount++;
        }

        return {totalSum, totalCount};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        matchingNodesCount = 0; // Reset counter for multiple test cases
        calculateSubtree(root);
        return matchingNodesCount;
    }
};
