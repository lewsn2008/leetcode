
#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

const string strTable[10] = {
	"", "", "abc", "def", "ghi", "jkl",
	"mno", "pqrs", "tuv", "wxyz"
};

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		int dlen = digits.length();
		if (dlen < 1) return vector<string>() = {""};

		/* 各位数字相乘得到结果字符串的个数total */
		int total = 1;
		for (int i = 0; i < digits.length(); i++) {
			if (!iswdigit(digits[i])) return vector<string>() = { "" };
			total *= strTable[digits[i]-'0'].length();
		}

		/* i为第几个结果，用i对每个数字对应的字符串长度取余转换成序号串，
		例如：“23”，i=5转换为：12，表示取2的字符串的第1位，3的字符串的第2位 */
		vector<string> res;
		for (int i = 0; i < total; i++) {
			int v = i;
			string temp;
			for (int j = dlen - 1; j >= 0; j--) {
				string s = strTable[digits[j] - '0'];
				temp.insert(temp.begin(), s[v % s.length()]);
				v = v / s.length();
			}
			res.push_back(temp);
		}
		return res;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution sln;
	vector<string> res = sln.letterCombinations("23");
	for (vector<string>::iterator it = res.begin();
		it != res.end(); ++it) {
		cout << *it << endl;
	}
	return 0;
}

