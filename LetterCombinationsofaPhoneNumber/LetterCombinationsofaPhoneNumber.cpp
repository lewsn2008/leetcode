
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

		/* ��λ������˵õ�����ַ����ĸ���total */
		int total = 1;
		for (int i = 0; i < digits.length(); i++) {
			if (!iswdigit(digits[i])) return vector<string>() = { "" };
			total *= strTable[digits[i]-'0'].length();
		}

		/* iΪ�ڼ����������i��ÿ�����ֶ�Ӧ���ַ�������ȡ��ת������Ŵ���
		���磺��23����i=5ת��Ϊ��12����ʾȡ2���ַ����ĵ�1λ��3���ַ����ĵ�2λ */
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

