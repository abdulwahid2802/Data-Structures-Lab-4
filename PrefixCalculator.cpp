#include "PrefixCalculator.h"

void Prefix::getInfix()
{
	gets_s(infix);
	convertToPrefix();
}


void Prefix::convertToPrefix()
{
	reverse(infix);
	Postfix::getInfix(tempReversed);
	reverse(Postfix::postfix);

	cout << tempReversed << endl;

}

void Prefix::reverse(char input[])
{
	int i, j;
	for (i = 0, j = strlen(input) - 1; i < strlen(input); i++, j--)
		tempReversed[i] = input[j];
	tempReversed[i] = '\0';
}