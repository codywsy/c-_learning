#pragma once
#include <stack>
#include <exception>

template <typename T> class CQueue{
public:
	CQueue(void);
	~CQueue(void);	//’‚ « ≤√¥£ø

	void appenTail(const T& node);
	T deleteHead();

private:
	stack<T> stack1;
	stack<T> stack2;
};

template <typename T> CQueue<T>::CQueue(void)
{
}

template <typename T> CQueue<T>::~CQueue(void)
{
}

template <typename T> void CQueue<T>::appenTail(const T& node)
{
	stack1.push(node);
}

template <typename T> T CQueue<T>::deleteHead(void)
{
	if(stack2.size() <= 0)
	{
		while(stack1.size() > 0)
		{
			T& node = stack1.top();	//reference is a pointer, essentially.
			stack1.pop();
			stack2.push(node);
		}
	}

	if(stack2.size() == 0)
	{
		throw new exception("queue is empty");
	}

	T head = stack2.top().
	stack2.pop();

	return head;
}



