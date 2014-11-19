
#include <iostream>
using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (NULL == root) return;
		if ((NULL == root->left) || (NULL == root->right)) return;
		/* connect left child to right child */
		root->left->next = root->right;
		/* if root->next is non-null, connect right child to root->next->left */
		if (root->next != NULL) {
			root->right->next = root->next->left;
		}
		/* recurse of left and right child sub-tree */
		connect(root->left);
		connect(root->right);
	}
	/* use the next pointer to print elements level by level */
	void printLevel(TreeLinkNode *root) {
		int i = 0;
		for (TreeLinkNode *h = root; h != NULL; h = h->left) {
			TreeLinkNode *p = h;
			cout << "level " << i << " : ";
			while (p != NULL) {
				cout << p->val << " ";
				p = p->next;
			}
			cout << endl;
			++i;
		}
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
	TreeLinkNode n1(1);
	TreeLinkNode n2(2);
	TreeLinkNode n3(3);
	TreeLinkNode n4(4);
	TreeLinkNode n5(5);
	TreeLinkNode n6(6);
	TreeLinkNode n7(7);
	n1.left = &n2;
	n1.right = &n3;
	n2.left = &n4;
	n2.right = &n5;
	n3.left = &n6;
	n3.right = &n7;

	/* call function and print the result */
	Solution sln;
	sln.connect(&n1);
	sln.printLevel(&n1);

	return 0;
}

