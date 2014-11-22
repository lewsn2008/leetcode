// Triangle.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

/* ����һ����triangle����һ�����ƵĶ��������ö������ݹ��˼����㣬�÷����������ǣ�
������ȫ��Ӧ�ɶ������������кܶ�ڵ㶼�ظ������ˣ����������������5����3������������
��4����������, leetcode�ᳬʱ��*/
class Solution1 {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		return minimumTotal(triangle, 0, 0);
	}
private:
	int minimumTotal(vector<vector<int> > &triangle, int level, int root) {
		int val = triangle[level][root];
		if (level == triangle.size() - 1) {
			return val;
		}
		int lmin = minimumTotal(triangle, level + 1, root);
		int rmin = minimumTotal(triangle, level + 1, root + 1);
		return (lmin < rmin) ? (lmin + val) : (rmin + val);
	}
};

/* ���������������� */
class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		int level = triangle.size();
		if (level < 1) return 0;

		/* ����ײ����ϵ�������temp��¼��ǰ��ÿ���ڵ㣨�����ڶ���������������С�ͣ�
		���������ϲ�ʱ��temp[0]���ǽ�� */
		vector<int> temp = triangle[level - 1];
		for (int l = level - 2; l >= 0; l--) {
			/* ��l��ֻ��l+1��Ԫ�أ�ע���ѭ���ı߽� */
			for (int i = 0; i < l + 1; i++) {
				int min = (temp[i] < temp[i + 1]) ? temp[i] : temp[i + 1];
				temp[i] = min + triangle[l][i];
			}
		}		
		return temp[0];
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> v1 = { 2 };
	vector<int> v2 = { 3, 4 };
	vector<int> v3 = { 6, 5, 7 };
	vector<int> v4 = { 4, 1, 8, 3 };
	vector<vector<int> > tri;
	tri.push_back(v1);
	tri.push_back(v2);
	tri.push_back(v3);
	tri.push_back(v4);

	Solution sln;
	int min = sln.minimumTotal(tri);
	cout << "res : " << min << endl;

	return 0;
}

