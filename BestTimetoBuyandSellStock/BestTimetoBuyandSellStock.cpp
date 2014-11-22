
#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int> &prices) {
		if (prices.size() <= 1) return 0;
		
		/* postMax[i]存放i+1到end中的最大值，表示如果第i天买进，后面能卖出的最大值，
		postMax[size-1]为0因为后面无法卖出了。反向循环一次求得该数组，时间复杂度O(n)，
		有点类似于HMM的后向算法求beta */
		vector<int> postMax = {0};
		int max = prices[prices.size() - 1];
		for (int i = prices.size() - 2; i >= 0; i--) {
			postMax.insert(postMax.begin(), max);
			if (prices[i] > max) {
				max = prices[i];
			}
		}

		/* i表示买进的日期，prices[i]为买进价格，postMax[i]为可以卖出的最高价格 */
		int maxProfit = 0;
		for (int i = 0; i < prices.size() - 1; i++) {
			if (postMax[i] - prices[i] > maxProfit) {
				maxProfit = postMax[i] - prices[i];
			}
		}

		return maxProfit;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> vec = {1, 2};
	Solution sln;
	cout << "res : " << sln.maxProfit(vec) << endl;

	return 0;
}

