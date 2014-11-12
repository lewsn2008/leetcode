
#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	const int MIN_DEF = 0x80000000;
	const int MAX_DEF = 0x7FFFFFFF;
public:
	bool isValidBST(TreeNode *root) {
		return isValidBST(root, MIN_DEF, MAX_DEF);
	}
private:
	bool isValidBST(TreeNode *root, int low, int upper) {
		if (NULL == root) return true;
		return (root->val > low) && (root->val < upper)
			&& isValidBST(root->left, low, root->val)
			&& isValidBST(root->right, root->val, upper);
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	/* test data, tree like :
	__________5
	_________/
	________14
	_________\
	__________1
	*/
	TreeNode n1(5);
	TreeNode n2(14);
	TreeNode n3(1);
	n1.left = &n2;
	n2.left = &n3;

	Solution sln;
	if (sln.isValidBST(&n1)) {
		cout << "yes!" << endl;
	}
	else {
		cout << "no!" << endl;
	}

	return 0;
}

