#pragma once

#include<string>
#include<string.h>
#include<iostream>
#include<cstdlib>

using namespace std;

#define PLUS '+'
#define MINUS '-'
#define MULT '*'
#define DEV '/'

#define precedence(x) (x == MULT || x == DEV)
#define isOper(x) (x == MULT || x == DEV || x == PLUS || x == MINUS)

class Postfix
{
	string infix;
	string postfix;

	long evaluatePostfix();

public:
	Postfix(string infix): infix(infix){}
	Postfix(){}

	string infixToPostfix(string infix);
	long evaluatePostix(string);
};


