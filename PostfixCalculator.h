#pragma once
#include<iostream>
#include<cstdlib>
#include<time.h>
#include "Stack.cpp"

using namespace std;

#define PLUS '+'
#define MINUS '-'
#define MULT '*'
#define DEV '/'

#define precedence(x) (x == MULT || x == DEV)

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

 class Postfix: protected Stack<char > 
 {
	 unsigned short int index = 0;

	 char infix[500];
	 char* infixExpr;
	 char* postfixExpr;
	 char* _getP(char*);
	 bool firstOperator(Stack<char>);
	 bool isHigher(char, char);

 protected:
	 char postfix[500];
	 void getInfix(char[]);

 public:
	 Postfix() {}
	 void getInfix();
	 char* getPostfix(char*);

 };
#endif // !POSTFIXCALCULATOR_H

