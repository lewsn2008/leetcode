
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
	vector<int> inorderTraversal(TreeNode *root) {
		vector<int> res;
		stack<const TreeNode *> stk;
		const TreeNode *p = root;
		while (!stk.empty() || (p != NULL)) {
			if (p != NULL) {
				stk.push(p);
				p = p->left;
			}
			else {
				p = stk.top(); stk.pop();
				res.push_back(p->val);
				p = p->right;				
			}
		}
		return res;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

