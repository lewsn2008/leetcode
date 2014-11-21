
#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;

class Solution1 {
	static const unsigned int MAX_NUM = 0x7fffffff;
	static const unsigned int MIN_NUM = 0x80000000;
public:
	int reverse(int x) {
		int sign = (x >= 0) ? 1 : -1;
		unsigned int ux = sign * x;
		unsigned int res = 0;
		while (ux != 0) {
			int rem = ux % 10;
			ux = ux / 10;
			if ( (sign > 0) && ((MAX_NUM / (float)10 < res) || (MAX_NUM - rem < res * 10)) ) {
				return 0;
			}
			if ( (sign < 0) && ((MIN_NUM / (float)10 < res) || (MIN_NUM - rem < res * 10)) ) {				
				return 0;
			}
			res = res * 10 + rem;
		}
		return sign * (int)res;
	}
};

class Solution {
public:
	int reverse(int x) {
		int ret = 0;
		while (x != 0) {
			/* handle overflow/underflow, and the official website post an question :
			"we do not need to check if ret == 214748364, why? ", 因为=214748364时，要
			溢出，末尾数必须是8或9，但是2147483648（9）反过来表示的原数早已溢出，也就是
			x不可能为这种情况！
			*/
			if (abs(ret) > 214748364) {
				return 0;
			}
			ret = ret * 10 + x % 10;
			x /= 10;
		}
		return ret;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	int a = 1563847412;
	int b = -123;
	Solution sln;
	cout << "reverse a : " << sln.reverse(a) << endl;
	cout << "reverse b : " << sln.reverse(b) << endl;

	return 0;
}

