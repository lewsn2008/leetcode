
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
		/* ��������ʼ��һ���յ�ͷ��㣬Ϊ�˵�һ��searchʱͷ��㲻Ϊ�� */
		ListNode reshead(MIN_VAL);
		ListNode *cur = head;
		while (cur != NULL) {
			/* �����������ҵ�����λ��ipos����cur�ڵ�嵽ipos֮�� */
			ListNode *ipos = searchInsertPos(&reshead, cur->val);
			ListNode *next = cur->next;
			cur->next = ipos->next;
			ipos->next = cur;
			cur = next;
		}
		/* ע�⣺���ﷵ�ص���reshead.next��ȥ���յ�ͷ��㣬������һ��
		���ɣ���ȻҪ����ͷ����������� */
		return reshead.next;
	}
private:
	ListNode *searchInsertPos(ListNode *head, int x) {
		ListNode *pre = NULL, *cur;
		/* ע�⣺�Ƚ�cur->val <= xʱ������=����Ϊhead���ֵ0x80000000����С�ĸ�����
		���������ĳ��Ԫ��ҲΪ0x80000000�����û��=ָ��Ͳ��������ƶ��ˣ����磺
		leetcode��һ����������[-2147483647,-2147483648]�ͻ���� */
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

