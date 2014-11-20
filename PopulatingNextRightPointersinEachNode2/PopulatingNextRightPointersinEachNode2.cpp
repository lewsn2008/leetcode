
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
		TreeLinkNode *temp, *sidenext;
		sidenext = NULL;
		temp = root->next;
		/* find the next node in current level by up-level node root */
		while (temp != NULL) {
			if (temp->left != NULL) {
				sidenext = temp->left;
				break;
			}
			if (temp->right != NULL) {
				sidenext = temp->right;
				break;
			}
			temp = temp->next;
		}
		if (root->right != NULL) {
			if (root->left != NULL) {
				/* left and right child both not NULL : connect left child 
				to right child */
				root->left->next = root->right;
			}
			/* right child not NULL : connect right->next to sidenext */
			root->right->next = sidenext;
		}
		else if (root->left != NULL) {
			/* only left child not NULL : connect left->next to sidenext */
			root->left->next = sidenext;
		}
		/* recurse of left and right child sub-tree */
		connect(root->right);
		connect(root->left);
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	/* test data, tree like :
	__________1
	________/   \
	_______2     3
	________\     \
	_________5     7
	*/
	TreeLinkNode n1(1);
	TreeLinkNode n2(2);
	TreeLinkNode n3(3);
	TreeLinkNode n5(5);
	TreeLinkNode n7(7);
	n1.left = &n2;
	n1.right = &n3;
	n2.right = &n5;
	n3.right = &n7;

	/* call function and print the result */
	Solution sln;
	sln.connect(&n1);

	return 0;
}

