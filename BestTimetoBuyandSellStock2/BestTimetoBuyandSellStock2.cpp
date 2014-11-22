
#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int> &prices) {
		int sum = 0;
		/* ֻҪ�����ǰһ��۸�ߣ��ͽ������뵽�������档������֪�� 
		����������������涼�ǿ��Ի�õġ� */
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

