// BalancedBinaryTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
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
	bool isBalanced(TreeNode *root) {
		int depth;
		return recurse(root, depth);
	}
private:
	bool recurse(TreeNode *root, int &depth) {
		if (NULL == root) {
			depth = 0;
			return true;
		}
		int ld, rd;
		/* if sub-tree is not balanced tree, then neither the root */
		if (!recurse(root->left, ld) || !recurse(root->right, rd)) return false;
		/* the difference between left and right is more than 1 */
		if (((ld - rd) > 1) || ((rd - ld) > 1)) return false;
		/* update and return the depth of root, the depth is MAX(ld,rd)+1 */
		depth = (ld > rd) ? (ld + 1) : (rd + 1);
		return true;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	/* test data, tree like :
	__________1
	_________/ \
	________2   3
	_______/ \
	______4   5
	*/
	TreeNode n1(1);
	TreeNode n2(2);
	TreeNode n3(3);
	TreeNode n4(4);
	TreeNode n5(5);
	n1.left = &n2;
	n1.right = &n3;
	n2.left = &n4;
	n2.right = &n5;

	Solution sln;
	if (sln.isBalanced(&n1)) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}

	return 0;
}

