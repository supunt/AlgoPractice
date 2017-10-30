#include <iostream>
#include <vector>

using namespace std;

std::vector<int> v;
//--------------------------------------
void getPrimeFactors(int value)
{
	v.clear();
	for (int i = 2; i <= value/i; ++i)
	{
		while (value % i == 0)
		{
			v.push_back(i);
			value /= i;
		}
	}

	if (value > 1)
		v.push_back(value);

	for (auto a : v)
		cout << a << ",";

	cout << endl;
}
//--------------------------------------
int main(int argc, char const *argv[])
{
	int val = 0;
	while (true)
	{
		cout << "Enter number : ";
		cin >> val;
		getPrimeFactors(val);
	}
	return 0;
}