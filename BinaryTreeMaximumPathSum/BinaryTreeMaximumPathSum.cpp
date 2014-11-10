
#include "stdafx.h"
#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/* Binary Tree creation interface */
/*
BOOL createBinaryTree(int &arr, TreeNode *root) {
	// not realized yet
}
*/

class Solution {
	const int MIN_MOST = 0x80000000;
public:
	int maxPathSum(TreeNode *root) {
		int maxSum = MIN_MOST;
		calSub(root, maxSum);
		return maxSum;
	}
	int calSub(TreeNode *root, int &max) {
		if (NULL == root) {
			return 0;
		}
		int lmax, rmax, tmpSumMax = root->val;
		lmax = calSub(root->left, max);
		tmpSumMax = (lmax > 0) ? (lmax + tmpSumMax) : tmpSumMax;
		rmax = calSub(root->right, max);
		tmpSumMax = (rmax > 0) ? (rmax + tmpSumMax) : tmpSumMax;
		if (tmpSumMax > max) {
			max = tmpSumMax;
		}
		int tmpPathMax = (lmax > rmax) ? (lmax + root->val) : (rmax + root->val);
		return (tmpPathMax > root->val) ? tmpPathMax : root->val;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	/* test data
	{9,6,-3,#,#,-6,2,#,#,2,#,-6,-6,-6}
	*/
	TreeNode n1 = TreeNode(-6);
	TreeNode n2 = TreeNode(-6);
	TreeNode n3 = TreeNode(-6);
	TreeNode n4 = TreeNode(2);
	TreeNode n5 = TreeNode(2);
	TreeNode n6 = TreeNode(-6);
	TreeNode n7 = TreeNode(-3);
	TreeNode n8 = TreeNode(6);
	TreeNode n9 = TreeNode(9);
	n2.left = &n1;
	n4.left = &n2;
	n4.right = &n3;
	n5.left = &n4;
	n7.left = &n6;
	n7.right = &n5;
	n9.left = &n8;
	n9.right = &n7;

	/* call Binary Tree creation interface */
	// createBinaryTree(...);

	Solution slt;
	int res = slt.maxPathSum(&n9);
	cout << "max : " << res << endl;
	return 0;
}

