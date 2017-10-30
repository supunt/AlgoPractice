#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
	int val = 0;
	while (true)
	{
		cout << "Enter number : ";
		cin >> val;
		if ((val != 0) && !(val&(val-1)))
			cout << "Two to the power\n";
		else
			cout << "nope\n";
	}
	return 0;
}