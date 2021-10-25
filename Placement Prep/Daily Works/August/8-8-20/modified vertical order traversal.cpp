

// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/submissions/

#define pii pair<int,int>   
class Solution { 
public:
    static bool compare(pii a,pii b){
        if(a.first > b.first) return 1;
        if(a.first < b.first) return 0;
        return a.second <= b.second;
    }
    
    void print(TreeNode* root,int hd,int vd,map<int,vector<pair<int,int>>> &mp){
        mp[hd].push_back(make_pair(vd,root->val));
        if(root->left)
            print(root->left,hd-1,vd-1,mp);
        if(root->right)
            print(root->right,hd+1,vd-1,mp);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>>mp;
        print(root,0,0,mp);
        vector<pair<int,int>>temp;vector<int>cur;
        vector<vector<int>>ans;
        for(auto a:mp){
            temp=a.second;
            cur.clear();
            sort(temp.begin(),temp.end(),compare);
            for(auto b:temp){
                cur.push_back(b.second);
            }
            ans.push_back(cur);
        }
        return ans;
    }
};