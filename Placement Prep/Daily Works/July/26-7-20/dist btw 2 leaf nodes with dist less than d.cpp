
// distance btw 2 leaf nodes with distance less tha d

class Solution {
private:
    int total;
    vector<int> dfs (TreeNode *root, int d) {
        if (!root->left && !root->right) return {0};
        
        vector<int> l, r;
        if (root->left) l = dfs(root->left, d);
        if (root->right) r = dfs(root->right, d);
        vector<int> ans;
        for (int a : l) {
            for (int b : r) {
                if (a + b + 2 <= d) total++;
            }
        }
        for (int a : l) {
            ans.push_back(a+1);
        }
        for (int b : r) {
            ans.push_back(b+1);
        }
        return ans;
    }
public:
    int countPairs(TreeNode* root, int distance) {
        total = 0;
        dfs(root, distance);
        return total;
    }
};