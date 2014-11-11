
#include <vector>
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
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> res;
		if (NULL == root) return res;

		stack<const TreeNode *> stk;
		stk.push(root);
		while (!stk.empty()) {
			const TreeNode *p = stk.top();
			stk.pop();
			res.push_back(p->val);		
			if (p->right != NULL) stk.push(p->right);
			if (p->left != NULL) stk.push(p->left);
		}
		return res;
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
	vector<int> res = sln.preorderTraversal(&n1);
	
	return 0;
}

