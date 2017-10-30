#include <stack>
#include "utils.h"

using namespace std;
stack<braceAndLoc*> braceOrder;

//-------------------------------------------------------------------------------------------------
#define CB_WO_OB 			"ERROR::Closing brace without openning brace (at position "
#define CON_HIGHLIGHT_RED 	"\e[41m"
#define CON_FONT_GREEN 		"\e[32m"
#define CON_FONT_RED 		"\e[31m"
#define CON_HIGHLIGHT_RESET "\e[49m"
#define CON_FONT_RESET 		"\e[39m"
//-------------------------------------------------------------------------------------------------
void processString(string data)
{	
	int pos = 1;
	for (char c : data)
	{
		if (isBraceTyped(c))
		{
			if (isClosingBracket(c))
			{
				if (braceOrder.empty())
				{
					cout << CON_FONT_RED << CB_WO_OB << pos << ")" << CON_FONT_RESET << endl;
					return;
				}
				else
				{
					braceAndLoc* top = braceOrder.top();
					if(!areComplemetingBraces(top->brace,c))
					{
						cout << CON_FONT_RED << CB_WO_OB << pos << ")" << CON_FONT_RESET << endl;
						return;
					}
					else
					{
						braceOrder.pop();
						pos++;
						continue;
					}
				}
			}
			else // All are openning braces
			{
				braceAndLoc* br = new braceAndLoc;
				br->brace = c;
				br->loc = pos;
				braceOrder.push(br);
			}
		}	
		pos++;
	}

	if (!braceOrder.empty())
	{
		// Array to mark issues
		bool errorArr[pos];
		for (int i = 0; i < pos; ++i)
			errorArr[i] = false;

		cout << CON_FONT_RED << "ERROR::One or more unclosed braces : " << CON_FONT_RESET;
		braceAndLoc* top = braceOrder.top();
		while (top)
		{
			errorArr[top->loc-1] = true;
			braceOrder.pop();
			top = nullptr;
			if (!braceOrder.empty())
				top = braceOrder.top();
		}

		for (int i = 0; i < pos; ++i)
		{
			// Highlight errors while printing
			if (errorArr[i])
				cout << CON_HIGHLIGHT_RED << data[i] << CON_HIGHLIGHT_RESET;
			else
				cout << data[i];
		}
		cout << endl;
		return;
	}

	cout << CON_FONT_GREEN << "GOOD::Properly braced string." << CON_FONT_RESET << endl;
}
//-------------------------------------------------------------------------------------------------
int main(int argc, char const *argv[])
{
	cout << "Enter string : ";
	string input = "";
	cin >> input;

	processString(input);
	return 0;
}