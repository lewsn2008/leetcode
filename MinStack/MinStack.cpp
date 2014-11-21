
#include "stdafx.h"
#include <stack>
#include <iostream>
using namespace std;

class MinStack {
public:
	void push(int x) {
		dataStack.push(x);
		if (minStack.empty()) {
			minStack.push(x);
		}
		else {
			if (x <= minStack.top()) {
				minStack.push(x);
			}
		}
	}
	void pop() {
		if (dataStack.empty()) {
			return;
		}
		int val = dataStack.top();
		dataStack.pop();
		if (val == minStack.top()) {
			minStack.pop();
		}
	}
	int top() {
		return dataStack.top();
	}
	int getMin() {
		return minStack.top();
	}
private:
	stack<int> dataStack;
	stack<int> minStack;
};

int _tmain(int argc, _TCHAR* argv[])
{
	MinStack stk;
	stk.push(0);
	stk.push(1);
	stk.push(0);
	int v1 = stk.getMin();
	stk.pop();
	int v2 = stk.getMin();
	cout << "v1 : " << v1 << ", v2 : " << v2 << endl;
	return 0;
}

