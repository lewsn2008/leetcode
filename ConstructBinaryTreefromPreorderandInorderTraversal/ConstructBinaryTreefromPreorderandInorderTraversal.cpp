
#include "stdafx.h"
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	typedef vector<int>::iterator vecit;
public:
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		return buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
	}
private:
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder, 
		int ps, int pe, int is, int ie) {
		if ((ps > pe) || (is > ie)) return NULL;
		/* assume two vector have the same size */
		if (preorder.size() != inorder.size()) return NULL;
		int curval = preorder[ps];
		/* find the index of the root node in the inorder vector */
		int in_root_pos = findPosInorder(inorder, curval);
		if (in_root_pos < 0) return NULL;
		/* length of the left sub-tree */
		int leftsize = in_root_pos - is;
		TreeNode *root = new TreeNode(curval);
		root->left = buildTree(preorder, inorder, ps + 1, ps + leftsize, is, in_root_pos - 1);
		root->right = buildTree(preorder, inorder, ps + leftsize + 1, pe, in_root_pos + 1, ie);
	}
	int findPosInorder(vector<int> &inorder, int val) {
		int i = 0;
		for (vecit it = inorder.begin(); it != inorder.end(); ++it,++i) {
			if (*it == val){
				return i;
			}
		}
		return -1;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

