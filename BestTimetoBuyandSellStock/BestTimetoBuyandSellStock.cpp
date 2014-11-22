
#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int> &prices) {
		if (prices.size() <= 1) return 0;
		
		/* postMax[i]���i+1��end�е����ֵ����ʾ�����i����������������������ֵ��
		postMax[size-1]Ϊ0��Ϊ�����޷������ˡ�����ѭ��һ����ø����飬ʱ�临�Ӷ�O(n)��
		�е�������HMM�ĺ����㷨��beta */
		vector<int> postMax = {0};
		int max = prices[prices.size() - 1];
		for (int i = prices.size() - 2; i >= 0; i--) {
			postMax.insert(postMax.begin(), max);
			if (prices[i] > max) {
				max = prices[i];
			}
		}

		/* i��ʾ��������ڣ�prices[i]Ϊ����۸�postMax[i]Ϊ������������߼۸� */
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

