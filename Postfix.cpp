#include "Postfix.h"
#include "Stack.cpp"

using namespace std;
string Postfix::infixToPostfix(string infix)
{

	Stack<char> stack = Stack<char>();


	for (int i = 0; i < infix.length(); i++)
	{
		//
		if (isdigit(infix[i]))
		{
			int j = i;
			while (isdigit(infix[j]))
				postfix += infix[j++];

			postfix += " ";
			i = j-1;
		}

		else if (infix[i] == '(')
			stack.push(infix[i]);
		// 
		else if (infix[i] == ')')
		{
			while (!stack._isEmpty() && stack._top() != '(')
			{
				postfix += stack._top();
				postfix += " ";
				stack.pop();
			}
			if (stack._top() == '(')
				stack.pop();
		}
		//
		else
		{
			if (stack._isEmpty())
				stack.push(infix[i]);
			else if (precedence(infix[i]) > precedence(stack._top()))
				stack.push(infix[i]);
			else
			{
				while ((precedence(infix[i]) <= precedence(stack._top())) && (stack._top() != '(' && !stack._isEmpty()))
				{
					postfix += stack._top();
					postfix += " ";
					stack.pop();
				}

				stack.push(infix[i]);
			}
		}
	}

	while (!stack._isEmpty() && stack._top() != '(')
	{
		postfix += stack._top();
		postfix += " ";
		stack.pop();
	}

	return postfix;
}

long Postfix::evaluatePostix(string postExpr)
{
	Stack<long> stack = Stack<long>();

	for (int i = 0; i < postExpr.length(); i++)
	{
		if (isdigit(postExpr[i]))
		{
			char str[100];
			int k = 0;
			while (isdigit(postExpr[i])) 
			{
				str[k++] = postExpr[i++];
			}
			str[k] = '\0';

			stack.push(atol(str));
		}
		else if (isOper(postExpr[i]))
		{
			long a = stack._top();
			stack.pop();
			long b = stack._top();
			stack.pop();

			switch (postExpr[i])
			{
				case PLUS:
					stack.push(a + b);
					break;
				case MINUS:
					stack.push(b - a);
					break;
				case MULT:
					stack.push(a * b);
					break;
				case DEV:
					stack.push(b / a);
					break;
				default:
					break;
			}
		}

	}

	if (!stack._isEmpty())
		return stack._top();
}
