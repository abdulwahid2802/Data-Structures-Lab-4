/*
Owner's Note:
This project is designed to teach concept of:
1. Prefix, Infix, Postfix conversions
2. Class inheritance and templates
3. OOP and encapsulation

All the code written here fully follows OOP.
This code is free and available on GitHub to Fork or Clone
Feel free to report any bugs or mistakes in code or open issues on GitHub

By Abduvohid,
WCodingLabs @2018;
wahid@sju.ac.kr
*/
#include "Postfix.h"
#include "Stack.cpp"

int main()
{

	string str;

	getline(cin, str);

	Postfix postfix;

	string postExpr = postfix.infixToPostfix(str);
	cout << postExpr << endl;

	cout<< postfix.evaluatePostix(postExpr);

	_getch();
	return 0;
}