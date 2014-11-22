
#include "stdafx.h"
#include <vector>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> res = {0, 0};
		map<int, int> hmap;
		for (int i = 0; i < numbers.size(); ++i) {
			if (hmap.count(target - numbers[i]) != 0) {
				res[0] = hmap[target - numbers[i]] + 1;
				res[1] = i + 1;
				break;
			}
			hmap.insert(pair<int, int>(numbers[i], i));
		}
		return res;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> vec = {3, 2, 4};
	int target = 6;
	Solution sln;
	vector<int> res = sln.twoSum(vec, target);
	cout << "<" << res[0] << ", " << res[1] << ">" << endl;

	return 0;
}

