#include <iostream>
#include <string>

//-----------------------------------------------------
struct braceAndLoc
{
	char brace;
	int loc;
};
//-----------------------------------------------------
bool isBraceTyped(char c)
{
	switch(c)
	{
		case '{':
		case '}':
		case '(':
		case ')':
		case '[':
		case ']':
		{
			return true;
		}
		default:
		{
			return false;
		}
	}
	return false;
}
//-----------------------------------------------------
bool areComplemetingBraces(char opBrace, char clBrace)
{
	bool ret = false;
	switch(opBrace)
	{
		case '(': ret = (clBrace==')'?true:false);break;
		case '[': ret = (clBrace==']'?true:false);break;
		case '{': ret = (clBrace=='}'?true:false);break;
		default: break;
	}
	return ret;
}
//-----------------------------------------------------
//Close bracket eval ----------------------------------
//-----------------------------------------------------
bool isClosingBracket(char c)
{
	if ((c == ')') ||
		(c == ']') ||
		(c == '}'))
		return true;
	return false;
}
