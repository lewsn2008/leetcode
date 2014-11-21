
#include "stdafx.h"
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
	TreeNode *sortedArrayToBST(vector<int> &num) {
		return sortedArrayToBST(num, 0, num.size()-1);
	}
private:
	TreeNode *sortedArrayToBST(vector<int> &num, int start, int end) {
		if (start > end) return NULL;
		int mid = (end + start) / 2;
		TreeNode *root = new TreeNode(num[mid]);
		root->left = sortedArrayToBST(num, start, mid - 1);
		root->right = sortedArrayToBST(num, mid + 1, end);
		return root;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	/* test data */
	vector<int> arr = {1,2,3,4,5,6,7};
	Solution sln;
	TreeNode *tree = sln.sortedArrayToBST(arr);

	return 0;
}

