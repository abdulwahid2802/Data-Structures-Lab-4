#include "PostfixCalculator.h"

Stack<char> stack = Stack<char>();

void Postfix::getInfix()
{
	gets_s(infix);

	infixExpr = infix;

	cout << infixExpr<<endl;
	getPostfix(infixExpr);
	cout <<endl<< postfixExpr << endl;
}

void Postfix::getInfix(char input[])
{

	infixExpr = input;
	getPostfix(infixExpr);
}

//
char* Postfix::getPostfix(char *infix)
{
	return _getP(infix);
}

char* Postfix::_getP(char *infix)
{
	for (int i = 0; i < strlen(infix); i++)
	{
		// check if the current char is operator or operand
		if (isdigit(infix[i]))
		{
			int j = i;
			// keep copying the character to postfix string while its digit
			while (isdigit(infix[j]))
				postfix[index++] = infix[j++];
			// put a white space to make it visible
			postfix[index++] = ' ';
			i = j-1;
		}
		else // current char is operator
		{
			// push to stack iff new char is first operator or of higer precedende
			if (firstOperator(stack) || isHigher(infix[i], stack._top()))
				stack.push(infix[i]);
			else
			{
				while (!stack._isEmpty())
				{
					postfix[index++] = stack._top();
					postfix[index++] = ' ';
					stack.pop();
				}
				stack.push(infix[i]);
			}
		}
	}

	while (!stack._isEmpty())
	{
		postfix[index++] = stack._top();
		postfix[index++] = ' ';
		stack.pop();
	}
	postfix[index-1] = '\0';

	postfixExpr = postfix;
	return postfixExpr;
}
//
bool Postfix::firstOperator(Stack<char> stack)
{
	return stack._isEmpty();
}
//
bool Postfix::isHigher(char a, char b)
{
	return precedence(a) > precedence(b);
}