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
#define ll long long int
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,ll>> q;
        q.push({root,0});
        int n;
        pair<TreeNode*,ll> p;
        ll ans = 1;
        while(!q.empty()){
            n = q.size();
            ll a=0,b,c=q.front().second;
            for(int i = 0; i < n; i++){
                p = q.front();
                q.pop();
                if(p.first->left){
                    q.push({p.first->left,(p.second-c)*1LL*2});
                }
                if(p.first->right){
                    q.push({p.first->right,(p.second-c)*1LL*2+1});
                }
                
                if(i==0){
                    a = (p.second);
                }
                if(i==n-1){
                    b = (p.second);
                }
            }
            ans = max(ans,b-a+1);
        }
        return ans;
    }
};