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
    
    TreeNode* lowestCommonAncestor(TreeNode* root, int startValue, int destValue)
    {
        if(root == NULL)
        {
            return NULL;
        }
        
        if(root->val == startValue || root->val == destValue)
        {
            return root;
        }
        
        TreeNode* lcaLeft = lowestCommonAncestor(root->left,startValue,destValue);
        TreeNode* lcaRigth = lowestCommonAncestor(root->right,startValue,destValue);
        
        
        if(lcaLeft != NULL && lcaRigth != NULL)
        {
            return root;
        }
        
        if(lcaLeft != NULL)
        {
            return lcaLeft;
        }
        
        return lcaRigth;
        
        
    }
    
    
    vector<pair<TreeNode*,char>> FindPath(TreeNode* root, int target)
    {
        if(root == NULL)
        {
            return {};
        }
        
        if(root -> val == target)
        {
            pair<TreeNode*,char> p1;
            p1.first = root;
            p1.second = '@';  //dummy val to show we found it
            
            return {p1};
        }
        
        vector<pair<TreeNode*,char>> leftPath = FindPath(root->left , target);
        vector<pair<TreeNode*,char>> rightPath = FindPath(root->right , target);
        
        vector<pair<TreeNode*,char>> ans;
        
        if(leftPath.size()==0 && rightPath.size() != 0)
        {
//             ans.push_back({root,'R'});
            
//             for(int i=0;i<rightPath.size();i++)
//             {
//                 ans.push_back({rightPath[i].first,rightPath[i].second});
//             }
//             return ans;
            
            rightPath.push_back({root,'R'});
            return rightPath;
        }
        
        if(rightPath.size() == 0 && leftPath.size() != 0)
        {
//             ans.push_back({root,'L'});
            
//             for(int i=0;i<leftPath.size();i++)
//             {
//                 ans.push_back({leftPath[i].first,leftPath[i].second});
//             }
//             return ans;
            
            leftPath.push_back({root,'L'});
            return leftPath;
        }
        
        
        return {};
    }
    
    
    
    string getDirections(TreeNode* root, int startValue, int destValue)
    {
        
        TreeNode* lca = lowestCommonAncestor(root,startValue,destValue);
        
      //  cout<<lca->val<<endl;
        
        vector<pair<TreeNode*,char>> path1 = FindPath(lca,startValue);
        
        vector<pair<TreeNode*,char>> path2 = FindPath(lca,destValue);
        
//         for(int k=0;k<path1.size();k++)
//         {
//             cout<<path1[k].first->val<<" "<<path1[k].second<<" ";
//         }
//         cout<<endl;
        
//         for(int k=0;k<path2.size();k++)
//         {
//             cout<<path2[k].first->val<<" "<<path2[k].second<<" ";
//         }
        
//         cout<<endl;
        
        
        reverse(path1.begin(),path1.end());
        reverse(path2.begin(),path2.end());
        string ans="";
        
        
        int i = path1.size() - 1;;
        while(i >= 0 && path1[i].first != lca)
        {
            ans += 'U';
            i--;
        }
        
        int j = 0;
        
        while(j < path2.size())
        {
            if(path2[j].first == lca)
            {
                
                while(j < path2.size()-1)   // -1 because we dont want to include dest val path which                                                   is just dummy
                {
                    ans += path2[j].second;
                    j++;
                }
            }
            
            j++;
        }
        
        
        return ans;
        
    }
};