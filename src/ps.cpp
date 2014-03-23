/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //binary tree 想递归
 //非递归？ 使用stack转，递归时push stack
 //time limit out , bigger space!!!
 #include<cmath>
class Solution {
public:
	vector<vector<int> > l;
    void path(TreeNode *root, int sum, vector<int> v) {
    	if(root->left==NULL&&root->right==NULL)
    	{
    		if(sum==root->val)
    		{
    			v.push_back(root->val);
    			l.push_back(v);
    			return;
    		}
    		else 
    		{
    			return;
    		}
    	}
        v.push_back(root->val);
        if(root->left!=NULL)
        	path(root->left,sum-root->val,v);
        if(root->right!=NULL)
        	path(root->right,sum-root->val,v);
        
    }
    vector<vector<int> > pathSum(TreeNode *root,int sum){
    	
    	vector<int> v;
    	if(root==NULL)
    	{
    		
    		return l;
    	}
    	path(root,sum,v);
    	return l;
  	}
};
