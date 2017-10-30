#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//----------------------------------------------------------
void printArr(vector<int> v, string header)
{
	cout << header << endl;

	for (int e : v)
		cout << e << " ";

	cout << endl;
}
//--------------------------------------------------------
void sortDumb(vector<int> v)
{
	cout << "\nsortDumb ------------------------" << endl;
	for (int i = 0; i < v.size()-1; i++)
	{
		for (int j = i+1; j < v.size(); j++)
		{
			if (v[i] > v[j])
				swap(v[i],v[j]);
		}
		printArr(v, "---------------------------------");
	}
}
//--------------------------------------------------------
//--------------------- Bubble sort ----------------------
//--------------------------------------------------------
void sortBubbly(vector<int> v)
{
	cout << "\nsortBubbly ----------------------" << endl;
	for(int k = 0; k < v.size(); k++)
	{
		for (int i = 0; i < (v.size()-(1+k)); i++)
		{
			if (v[i] > v[i+1])
				swap(v[i],v[i+1]);

			printArr(v, "---------------------------------");
		}
	}
}

//--------------------------------------------------------
//--------------------- merge sort -----------------------
//--------------------------------------------------------
void merge(vector<int>& vleft,vector<int>& vRight,vector<int>& vResult)
{
	int lenLeft = vleft.size();
	int lenRight = vRight.size();
	int i = 0;
	int j = 0;
	int mainIndex = 0;

	while (( i < lenLeft ) && ( j < lenRight ))
	{
		if (vleft[i] <= vRight[j])
		{
			vResult[mainIndex] = vleft[i];
			i++;
		}
		else
		{
			vResult[mainIndex] = vRight[j];
			j++;
		}
		mainIndex++;
	}	

	while (i < lenLeft)
	{
		vResult[mainIndex] = vleft[i];
		i++;
		mainIndex++;
	}
	while (j < lenRight)
	{
		vResult[mainIndex] = vRight[j];
		j++;
		mainIndex++;
	}
	
}
//--------------------------------------------------------
void sortMergely(vector<int>& v)
{
	if(v.size() < 2)
		return;

	int halfSize = v.size()/2;

	vector<int> left;
	vector<int> right;

	for (int i = 0; i < halfSize; i++)
		left.push_back(v[i]);
	for (int i = halfSize; i < v.size(); i++)
		right.push_back(v[i]);

	sortMergely(left);
	sortMergely(right);
	merge(left,right,v);
}

//--------------------------------------------------------
//--------------------- Quick sort -----------------------
//--------------------------------------------------------
int partition(vector<int>& input, int start, int end)
{
	int pivot = input[end];
	int pIndex = start;
	for (int i = start; i < end ; i++)
	{
		if (input[i] <= pivot)
		{
			swap(input[i],input[pIndex]);
			pIndex++;
		}
	}
	swap(input[pIndex],input[end]);
	return pIndex;
}
//--------------------------------------------------------
void QuickSort(vector<int>& input, int start, int end)
{
	if (end > start)
	{
		int pIndex = partition(input,start,end);
		QuickSort(input,start,pIndex -1);
		QuickSort(input,pIndex+1,end);
	}
}
//--------------------------------------------------------

int main(int argc, char** argv)
{
	cout << "Enter the array size ------->" << endl << endl;
	int arrSize = 0;
	cin >> arrSize;
	cout << "Enter the array ------->" << endl << endl;
	vector<int> v;
	vector<int> vCopy;
	int temp = 0;
	for (int i = 0; i < arrSize; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}

	vCopy = v;
	sortDumb(v);

	v = vCopy;
	sortBubbly(v);

	v = vCopy;
	sortMergely(v);
	printArr(v, "\nmerge sortly---------------------");

	v = vCopy;
	QuickSort(v,0,v.size()-1);
	printArr(v, "\nQuick sort---------------------");

	char SubjectLine[4] = {0};

	
	for (int i = 0; i < 4; i++)
	{
		char c = SubjectLine[i];
		if (c == '\0')
			cout << "NULL|";
		else
			cout << c << "|";
	}

       SubjectLine[0] = 70;

       SubjectLine[1] = 0x50;

       SubjectLine[2] = 144%73;

       SubjectLine[3] = '\0';

     cout << SubjectLine << endl;
}

