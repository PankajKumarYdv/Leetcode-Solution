struct SegmentTreeNode {
    int max_len;    // Length of the longest repeating substring within this segment
    int pref_len;   // Length of the repeating prefix from the left boundary
    int suff_len;   // Length of the repeating suffix from the right boundary
    char left_char;  // Character at the leftmost index of this segment
    char right_char; // Character at the rightmost index of this segment
    int size;       // Total number of elements covered by this segment
};

class SegmentTree {
private:
    vector<SegmentTreeNode> tree;
    int n;

    // Helper function to merge two adjacent segment nodes (left child and right child)
    SegmentTreeNode merge(const SegmentTreeNode& L, const SegmentTreeNode& R) {
        SegmentTreeNode parent;
        parent.size = L.size + R.size;
        parent.left_char = L.left_char;
        parent.right_char = R.right_char;
        
        // Base case: Default maximum length is the maximum of either child
        parent.max_len = max(L.max_len, R.max_len);
        parent.pref_len = L.pref_len;
        parent.suff_len = R.suff_len;

        // If the boundaries meet with the same character, we can bridge them
        if (L.right_char == R.left_char) {
            // The combined middle section forms a new potential maximum repeating block
            parent.max_len = max(parent.max_len, L.suff_len + R.pref_len);

            // If the left child is entirely composed of a single repeating character, 
            // the parent's prefix expands into the right child's prefix
            if (L.pref_len == L.size) {
                parent.pref_len = L.size + R.pref_len;
            }
            // Analogously, if the right child is entirely uniform, 
            // the parent's suffix expands back into the left child's suffix
            if (R.suff_len == R.size) {
                parent.suff_len = R.size + L.suff_len;
            }
        }

        return parent;
    }

    // Recursively build the tree from the initial string
    void build(int node, int start, int end, const string& s) {
        if (start == end) {
            tree[node] = {1, 1, 1, s[start], s[start], 1};
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid, s);
        build(2 * node + 1, mid + 1, end, s);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    // Recursively update a specific character index in the tree
    void update(int node, int start, int end, int idx, char val) {
        if (start == end) {
            tree[node] = {1, 1, 1, val, val, 1};
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

public:
    SegmentTree(const string& s) {
        n = s.size();
        tree.resize(4 * n);
        if (n > 0) {
            build(1, 0, n - 1, s);
        }
    }

    void update(int idx, char val) {
        update(1, 0, n - 1, idx, val);
    }

    int getMaxRepeating() {
        return tree[1].max_len;
    }
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int numQueries = queryCharacters.size();
        vector<int> result(numQueries);

        // Instantiate the Segment Tree with the original string configuration
        SegmentTree segTree(s);

        // Process each query step-by-step
        for (int i = 0; i < numQueries; i++) {
            int idx = queryIndices[i];
            char val = queryCharacters[i];

            // Perform dynamic point update in O(log N)
            segTree.update(idx, val);

            // Fetch global maximum from the root of the tree in O(1)
            result[i] = segTree.getMaxRepeating();
        }

        return result;
    }
};