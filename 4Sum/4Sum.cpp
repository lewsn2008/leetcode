
#include "stdafx.h"
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > fourSum(vector<int> &num, int target) {
		vector<vector<int> > res;
		if (num.size() < 4) return res;

		sort(num.begin(), num.end());
		for (int i = 0; i < num.size() - 3; i++) {
			if ((i>0) && (num[i] == num[i - 1])) continue;
			for (int j = i + 1; j < num.size() - 2; j++) {
				if ((j > i + 1) && (num[j] == num[j - 1])) continue;
				int p = j + 1;
				int q = num.size() - 1;
				while (p < q) {
					if ((p > j + 1) && (num[p] == num[p - 1])) {
						++p;
						continue;
					}
					if ((q < num.size() - 1) && (num[q] == num[q + 1])) {
						--q;
						continue;
					}
					if (num[i] + num[j] + num[p] + num[q] < target) {
						++p;
					}
					else if (num[i] + num[j] + num[p] + num[q] > target) {
						--q;
					}
					else {
						res.push_back(vector<int>() = {num[i], num[j], num[p], num[q] });
						++p;
						--q;
					}
				}
			}
		}
		return res;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> vec = {0, 0, 0, 0};
	Solution sln;
	vector<vector<int> > res = sln.fourSum(vec, 0);

	return 0;
}

