
#include "stdafx.h"

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	static const int MIN_VAL = 0x80000000;
public:
	ListNode *insertionSortList(ListNode *head) {
		/* 结果链表初始化一个空的头结点，为了第一次search时头结点不为空 */
		ListNode reshead(MIN_VAL);
		ListNode *cur = head;
		while (cur != NULL) {
			/* 在新链表中找到插入位置ipos，将cur节点插到ipos之后 */
			ListNode *ipos = searchInsertPos(&reshead, cur->val);
			ListNode *next = cur->next;
			cur->next = ipos->next;
			ipos->next = cur;
			cur = next;
		}
		/* 注意：这里返回的是reshead.next，去掉空的头结点，这里是一个
		技巧，不然要处理头结点的特殊情况 */
		return reshead.next;
	}
private:
	ListNode *searchInsertPos(ListNode *head, int x) {
		ListNode *pre = NULL, *cur;
		/* 注意：比较cur->val <= x时必须有=，因为head存的值0x80000000是最小的负数，
		如果链表中某个元素也为0x80000000，如果没有=指针就不会往后移动了，例如：
		leetcode中一个测试用例[-2147483647,-2147483648]就会出错 */
		for (cur = head; cur != NULL && cur->val <= x; pre = cur, cur = cur->next);
		return pre;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	ListNode n1(-2147483647);
	ListNode n2(0x80000000);
	n1.next = &n2;

	Solution sln;
	ListNode *res = sln.insertionSortList(&n1);

	return 0;
}

