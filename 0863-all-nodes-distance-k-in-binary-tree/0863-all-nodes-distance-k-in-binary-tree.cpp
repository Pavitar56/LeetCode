/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    //TC = O(3*N)
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        unordered_map<TreeNode*,TreeNode*> map; //for tracking parent of each so node-> parent
        
        
        queue<pair<TreeNode*,TreeNode*>> q;
        q.push({root,NULL});
        map[root] = NULL; //parent of root = null
        
        
        //this queue doesnot need visited bcz we are always travelling down
        while(!q.empty())
        {
            TreeNode* node = q.front().first;
            TreeNode* parent = q.front().second;
            
            map[node] = parent;
            q.pop();
            
            
            if(node->left)
            {
                q.push({node->left,node});
            }
            
            if(node->right)
            {
                q.push({node->right,node});
            }
            
        }
        
        
        TreeNode* src = target;
        
        vector<int> ans;
        
        
        
        //{node,distance}
        unordered_map<TreeNode*,bool> visited;
        
        queue<pair<TreeNode*,int>> dist;
        dist.push({src,0});
        
        visited[src] = true;
        
        //this needs visited bcz we can go up too
        while(!dist.empty())
        {
            TreeNode* node = dist.front().first;
            int distance = dist.front().second;
            
            if(distance  > k)
            {
                break;
            }
            
            if(distance == k)
            {
                ans.push_back(node->val);
            }
            
            dist.pop();
            
            
            if(node->left && visited.count(node->left) == 0)
            {
                dist.push({node->left,distance+1});
                visited[node->left] = true;
            }
            
            if(node->right && visited.count(node->right) == 0)
            {
                dist.push({node->right,distance+1});
                visited[node->right] = true;
            }
            
            if(map[node] && visited.count(map[node]) == 0)
            {
                dist.push({map[node],distance+1});
                visited[map[node]] = true;
            }
      
        }
        
        
        return ans;
        
        
        
    }
};