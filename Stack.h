#pragma once

#ifndef STACK_H

#include<iostream>
#include<cstdlib>
#include<time.h>
#include<string.h>
#include<conio.h>

using namespace std;

template<class T>
class Stack
{
	typedef struct Node
	{
		T data;
		Node *next;
	}*Nptr;

	Nptr top;
	Nptr bottom;

	void _createNode(T);
	void _addNode(Nptr &, Nptr);
	void _pop();

protected:
	T _top(Stack<T>)const;

public:
	Stack();
	void push(T);
	void pop();
	void print()const;

	T _top()const;
	bool _isEmpty()const;

};

#endif // !STACK_H

