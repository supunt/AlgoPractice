#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;
//----------------------------------------
int kadane(vector<int> v, int& start, int& end)
{
	int runningMax = v[0];
	int bestKnownMax=v[0];
	start = 0;
	end=0;

	for (int i = 1; i < v.size(); ++i)
	{
		runningMax += v[i];
		if (runningMax > bestKnownMax)
		{
			bestKnownMax = runningMax;
			end = i;
		}

		if (runningMax < 0)
		{
			runningMax = 0;
			start = i+1;
		}
	}
	return bestKnownMax;
}
//----------------------------------------
int main(int argc, char** argv)
{
	cout << "Enter number of elements : ";
	int elems = 0;
	cin >> elems;

	int tempVar=0;
	vector<int> vctElems;
	for (int i = 0; i < elems; ++i)
	{
		cin >> tempVar;
		vctElems.push_back(tempVar);
	}

	int start=0,end=0;
	int max_sub_arr = kadane(vctElems,start,end);

	cout << "Max is : " << max_sub_arr << " [" << start << "," << end << "]\n";

	return 0;
}

