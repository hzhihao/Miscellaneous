#include "stdafx.h"
/*
	自定义的一个最小栈，只需要以O(1)的时间复杂度找到栈中元素的最小值
	将比较小的元素入栈两次 实现过程：
	开始将第一个元素入栈两次。
	之后，如果一个元素小于或等于栈顶元素，入栈两次；
	如果大于栈顶元素，将新的元素放在栈顶元素的下边（拿出栈顶元素，放进新元素，最终放进原栈顶元素）
*/
class MinStack
{
private:
	stack<int> stack;
public:
	MinStack()
	{
	}

	~MinStack()
	{
	}

	void push(int value) {
		if (stack.empty()) {
			stack.push(value);
			stack.push(value);
		}
		else {
			if (stack.top()<value) {
				int min = stack.top();
				stack.pop();
				stack.push(value);
				stack.push(min);
			}
			else {
				stack.push(value);
				stack.push(value);
			}

		}
	}

	void pop() {
		int min = stack.top();
		stack.pop();
		int top = stack.top();
		stack.pop();
		if (min<top) {
			stack.push(min);
		}

	}

	int top() {
		int min = stack.top();
		stack.pop();
		int top = stack.top();
		stack.push(min);
		return top;
	}

	int min() {
		return stack.top();
	}
};
