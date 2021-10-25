

// https://leetcode.com/problems/path-sum-iii/

USING RECURSION:

class Solution {
public:
    int DFS(TreeNode *root,int sum){
        return root?(root->val==sum) + DFS(root->left,sum-root->val) + DFS(root->right,sum-root->val):0;
    }
    int pathSum(TreeNode* root, int sum) {
        return root? DFS(root,sum) + pathSum(root->left,sum) + pathSum(root->right,sum):0;
    }
};

USING MAP:

class Solution {
public:
    int nr = 0;                                               // This is our answer
    void dfs(TreeNode *node, int s, unordered_map <int, int> di, int sum) {
        if (!node) return;                                    // If we don't have any nodes in our path, we leave the recursion
        s += node->val;                                       // Every time we have a node with a value, we add its value to our 's'
        nr += di[s - sum];                                    // Our map maintains how many times we've already got a specific sum (left pointer). 's' is the right pointer. If we've got a left pointer with the value 's - sum', then we have a subpath with the sum 's - (s - sum)' = 'sum', which is what we need
        di[s] ++;                                             // Increase the number of left pointers which have the sum 's'
        dfs(node->left , s, di, sum);                         // Continue our path to the left
        dfs(node->right, s, di, sum);                         // Continue our path to the right
    }
    int pathSum(TreeNode* root, int sum) {
        dfs(root, 0, unordered_map <int, int> {{0, 1}}, sum); // We run a dfs from the root; See 'P.s.' for the 'unordered_map <int, int> {{0, 1}}' part
        return nr;                                            // return answer
    }
};