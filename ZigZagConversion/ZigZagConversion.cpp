
#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	string convert(string s, int nRows) {
		/* temp string array to save every row */
		string *strTempArr = new string[nRows];
		/* step control the direction, -1 means up-ward, 1 means down-ward */
		int step = -1;
		/* get char from origin sequence and put to corresponding row by order */
		for (int i = 0,row = 0; i < s.length(); i++) {
			char c = s[i];
			strTempArr[row].push_back(c);
			/* hit the top or bottom row, change the direction */
			if ((row == 0) || (row == nRows - 1)) {
				step = step * (-1);
			}
			/* move by increasing with step */
			row = (row + step) % nRows;
		}
		string res;
		/* join temp strings of every row */
		for (int i = 0; i < nRows; i++) {
			res += strTempArr[i];
		}
		delete[] strTempArr;
		return res;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution sln;
	string res = sln.convert("PAYPALISHIRING", 3);
	cout << "res : " << res << endl;

	res = sln.convert("ABCDEF", 2);
	cout << "res : " << res << endl;

	return 0;
}

