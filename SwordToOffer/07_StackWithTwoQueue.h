#pragma once
#include <queue>
#include <exception>

template <typename T> class CStack{
public:
	CStack(void);
	~CStack(void);

	void appenTail(const T& node);
	T deleteHead(void);

private:
	queue<T> queue1;
	queue<T> queue2;
};

template <typename T> CStack::CStack(void)
{
}

template <typename T> CStack::~CStack(void)
{
}

template <typename T> void CStack::appenTail(const T& node)
{
	if(!queue1.empty())
	{
		queue1.push(node);
	}
	else if(!queue2.empty())
	{
		queue2.push(node);
	}

}

template <typename T> T CStack::deleteHead(void)
{
	if(!queue1.empty() && queue2.empty())
	{
		while(queue1.size() > 1)
		{
			T& data = queue1.top;
			queue2.push(data);
			queue1.pop();
		}

		if(queue1.size() == 1)
		{
			T head = queue1.top();
			queue1.pop();
		}

		return head;
	}
	else if(queue1.empty() && !queue2.empty())
	{
		while(queue2.size() > 1)
		{
			T& data = queue2.top();
			queue1.push(data);
			queue2.pop();
		}

		if(queue2.size() == 1)
		{
			T head = queue2.top();
			queue2.pop();
		}

		return head;
	}
	else if(queue1.empty() && queue2.empty())
	{
		throw new exception("stack is empty");
	}
}