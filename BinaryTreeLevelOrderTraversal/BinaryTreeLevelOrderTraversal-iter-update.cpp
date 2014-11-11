
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int> > levelOrder(TreeNode *root) {
		vector<vector<int> > resvec;
		if (NULL == root) return resvec;
		/* use queue to save nodes in the same level, two queues to
		use alternately as one is process the other is saving */
		queue<TreeNode *> q1, q2;
		vector<int> vecLevel;
		q1.push(root);
		while (!q1.empty()) {
			vecLevel.clear();
			while (!q1.empty()) {
				TreeNode *visit = q1.front();
				q1.pop();
				vecLevel.push_back(visit->val);
				if (visit->left != NULL) q2.push(visit->left);
				if (visit->right != NULL) q2.push(visit->right);
			}
			/* save to result */
			resvec.push_back(vecLevel);
			/* swap the two queues */
			q2.swap(q1);
		}
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	/* test data, tree like :
            1
           / \
          2   3
          \  / \
          4 5   6
                 \
                  7
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
	n2.right = &n4;
	n3.left = &n5;
	n3.right = &n6;
	n6.right = &n7;

	Solution sln;
	vector<vector<int> > res = sln.levelOrder(&n1);

	return 0;
}

