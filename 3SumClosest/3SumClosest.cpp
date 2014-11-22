
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

		/* find consistent triplets and save to res, a去num[0]到num[len-2]的每一个值，
		b, c取a+1和end，然后往中间夹击（这里与编程之美2.12相似），注意其中a,b,c与前一个
		值相等时跳过，这个处理很重要，可以提升效率，如果没有leetcode上会超时。 */
		for (vit a = num.begin(); a < prev(num.end(), 2); a++) {
			/* 如果a与前一个值相等说明已经计算过，直接跳过 */
			if ((a > num.begin()) && (*a == *(a - 1))) continue;
			vit b = next(a);
			vit c = prev(num.end());
			while (b < c) {
				/* 如果b与前一个值相等说明已经计算过，直接跳过 */
				if ((b != next(a)) && (*b == *(b - 1))) {
					++b;
					continue;
				}
				/* 同上 */
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

