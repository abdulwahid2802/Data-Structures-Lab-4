#pragma once

#ifndef PREFIX_H
#define PREFIX_H

#include<cstdlib>
#include<iostream>
#include "PostfixCalculator.h"

using namespace std;

class Prefix: protected Postfix
{
	char infix[500];
	char infixReverse[500];
	char prefix[500];

	char tempReversed[500];

	void reverse(char[]);
	void convertToPrefix();


public:
	Prefix(){}
	void getInfix();

};



#endif // !PREFIX_H






