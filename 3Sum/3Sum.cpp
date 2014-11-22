// 3Sum.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	typedef vector<int>::iterator vit;
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int> > res;
		if (num.size() < 3) return res;
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
				if (*a + *b + *c < 0) {
					++b;
				}
				else if (*a + *b + *c > 0) {
					--c;
				}
				else {
					vector<int> tv = { *a, *b, *c };
					res.push_back(tv);
					++b;
					--c;
				}
			}
		}
		// remove duplicate triplets ------------------------------
		sort(res.begin(), res.end());
		/* Note the unique function, it should be used along with erase */
		res.erase(unique(res.begin(), res.end()), res.end());
		//---------------------------------------------------------
		return res;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> vec = { 7, -1, 14, -12, -8, 7, 2, -15, 8, 8, -8, -14, -4, -5, 7, 9, 11, -4, -15, -6, 1, -14, 4, 3, 10, -5, 2, 1, 6, 11, 2, -2, -5, -7, -6, 2, -15, 11, -6, 8, -4, 2, 1, -1, 4, -6, -15, 1, 5, -15, 10, 14, 9, -8, -6, 4, -6, 11, 12, -15, 7, -1, -9, 9, -1, 0, -4, -1, -12, -2, 14, -9, 7, 0, -3, -4, 1, -2, 12, 14, -10, 0, 5, 14, -1, 14, 3, 8, 10, -8, 8, -5, -2, 6, -11, 12, 13, -7, -12, 8, 6, -13, 14, -2, -5, -11, 1, 3, -6 };
	Solution sln;
	vector<vector<int> > res;
	res = sln.threeSum(vec);

	return 0;
}

