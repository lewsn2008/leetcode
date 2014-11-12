
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	~Solution() {
		/* release tree created by new operaator */
		for (auto p : m_res) {
			releaseTree(p);
		}
	}
	vector<TreeNode *> generateTrees(int n) {
		m_res = generateTrees(1, n);
		return m_res;
	}
private:
	vector<TreeNode *> generateTrees(int start, int end) {
		vector<TreeNode *> res;
		if (start > end) {
			res.push_back(NULL);
			return res;
		}
		/* loop for every node(i) as the root */
		for (int i = start; i <= end; i++) {
			/* generate left sub-tree with node (start ... i-1) */
			/* generate right sub-tree with node (i+1 ... end) */
			vector<TreeNode *> lArr = generateTrees(start, i - 1);
			vector<TreeNode *> rArr = generateTrees(i + 1, end);
			/* create root node, and connect the left child and the right 
			child selected from every pair of (p,q) in lArr and rArr */
			for (auto p : lArr) {
				for (auto q : rArr) {
					TreeNode *root = new TreeNode(i);
					root->left = p;
					root->right = q;
					res.push_back(root);
				}
			}
		}
		return(res);
	}
	void releaseTree(TreeNode *root) {
		if (NULL == root) return;
		releaseTree(root->left);
		releaseTree(root->right);
		delete root; root = NULL;
	}
private:
	vector<TreeNode *> m_res;
};

int _tmain(int argc, _TCHAR* argv[])
{
	/* testing code are not completed */
	return 0;
}

