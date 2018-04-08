#include "Stack.h"

using namespace std;

template<class T>
Stack<T>::Stack()
{
	top = NULL;
	bottom = NULL;
}

template<class T>
void Stack<T>::push(T data)
{
	_createNode(data);
}

template<class T>
void Stack<T>::_createNode(T data)
{
	Nptr n = new Node();
	n->data = data;
	n->next = NULL;
	
	_addNode(top, n);
}

template<class T>
void Stack<T>::_addNode(Nptr &Ptr, Nptr n)
{
	if (_isEmpty())
	{
		top = n;
		bottom = n;
	}
	else
	{
		n->next = top;
		top = n;
	}
}

template<class T>
bool Stack<T>::_isEmpty()const
{
	return top == NULL;
}

template<class T>
void Stack<T>::pop()
{
	_pop();
}

template<class T>
void Stack<T>::_pop()
{
	if (!_isEmpty())
	{
		Nptr temp = top;
		top = top->next;

		delete temp;
	}
}

template<class T>
T Stack<T>::_top()const
{
	if(!_isEmpty())
		return top->data;
}

template<class T>
T Stack<T>::_top(Stack<T> stack)const
{
	return stack.top->data;
}

template<class T>
void Stack<T>::print()const
{
	if (!_isEmpty())
	{
		Nptr curr = top;
		do
		{
			cout << curr->data << " ";
			curr = curr->next;
		} while (curr);


		cout << endl << "Top: " << top->data << endl;
	}
}