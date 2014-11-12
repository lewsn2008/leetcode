
#include <iostream>
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
	vector<int> postorderTraversal(TreeNode *root) {
		vector<int> res;
		if (NULL == root) return res;

		stack<TreeNode *> stk;
		/* p records the current node, q records the last visited node */
		TreeNode *p = root, *q;
		do {
			/* traverse to the end node of left sub-tree */
			while (p != NULL) {
				stk.push(p);
				p = p->left;
			}
			q = NULL;
			while (!stk.empty()) {			
				p = stk.top();
				stk.pop();
				/* if right child is the last visited node or NULL, 
				then visit the current node */
				if ((p->right == q) || (NULL == p->right)) {
					res.push_back(p->val);
					q = p;
				}
				else {
					/* the right child is not visited yet, push current node 
					again and set p to p->right */
					stk.push(p);
					p = p->right;
					/* IMPORTANT, break this while to recurser the right child */
					break;
				}
			}
		} while (!stk.empty());
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
	vector<int> res = sln.postorderTraversal(&n1);
	for (vector<int>::iterator it = res.begin(); it != res.end(); ++it) {
		cout << *it << ", ";
	}
	cout << endl;

	return 0;
}


