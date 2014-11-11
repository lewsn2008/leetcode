
#include <iostream>
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
	vector<vector<int> > levelOrderBottom(TreeNode *root) {
		vector<vector<int> > res;
		recurse(root, 1, res);
		return res;
	}
private:
	void recurse(TreeNode *root, int level, vector<vector<int> > &resvec) {
		if (NULL == root) return;
		/* reach this level for the first time, create vector<int> at the end
		of resvec */
		if (level > resvec.size()) {
			vector<int> vec;
			resvec.insert(resvec.begin(),vec);
		}
		/* save current node's value to its own vector object in 
		resvec[resvec.size()-level], index is important */
		resvec[resvec.size()-level].push_back(root->val);
		if (root->left != NULL) recurse(root->left, level + 1, resvec);
		if (root->right != NULL) recurse(root->right, level + 1, resvec);
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
	vector<vector<int> > res = sln.levelOrderBottom(&n1);
	cout << "[";
	for (vector<vector<int> >::iterator it = res.begin(); it != res.end(); ++it) {
		vector<int> ivec = *it;
		cout << "[";
		for (vector<int>::iterator it2 = ivec.begin(); it2 != ivec.end(); ++it2) {
			cout << *it2 << ",";
		}
		cout << "]";
	}
	cout << "]";

	return 0;
}

