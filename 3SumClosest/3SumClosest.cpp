
#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
	typedef vector<int>::iterator vit;
public:
	int threeSumClosest(vector<int> &num, int target) {
		int closest = 0;
		bool closest_set = false;

		/* sort the vector num */
		sort(num.begin(), num.end());

		/* find consistent triplets and save to res, aȥnum[0]��num[len-2]��ÿһ��ֵ��
		b, cȡa+1��end��Ȼ�����м�л�����������֮��2.12���ƣ���ע������a,b,c��ǰһ��
		ֵ���ʱ����������������Ҫ����������Ч�ʣ����û��leetcode�ϻᳬʱ�� */
		for (vit a = num.begin(); a < prev(num.end(), 2); a++) {
			/* ���a��ǰһ��ֵ���˵���Ѿ��������ֱ������ */
			if ((a > num.begin()) && (*a == *(a - 1))) continue;
			vit b = next(a);
			vit c = prev(num.end());
			while (b < c) {
				/* ���b��ǰһ��ֵ���˵���Ѿ��������ֱ������ */
				if ((b != next(a)) && (*b == *(b - 1))) {
					++b;
					continue;
				}
				/* ͬ�� */
				if ((c != prev(num.end())) && (*c == *(c + 1))) {
					--c;
					continue;
				}
				/* update closest value */
				int sum = *a + *b + *c;
				if (!closest_set) {
					closest = sum;
					closest_set = true;
				}
				else {
					if (abs(sum - target) < abs(closest - target)) {
						closest = sum;
					}
				}
				/* move iterator */
				if (sum < target) {
					++b;
				}
				else if (sum > target) {
					--c;
				}
				else { // equal target
					return target;
				}
			}
		}

		return closest;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> vec = { 1, 1, -1, -1, 3 };
	Solution sln;
	int res = sln.threeSumClosest(vec, 3);
	cout << "res : " << res << endl;

	return 0;
}

