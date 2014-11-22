// Triangle.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

/* 方法一：将triangle看成一个相似的二叉树，用二叉树递归的思想计算，该方法的问题是：
不能完全对应成二叉树，里面有很多节点都重复计算了（例如下面的例子中5即是3的右子树，又
是4的左子树）, leetcode会超时！*/
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

/* 方法二：迭代方法 */
class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		int level = triangle.size();
		if (level < 1) return 0;

		/* 从最底层往上迭代，用temp记录当前层每个节点（类似于二叉树）的子树最小和，
		迭代都最上层时，temp[0]就是结果 */
		vector<int> temp = triangle[level - 1];
		for (int l = level - 2; l >= 0; l--) {
			/* 第l层只有l+1个元素，注意该循环的边界 */
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

