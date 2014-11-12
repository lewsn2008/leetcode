
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	/* fount the calculating rule, like : 
	easy to find : f(0) = 1, f(1) = 1,
	f(2) = f(0)*f(1) + f(1)*f(0)
	f(3) = f(0)*f(2) + f(1)*f(1) + f(2)*f(0)
	f(4) = f(0)*f(3) + f(1)*f(2) + f(2)*f(1) + f(3)*f(1)
	......
	*/
	int numTrees(int n) {
		if (n <= 1) return 1;
		vector<int> arr(n+1, 0);
		arr[0] = 1;
		arr[1] = 1;
		for (int i = 2; i <= n; ++i) {
			int sum = 0;
			for (int j = 0; j < i / 2; ++j) {
				sum += 2 * arr[j] * arr[i - j - 1];
			}
			/* for odd number, plus the middle item */
			sum += (i % 2) * arr[i / 2] * arr[i / 2];
			arr[i] = sum;
		}
		return arr[n];
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution sln;
	/* test data */
	for (int i = 0; i < 10; i++) {
		cout << i << " : " << sln.numTrees(i) << endl;
	}
	return 0;
}

