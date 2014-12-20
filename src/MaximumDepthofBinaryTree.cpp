#include <iostream>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode *root) {
     	if(root==NULL)
     		return 0;
     	else
     		return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
    int max(int a,int b)
    {
    	return a>=b?a:b;
    }
};
int main()
{
	TreeNode *root=new TreeNode(2);
	root->left=new TreeNode(3);
	Solution so;
	cout<<so.maxDepth(root);

}