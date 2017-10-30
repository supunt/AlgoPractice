//#include <stdlib.h>
#include <iostream>
#include <vector>
#include <sys/time.h>
#include <math.h>

using namespace std;

struct timeval tvStart,tvEnd;

vector<int> dumbTimes, smartTimes;

long long c[6];
//-----------------------------------------------
//-----------------------------------------------
bool checkCoef(int n)
{
	int i, j;
 
	for (c[i=0] = 1; i < n; c[0] = -c[0], i++)
	{
		for (c[1 + (j=i)] = 1; j > 0; j--)
			c[j] = c[j-1] - c[j];		
	}

	return true;
}
//-----------------------------------------------
//-----------------------------------------------
int is_primeDumb(int n)
{
	if (n%2 == 0)
		return 0;
	else
    {
        int isprime = 0;
		for(int i = 2; i <= sqrt(n); i += 2)
		{
			if(i % 2 == 0)
				i++;

			if((int(n)% i) == 0)
			{
				isprime = 1;
				break;
			}
		}

		return isprime;
    }
}
//-----------------------------------------------
//-----------------------------------------------
bool is_prime(int n)
{
	if (n%2 == 0)
		return 0;

	int i;
 
	return checkCoef(n);
	c[0] += 1, c[i=n] -= 1;
	while (i-- && !(c[i] % n));
 
	return i < 0;
}
//-----------------------------------------------
//-----------------------------------------------
int main(void)
{
 	
 	for (int i = 3; i < 6; i++)
 	{
 		//gettimeofday(&tvStart,NULL);
		if(is_prime(i))
			cout << i << "|" ;
		//gettimeofday(&tvEnd,NULL);

		//smartTimes.push_back((tvEnd.tv_sec*1000000 + tvEnd.tv_usec) - (tvStart.tv_sec*1000000 + tvStart.tv_usec));

		//gettimeofday(&tvStart,NULL);
		if(is_primeDumb(i))
			cout << i << endl;

		//gettimeofday(&tvEnd,NULL);

		//dumbTimes.push_back((tvEnd.tv_sec*1000000 + tvEnd.tv_usec) - (tvStart.tv_sec*1000000 + tvStart.tv_usec));

 	}
 	
	
	// for (int i = 0; i < dumbTimes.size(); i++)
	// {
	// 	if(dumbTimes[i] > smartTimes[i])
	// 	{
	// 		cout << "Break at : " << i << " gap is : " << (dumbTimes[i] - smartTimes[i]) << endl;
	// 		//break;
	// 	}
	// }
	return 0;
}