#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <sys/time.h>

using namespace std;

//------------------------------------------------
bool binaryLookup(int lookupValue, vector<int>* vct, int start, int end)
{
	if (end < start)
		return false;

	int midPoint = start + (end - start)/2;

	if ((*vct)[midPoint] == lookupValue)
		return true;
	else if ((*vct)[midPoint] > lookupValue)
		return binaryLookup(lookupValue,vct,start,midPoint-1);
	else
		return binaryLookup(lookupValue,vct,midPoint+1,end);

	return false;
}
//------------------------------------------------
bool findMinCommonBinary(vector<int> v1,vector<int> v2, int& minCommon)
{
	if ((v1.size())*(v2.size()) == 0)
		return false;

	bool commonFound = false;
	bool useFirstArr=false;
	useFirstArr = (v1.size() <= v2.size())?true:false;

 	vector<int>* smallArray;
 	vector<int>* largeArray;

 	if (useFirstArr)
 	{
 		smallArray = &v1;
 		largeArray = &v2;
 	}	
 	else
 	{
 		smallArray = &v2;
 		largeArray = &v1;
 	}
 	sort(smallArray->begin(),smallArray->end());
 	int maxElemInSmallaArr = smallArray->back();
 	//--------------------------
	for (int elem : *largeArray)
	{
		if (maxElemInSmallaArr < elem)
			continue;

		if (binaryLookup(elem,smallArray,0,smallArray->size()-1))
		{
			commonFound = true;
			if (minCommon > elem)
				minCommon = elem;
		}
	}

	return commonFound;
}
//------------------------------------------------
void findMinCommonSorting(vector<int> v1,vector<int> v2, bool& found, int& minCommon)
{
	if ((v1.size())*(v2.size()) == 0)
		return;

	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());

	if (v1.back() < v2.front())
		return;
	if (v2.back() < v1.front())
		return;

	// serving edge condition (x) below
	bool useFirstArr=false;
	useFirstArr = (v1.size() <= v2.size())?true:false;
	int maxElemInSmallaArr = INT_MIN;

 	vector<int>* smallVect;
 	vector<int>* largeVect;

 	if (useFirstArr)
 	{
 		smallVect = &v1;
 		largeVect = &v2;
 	}	
 	else
 	{
 		smallVect = &v2;
 		largeVect = &v1;
 	}
 	//--------------------------
	int i=0,j=0;
	while ((i < smallVect->size()) && (j < largeVect->size()))
	{
		if ((*smallVect)[i] == (*largeVect)[j])
		{
			found = true;
			minCommon = (*smallVect)[i];
			return;
		}
		else if ((*smallVect)[i] < (*largeVect)[j])
			i++;
		else
			j++;
	}
}
//------------------------------------------------
void printvct(vector<int> v)
{
	for (int elem : v)
		cout << elem << " ";

	cout << endl;
}
//------------------------------------------------
void findMinCommonUOM(vector<int> v1,vector<int> v2, bool& found, int& minCommon)
{
	if ((v1.size())*(v2.size()) == 0)
		return;

	unordered_map<int,int> mapUO;
	bool useFirstArr=false;
	useFirstArr = (v1.size() <= v2.size())?true:false;
	int maxElemInSmallaArr = INT_MIN;

 	vector<int>* smallVect;
 	vector<int>* largeVect;

 	if (useFirstArr)
 	{
 		smallVect = &v1;
 		largeVect = &v2;
 	}	
 	else
 	{
 		smallVect = &v2;
 		largeVect = &v1;
 	}

 	for (int elemV1 : *smallVect)
 	{
 		if (maxElemInSmallaArr < elemV1)
 			maxElemInSmallaArr = elemV1;

 		mapUO[elemV1] = -1;
 	}

 	unordered_map<int,int>::iterator iteUOM;
 	for (int elemV2 : *largeVect)
 	{
 		if (elemV2 > maxElemInSmallaArr)
 			continue;

 		iteUOM = mapUO.find(elemV2);
 		if (iteUOM != mapUO.end())
 		{
 			found = true;
 			minCommon = elemV2;
 			return;
 		}
 	}
}
//------------------------------------------------
void runTests(vector<int> arr1,vector<int> arr2)
{
	struct timeval tv_start;
	struct timeval tv_end;
	//---------------------------------------------------------
	gettimeofday(&tv_start,nullptr);

	bool found=false;
	int min=INT_MAX;
	findMinCommonSorting(arr1,arr2,found,min);

	if (found)
		cout << "Min found by sorting :" << min << endl;
	else
	 	cout << "Common minimum not found.\n";
	gettimeofday(&tv_end,nullptr);

	cout << "Time elapsed : " << (tv_end.tv_sec - tv_start.tv_sec)*1000000 + (tv_end.tv_usec - tv_start.tv_usec) << endl;
	//---------------------------------------------------------
	gettimeofday(&tv_start,nullptr);
	found=false;
	min=INT_MAX;
	findMinCommonUOM(arr1,arr2,found,min);

	if (found)
		cout << "Min found by hash map:" << min << endl;
	else
	 	cout << "Common minimum not found.\n";
	 gettimeofday(&tv_end,nullptr);
	 cout << "Time elapsed : " << (tv_end.tv_sec - tv_start.tv_sec)*1000000 + (tv_end.tv_usec - tv_start.tv_usec) << endl;

	 //---------------------------------------------------------
	gettimeofday(&tv_start,nullptr);
	min=INT_MAX;

	if (findMinCommonBinary(arr1,arr2,min))
		cout << "Min found by Binary:" << min << endl;
	else
	 	cout << "Common minimum not found.\n";
	 gettimeofday(&tv_end,nullptr);
	 cout << "Time elapsed : " << (tv_end.tv_sec - tv_start.tv_sec)*1000000 + (tv_end.tv_usec - tv_start.tv_usec) << endl;

	 cout << "---------------------------------------" << endl;
}
//------------------------------------------------
int main(int argc, char const *argv[])
{
	vector<int> arr1 = {1,2};
	vector<int> arr2 = {0,8,7,6,5,3,4,9,22,21};

	runTests(arr1,arr2);

	arr2[0] = 1;

	runTests(arr1,arr2);

	arr2[0] = 2;

	runTests(arr1,arr2);

	arr2[9] = 1;

	runTests(arr1,arr2);

	arr2[9] = 2;

	runTests(arr1,arr2);

	arr1.clear();
	arr2.clear();
	for (int i = 0; i < 10000 ; ++i)
	{
		if (i < 5000)
			arr1.push_back(i);

		arr2.push_back(i*10000+1);
	}

	arr2[9999] = 1;

	runTests(arr1,arr2);
	arr2[1] = 1;

	runTests(arr1,arr2);

	arr1.clear();
	arr2.clear();
	for (int i = 1; i < 10000 ; ++i)
	{
		if (i < 5000)
			arr1.push_back(i);

		arr2.push_back(i*10000+1);
	}

	//arr2[9999] = 1;

	runTests(arr1,arr2);

	arr1.clear();
	arr2.clear();

	arr1.push_back(1);
	arr2.push_back(1);

	runTests(arr1,arr2);


	arr1.clear();
	arr2.clear();

	arr1.push_back(1);
	arr2.push_back(2);

	runTests(arr1,arr2);

	arr1.clear();
	arr2.clear();

	arr1.push_back(1);
	arr1.push_back(2);
	arr1.push_back(3);
	arr1.push_back(4);
	arr1.push_back(5);

	arr2.push_back(5);
	arr2.push_back(4);
	arr2.push_back(3);
	arr2.push_back(2);
	arr2.push_back(1);

	runTests(arr1,arr2);
	// tests 
	// size->0, size->0
	// size->1, size->0
	// size->0, size->1
	// size->1, size->1, matching elements
	// size->1, size->1, no matching elements
	// size->2, size->8, matching elements at the begin of arr2
	// size->2, size->8, matching elements at the end of arr2
	// size->2, size->8, matching elements at the middle of arr2
	// size->2, size->8, no matching elements
	// size->1, size->8, no matching elements
	// size->1, size->8, matching elements at the begin of arr2
	// size->1, size->8, matching elements at the end of arr2
	// size->1, size->8, matching elements at the middle of arr2
	return 0;
}

