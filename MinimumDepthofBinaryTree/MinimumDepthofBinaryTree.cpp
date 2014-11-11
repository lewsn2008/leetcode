
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
	int minDepth(TreeNode *root) {
		if (NULL == root) return 0;
		int l, r, res;
		l = minDepth(root->left);
		r = minDepth(root->right);
		return ((0==l*r) ? ((l>r) ? l+1 : r+1) : ((l<r) ? l+1 : r+1));
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
	int mindepth = sln.minDepth(&n1);
	cout << "min depth : " << mindepth << endl;

	return 0;
}

