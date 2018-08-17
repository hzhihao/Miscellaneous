#include "stdafx.h"
/*
	�Զ����һ����Сջ��ֻ��Ҫ��O(1)��ʱ�临�Ӷ��ҵ�ջ��Ԫ�ص���Сֵ
	���Ƚ�С��Ԫ����ջ���� ʵ�ֹ��̣�
	��ʼ����һ��Ԫ����ջ���Ρ�
	֮�����һ��Ԫ��С�ڻ����ջ��Ԫ�أ���ջ���Σ�
	�������ջ��Ԫ�أ����µ�Ԫ�ط���ջ��Ԫ�ص��±ߣ��ó�ջ��Ԫ�أ��Ž���Ԫ�أ����շŽ�ԭջ��Ԫ�أ�
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
