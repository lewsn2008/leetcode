// CommonTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int> > pathSum(TreeNode *root, int sum) {
		vector<vector<int> > resVec;
		vector<int> tmpVec;
		recurse(root, sum, resVec, tmpVec);
		return resVec;
	}
private:
	void recurse(TreeNode *root, int sum, vector<vector<int> > &res, vector<int> &tmp) {
		if (NULL == root) return;

		tmp.push_back(root->val);

		/* the leaf node */
		if ((NULL == root->left) && (NULL == root->right) && (root->val == sum)) {
			res.push_back(tmp);	// find it, push to the resVec
		}
		/* recurse left child with (sum-root->val) */
		recurse(root->left, sum - root->val, res, tmp);
		/* recurse right child with (sum-root->val) */
		recurse(root->right, sum - root->val, res, tmp);

		tmp.pop_back();
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
	vector<vector<int> > resvec = sln.pathSum(&n1, 22));

	return 0;
}

