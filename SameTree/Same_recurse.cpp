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
	bool isSameTree(TreeNode *p, TreeNode *q) {
		if ((NULL == p) && (NULL == q)) return true;
		if ((p != NULL) && (q != NULL) && (p->val == q->val)) {
			return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
		}
		return false;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

