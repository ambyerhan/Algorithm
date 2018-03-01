#pragma once

# ifndef __CQUEUE_H__
# define __CQUEUE_H__

# include <stdio.h>
# include <stdlib.h>
# include <stack>
# include <vector>
# include <stack>

template<typename T>
class CQueue
{
public:
	CQueue(void);
	~CQueue(void);

	void appendTail(const T &node);
	T deleteHead();

private:
	std::stack<T> stk1;
	std::stack<T> stk2;
};
/*
class CTMP
{
public:
	CTMP();
	~CTMP();
private:
	int data;
};
*/
//# include "CQueue.cpp"

template<typename T>
CQueue<T>::CQueue()
{

}

template<typename T>
CQueue<T>::~CQueue()
{

}

template<typename T>
void CQueue<T>::appendTail(const T &node)
{
	this->stk1.push(node);
}

template<typename T>
T CQueue<T>::deleteHead()
{
	if (this->stk2.empty())
	{
		if (this->stk1.empty())
			return NULL;
		else
		{
			while (!this->stk1.empty())
			{
				T &data = this->stk1.top();
				this->stk1.pop();
				this->stk2.push(data);
			}
		}
	}
	if (this->stk2.empty())
		return NULL;
	T head = this->stk2.top(); // top: return but not del the top
	this->stk2.pop(); // pop: del directly, won't return
	return head;
}


# endif
