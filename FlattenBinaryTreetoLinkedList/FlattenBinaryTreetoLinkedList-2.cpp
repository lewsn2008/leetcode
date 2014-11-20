
#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	/* fantastic method, draw a graph to understand it */
	void flatten(TreeNode *root) {
		if (NULL == root) return;
		stack<TreeNode *> stk;
		stk.push(root);
		while (!stk.empty()) {
			TreeNode *p = stk.top();
			stk.pop();
			if (p->right != NULL) stk.push(p->right);
			if (p->left != NULL) stk.push(p->left);
			p->left = NULL;
			if (!stk.empty()) {
				p->right = stk.top();
			}
		}
	}
	/* print the processed result by traverse along right child */
	void rightTraverse(TreeNode *root) {
		cout << "Right traverse : ";
		while (root != NULL) {
			cout << root->val << " -> ";
			root = root->right;
		}
		cout << endl;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	/* test data, tree like :
	__________1
	________/   \
	_______2     3
	______/ \   / \
	_____4   5 6   7
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
	n2.left = &n4;
	n2.right = &n5;
	n3.left = &n6;
	n3.right = &n7;

	/* call function and print the result */
	Solution sln;
	sln.flatten(&n1);
	sln.rightTraverse(&n1);

	return 0;
}

