
#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int> &prices) {
		int sum = 0;
		/* 只要当天比前一天价格高，就将差额加入到最终收益。分析可知， 
		所有相邻两天的收益都是可以获得的。 */
		for (int i = 1; i < prices.size(); i++) {
			int delta = prices[i] - prices[i - 1];
			if (delta > 0) {
				sum += delta;
			}
		}
		return sum;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> vec = {1, 3, 2, 8, 9, 9, 20};
	Solution sln;
	cout << "res : " << sln.maxProfit(vec) << endl;

	return 0;
}

