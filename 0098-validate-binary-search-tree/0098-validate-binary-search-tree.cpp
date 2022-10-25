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
    
    
    class Pair
    {
        public:
        long long int maximum;
        long long int minimum;
        bool isTree;
        
        Pair()
        {
            maximum = -pow(2,31) - 1;
            minimum = pow(2,31) + 1;
            isTree = true;
        }
        
    };
    
    
    Pair isBst(TreeNode* root)
    {
        if(root == NULL)
        {
            Pair p1;
            return p1;
        }
        
        Pair left = isBst(root->left);
        
        Pair right = isBst(root->right);
        
        Pair ans;
        int maxTotal;
        int minTotal;
        
        if(root->val > left.maximum && root->val > right.maximum)
        {
            maxTotal = root->val; 
        }
        else
        {
            maxTotal = max(left.maximum,right.maximum);
        }
        
        if(root->val < left.minimum && root->val < right.minimum)
        {
            minTotal = root->val;
        }
        else
        {
            minTotal = min(left.minimum,right.minimum);
        }
        
        
        bool treeCheck;
        
        if(left.isTree == false || right.isTree == false || root->val <= left.maximum ||                                     root->val >= right.minimum)
        {
            treeCheck = false;
        }
        else
        {
            treeCheck = true;
        }
        
        ans.minimum = minTotal;
        ans.maximum = maxTotal;
        ans.isTree = treeCheck;
        
        return ans;
    }
    
    
    
    
    
    bool isValidBST(TreeNode* root)
    {
       
        return isBst(root).isTree;
    }
};