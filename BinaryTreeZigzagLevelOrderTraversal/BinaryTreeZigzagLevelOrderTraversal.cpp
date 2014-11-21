
#include "stdafx.h"
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		vector<vector<int> > res;
		recurse(root, 1, res, true);
		return res;
	}
private:
	void recurse(TreeNode *root, int level, vector<vector<int> > &resvec, bool direction) {
		if (NULL == root) return;
		/* reach this level for the first time, create vector<int> at the end
		of resvec */
		if (level > resvec.size()) {
			resvec.push_back(vector<int>());
		}
		/* save current node's value to its own vector object resvec[level-1],
		insert differentiates with the direction */
		if (direction) {
			resvec[level - 1].push_back(root->val);
		}
		else {
			resvec[level - 1].insert(resvec[level - 1].begin(), root->val);
		}
		if (root->left != NULL) recurse(root->left, level + 1, resvec, !direction);
		if (root->right != NULL) recurse(root->right, level + 1, resvec, !direction);
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	/* test data, tree like :
	__________1
	_________/ \
	________2   3
	_________\  / \
	__________4 5  6
	________________\
	_________________7
	*/
	TreeNode n1(1);
	TreeNode n2(2);
	TreeNode n3(3);
	TreeNode n4(4);
	TreeNode n5(5);
	TreeNode n6(6);
	TreeNode n7(7);
	n1.left = &n2;
	n1.right = &n3;
	n2.right = &n4;
	n3.left = &n5;
	n3.right = &n6;
	n6.right = &n7;

	Solution sln;
	vector<vector<int> > res = sln.zigzagLevelOrder(&n1);

	return 0;
}

