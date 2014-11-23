
#include "stdafx.h"

struct ListNode {
    int val;
    ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode *sortedListToBST(ListNode *head) {
		int len = 0;
		/* calculate the lenght of the list */
		for (ListNode *p = head; p != NULL; p = p->next, len++);
		return sortedListToBST(head, 0, len - 1);
	}
private:
	/* recursive method the build tree with node between left to right.
	NOTE: there is a point could be improved : the argument left is always 
	zero so it can be removed */
	TreeNode *sortedListToBST(ListNode *&head, int left, int right) {
		if ((NULL == head) ||(left > right)) return NULL;
		/* get the middle node */
		int mid = (left + right) / 2;
		ListNode *p = head;
		for (int i = 0; i < mid; i++, p = p->next);
		/* create root node with the middle node's value */
		TreeNode *root = new TreeNode(p->val);
		/* recurse to build left and right sub-tree */
		root->left = sortedListToBST(head, left, mid - 1);
		root->right = sortedListToBST(p->next, 0, right - mid - 1);
		return root;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	ListNode n1(1);
	ListNode n2(3);
	n1.next = &n2;
	Solution sln;
	TreeNode *root = sln.sortedListToBST(&n1);

	return 0;
}

