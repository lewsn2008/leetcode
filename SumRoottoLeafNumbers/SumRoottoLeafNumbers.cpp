
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
	int sumNumbers(TreeNode *root) {
		int pre = 0, total = 0;
		if (NULL == root) {
			return 0;
		}
		sumNumbers(root, pre, total);
		return total;
	}
private:
	/* prefix is prefix numbers before current node in one path */
	void sumNumbers(TreeNode *root, int prefix, int &total) {
		/* sub is sum of nodes' value to current node */
		int sub = 10 * prefix + root->val;
		if ((root->left == NULL) && (root->right == NULL)) {
			total = total + sub;
			return;
		}
		/* recurse of the child nodes */
		if (root->left != NULL) sumNumbers(root->left, sub, total);
		if (root->right != NULL) sumNumbers(root->right, sub, total);
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	/* test data, tree like :
	__________1
	_________/ \
	________2   3
	*/
	TreeNode n1(1);
	TreeNode n2(2);
	TreeNode n3(3);
	n1.left = &n2;
	n1.right = &n3;

	Solution sln;
	int res = sln.sumNumbers(&n1);
	cout << "result is : " << res << endl;

	return 0;
}

