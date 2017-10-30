#include <iomanip>
#include <iostream>
#include <vector>
#include <sys/time.h>

using namespace std;

int* arr = NULL;
struct timeval tm_start, tm_end;

//-----------------------------------------------------------
void startTrapping()
{
	gettimeofday(&tm_start,NULL);
}
//-----------------------------------------------------------
void endTrapping(string addthis)
{
	gettimeofday(&tm_end,NULL);

	long diff = (tm_end.tv_sec*1000000 - tm_start.tv_sec*1000000) + (tm_end.tv_usec - tm_start.tv_usec);
	cout << "Time elapsed for" << addthis << " :" << diff << endl;
}
//-----------------------------------------------------------
void initReuseArr(int n)
{
	if (arr == NULL)
	{
		arr =  new int[n+1];
		for (int i = 0; i < n+1; i++)
			arr[i] = 0;
	}
}
//-----------------------------------------------------------
unsigned long long getDumbFibo(int n)
{
	unsigned long long retval = 0;

	if(n <= 2)
		retval = 1;
	else
		retval = getDumbFibo(n-1) + getDumbFibo(n-2);

	return retval;	
}
//-----------------------------------------------------------
unsigned long long getMemoFibo(int n)
{
	
	unsigned long long retval = 0;
	initReuseArr(n);	

	if (arr[n] != 0)
		retval = arr[n];
	else
	{
		if(n <= 2)
			retval = 1;
		else
		{
			retval = getMemoFibo(n-1) + getMemoFibo(n-2);
			arr[n] = retval;
		}
	}

	return retval;	
}
//-----------------------------------------------------------
int main(int argc, char* argv[])
{
	unsigned long long fd = 0;
	unsigned long long fs = 0;
	int stage = 0;

	if (argc < 2)
	{
		cerr << "Usage a.exe <type[0(dumb),1(memo),2(both)]>" << endl;
		return 0;
	}
	else
		stage = atoi(argv[1]);

	cout << "-------------------------------" << endl;
    for (int i = 0; i < 100; i++)
   	{
   		cout << "Generating fibo number : " << i << endl;

   		if ((stage == 0) || (stage == 2))
   		{
   			startTrapping();
	   		fd = getDumbFibo(i);
	   		endTrapping(" dumb");
   		}

   		if ((stage == 1) || (stage == 2))
   		{
	   		startTrapping();
	   		fs = getMemoFibo(i);
	   		endTrapping(" memo");
   		}

   		cout << "fibo(" << i << ") = [" << fd << "," << fs << "]" << endl;
   		cout << "-------------------------------" << endl;

   		delete [] arr;
		arr = NULL;
  	}
    return 0;
}