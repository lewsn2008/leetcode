// CommonTest.cpp : 定义控制台应用程序的入口点。
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
	bool isSymmetric(TreeNode *root) {
		if (NULL == root) {
			return true;
		}
		else {
			return compareSub(root->left, root->right);
		}

	}
	bool compareSub(TreeNode *p, TreeNode *q) {
		if ((NULL == p) && (NULL == q)) return true;
		if ((p != NULL) && (q != NULL) && (p->val == q->val)) {
			return (compareSub(p->left, q->right) && compareSub(p->right, q->left));
		}
		return false;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

