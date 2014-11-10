
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
	bool hasPathSum(TreeNode *root, int sum) {
		if (NULL == root) {
			return false;
		}
		/* the leaf node, return true node's value equals sum */
		if ((NULL == root->left) && (NULL == root->right) && (root->val == sum)) {
			return true;
		}
		/* recurse left child with (sum-root->val) */
		if ((root->left != NULL) && hasPathSum(root->left, sum - root->val) ){
			return true;
		}
		/* recurse right child with (sum-root->val) */
		if ((root->right != NULL) && hasPathSum(root->right, sum - root->val)){
			return true;
		}
		return false;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	/* test data, sum is 22, tree like : 
                   5
                  / \
                 4   8
                /   / \
               11  13  4
              /  \      \
             7    2      1
	*/
	TreeNode n1(5);
	TreeNode n2(4);
	TreeNode n3(8);
	TreeNode n4(11);
	TreeNode n5(13);
	TreeNode n6(4);
	TreeNode n7(7);
	TreeNode n8(2);
	TreeNode n9(1);

	n1.left = &n2;
	n1.right = &n3;
	n2.left = &n4;
	n3.left = &n5;
	n3.right = &n6;
	n4.left = &n7;
	n4.right = &n8;
	n6.right = &n9;

	Solution sln;
	if (sln.hasPathSum(&n1, 22)) {
		cout << "Yes, find it!" << endl;
	}
	else {
		cout << "No, can't find it!" << endl;
	}

	return 0;
}

