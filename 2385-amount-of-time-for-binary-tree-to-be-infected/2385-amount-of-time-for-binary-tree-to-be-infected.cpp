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
    int amountOfTime(TreeNode* root, int start) {
        
        
        unordered_map<TreeNode*,TreeNode*> map; //for tracking parent of each so node-> parent
        
        
        queue<pair<TreeNode*,TreeNode*>> q;
        q.push({root,NULL});
        map[root] = NULL; //parent of root = null
        
        
        
        TreeNode* src = NULL;
        
        //this queue doesnot need visited bcz we are always travelling down
        while(!q.empty())
        {
            TreeNode* node = q.front().first;
            TreeNode* parent = q.front().second;
            
            if(node -> val == start)
            {
                src = node;
            }
            
            
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
        
        
        
      
        int ans = INT_MIN;
        //{node,time}
        unordered_map<TreeNode*,bool> visited;
        
        queue<pair<TreeNode*,int>> q2;
        q2.push({src,0});
        
        visited[src] = true;
        
        //this needs visited bcz we can go up too
        while(!q2.empty())
        {
            TreeNode* node = q2.front().first;
            int time = q2.front().second;
            
         
            q2.pop();
            
            ans = max(ans,time);
          
            if(node->left && visited.count(node->left) == 0)
            {
                q2.push({node->left,time+1});
                visited[node->left] = true;
            }
            
            if(node->right && visited.count(node->right) == 0)
            {
                q2.push({node->right,time+1});
                visited[node->right] = true;
            }
            
            if(map[node] && visited.count(map[node]) == 0)
            {
                q2.push({map[node],time+1});
                visited[map[node]] = true;
            }
            
            
            
        }
        
        
        return ans;
        
        
        
        
        
        
        
    }
};