#include <iostream>
#include <vector>
#include <climits>

using namespace std;
//----------------------------------------
bool preChecks(vector<int> v)
{
	if (v.size() < 3)
		return false;

	return true;
}
//----------------------------------------
int findMinPit(vector<int> v)
{
	if (!preChecks(v))
		return -1;

	bool pitFound = false;
	int minPit = INT_MIN;
	int lastKnownj = 0;
	int lastKnownk = 0;
	// by now vector size is >= that 3
	for (int i = 0; i < v.size() ; i++)
	{
		int j = i+1;
		int k = j+1;

		lastKnownj = v[i];
		lastKnownk = v[j];

		for (; j < v.size(); j++)
		{
			if (lastKnownj < v[j])
				break;
			else
				lastKnownj = v[j];

			for (; k < v.size(); k++)
			{
				if (lastKnownk < v[k])
					break;
				else
                {
                    pitFound = true;
                    lastKnownk = v[k];
                    int tempMinPit = min((v[i] - v[j]),(v[k] - v[j]));
                    if (minPit < tempMinPit)                        
                        minPit = tempMinPit;
                }
			}
		}
	}
	return pitFound?abs(minPit):-1;
}
//----------------------------------------
int main(int argc, char const *argv[])
{
	vector<int> A = {0, 1, 3, -2, 0, 1, 0, -3, 2, 3};
    cout << "Min pit : " << findMinPit(A) << endl;

    A = {0, 1, 2,3,4,5,6};
    cout << "Min pit : " << findMinPit(A) << endl;

    A = {0, 1};
    cout << "Min pit : " << findMinPit(A) << endl;

    A = {1,31, 3, -2, 10, 1, 0, -3, 2, 3};
    cout << "Min pit : " << findMinPit(A) << endl;
	return 0;
}