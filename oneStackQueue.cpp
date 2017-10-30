#include <iostream>
#include <stack>

using namespace std;
//------------------------------------
template <class T>
class osQ
{
public:
	void Q(T val);
	bool DQ();

private:
	stack<T> values;
};
//------------------------------------
template <class T>
void osQ<T>::Q(T val)
{
	values.push(val);
}
//------------------------------------
template <class T>
bool osQ<T>::DQ()
{
	if (!values.empty())
	{
		T v = values.top();
		values.pop();
		if (!DQ())
			cout << v << endl;
		else
			Q(v);

		return true;
	}
	return false;
}

//------------------------------------
using namespace std;
int main(int argc, char const *argv[])
{
	osQ<int> q;
	q.Q(1);
	q.Q(2);
	q.Q(3);
	q.Q(4);

	q.DQ();
	q.DQ();
	q.DQ();
	q.DQ();
}