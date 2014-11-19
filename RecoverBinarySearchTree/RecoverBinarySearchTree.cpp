
#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void recoverTree(TreeNode *root) {
		pair<TreeNode *, TreeNode *> respair;
		/* find wrong nodes' pair */
		findWrongNode(root, respair);
		/* exchange the values of the pair */
		if ((respair.first != NULL) && (respair.second != NULL)) {
			int temp = respair.first->val;
			respair.first->val = respair.second->val;
			respair.second->val = temp;
		}
	}
private:
	/* use morris method to traverse the tree inorder, sava the current node and 
	previous node, when visit the current node, judge <cur, pre> pair is in order 
	or not, if not update wrong node in nodepair */
	void findWrongNode(TreeNode *root, pair<TreeNode *, TreeNode *> &nodepair) {
		TreeNode *cur, *pre, *temp;
		cur = root;
		pre = temp = NULL;
		while (cur != NULL) {
			if (NULL == cur->left) {
				/* visit node, so judge and update pair */
				updatePair(nodepair, cur, pre);
				pre = cur;
				cur = cur->right;
			}
			else {
				temp = cur->left;
				while ((temp->right != NULL) && (temp->right != cur)) {
					temp = temp->right;
				}
				if (NULL == temp->right) {
					temp->right = cur;
					cur = cur->left;
				}
				else {
					/* visit node, so judge and update pair */
					updatePair(nodepair, cur, pre);
					pre = cur;
					cur = cur->right;
					temp->right = NULL;
				}
			}
		}
	}
	void updatePair(pair<TreeNode *, TreeNode *> &nodepair, TreeNode *cur, TreeNode *pre) {
		if ((NULL == cur) || (NULL == pre)) return;
		/* judge values of <cur, pre> pair is in order */
		if (cur->val < pre->val) {
			if (NULL == nodepair.first) {
				nodepair.first = pre;
			}
			/* only need to update the second wrong node */
			nodepair.second = cur;
		}
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	/* test data, tree like :
	__________2
	_________/ \
	________3   1
	*/
	TreeNode n1(2);
	TreeNode n2(3);
	TreeNode n3(1);
	n1.left = &n2;
	n1.right = &n3;

	Solution sln;
	sln.recoverTree(&n1);

	return 0;
}

