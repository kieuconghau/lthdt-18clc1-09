#include <iostream>
using namespace std;

class StackIter;

class Stack
{
	friend class StackIter;

private:
	int items[10];
	int stackPosition;

public:
	Stack()
	{
		stackPosition = -1;
	}

	void push(int in)
	{
		items[++stackPosition] = in;
	}

	int pop()
	{
		return items[stackPosition--];
	}

	bool isEmpty()
	{
		return (stackPosition == -1);
	}

	StackIter *createIterator() const; // 2. Add a createIterator() member
};


class StackIter
{
private:
	// 1. Design an "iterator" class
	const Stack *stk;
	int index;

public:
	StackIter(const Stack *s)
	{
		stk = s;
	}

	void first()
	{
		index = 0;
	}

	void next()
	{
		index++;
	}

	bool isDone()
	{
		return index == stk->stackPosition + 1;
	}

	int currentItem()
	{
		return stk->items[index];
	}
};


StackIter* Stack::createIterator() const
{
	return new StackIter(this);
}


// Opened/Closed Principle
bool operator == (const Stack &l, const Stack &r)
{
	// 3. Clients ask the container object to create an iterator object
	StackIter *itl = l.createIterator();
	StackIter *itr = r.createIterator();
	
	// 4. Clients use the first(), isDone(), next(), and currentItem() protocol
	for (itl->first(), itr->first(); !itl->isDone(); itl->next(), itr->next())	// Parallel process
	{
		if (itl->currentItem() != itr->currentItem())
			break;
	}
	bool ans = itl->isDone() && itr->isDone();
	
	delete itl;
	delete itr;
	
	return ans;
}


int main()
{
	Stack s1;
	for (int i = 1; i < 5; i++)
		s1.push(i);
	
	Stack s2(s1), s3(s1), s4(s1), s5(s1);
	s3.pop();
	s5.pop();
	s4.push(2);
	s5.push(9);
	
	cout << "1 == 2 is " << (s1 == s2) << endl;
	cout << "1 == 3 is " << (s1 == s3) << endl;
	cout << "1 == 4 is " << (s1 == s4) << endl;
	cout << "1 == 5 is " << (s1 == s5) << endl;

	system("pause");
	return 0;
}