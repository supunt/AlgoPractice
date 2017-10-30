#include <iostream>
#include <stack>
#include <string>

using namespace std;

string err = "empty queue";
//------------------------------------
template <class T>
class myQ
{
public:
	void enqueue(T val);
	T dequeue();

private:
	stack<T> in;
	stack<T> out;

};
//------------------------------------
template <class T>
void myQ<T>::enqueue(T val)
{
	in.push(val);
}
//------------------------------------
template <class T>
T myQ<T>::dequeue()
{
	T lv;
	if (out.empty())
	{
		while (!in.empty())
		{
			lv = in.top();
			in.pop();
			out.push(lv);
		}
	}
	
	if (out.empty())
		throw err;

	lv = out.top();
	out.pop();
	return lv;
}
//------------------------------------
int main(int argc, char const *argv[])
{
	myQ<int> stackyQ;
	
	try
	{
		stackyQ.enqueue(1);
		stackyQ.enqueue(2);
		
		cout << stackyQ.dequeue() << endl;
		cout << stackyQ.dequeue() << endl;
		stackyQ.enqueue(3);
		stackyQ.enqueue(4);
		stackyQ.enqueue(5);
		cout << stackyQ.dequeue() << endl;
		cout << stackyQ.dequeue() << endl;
		cout << stackyQ.dequeue() << endl;
		stackyQ.enqueue(9);
		cout << stackyQ.dequeue() << endl;
		cout << stackyQ.dequeue() << endl;
	}
	catch (string err)
	{
		cout << err << endl;
	}

	return 0;
}