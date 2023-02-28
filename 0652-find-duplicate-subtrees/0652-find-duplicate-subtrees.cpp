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
public:
    
    
    string encode(TreeNode* root,vector<TreeNode*> &ans,unordered_map<string,int> &freq)
    {
        if(root == NULL)
        {
            return "";
        }
        
        string left = encode(root->left,ans,freq);
        string right = encode(root->right,ans,freq);
        
        string curr = to_string(root->val) + "#" + left + "#" + right;
        
        freq[curr]++;
        
        if(freq[curr] == 2)
        {
            ans.push_back(root);
        }
        
        return curr;
        
        
    }
    
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        vector<TreeNode*> ans;
        unordered_map<string,int> freq;
        
        encode(root,ans,freq);
        
        return ans;
        
        
    }
};