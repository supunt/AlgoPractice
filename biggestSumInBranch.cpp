#include <iostream>
#include <deque>
#include <numeric>
using namespace std;


//------------------------------------
template <class T>
class node{
public:
	node(T v){ value = v;};
	T value;
	node* left = nullptr;
	node* right= nullptr;
};
//------------------------------------
template <class T>
class tree{
public:
	node<T>* root = nullptr;
	deque<T> values;
	T max;
	void traverse(node<T>* node)
	{
		if (!node)
			return;

		values.push_back(node->value);
		traverse(node->left);
		T sum = accumulate(values.begin(),values.end(),0);
		if (max < sum)
			max = sum;

		traverse(node->right);
		sum = accumulate(values.begin(),values.end(),0);
		if (max < sum)
			max = sum;

		values.pop_back();
	}

	T getMax(){ return max;};
};
//------------------------------------
int main(int argc, char const *argv[])
{
	tree<int> tree;
	tree.root = new node<int>(1);
	tree.max = 0;
	tree.root->left = new node<int>(2);
	tree.root->left->left = new node<int>(5);
	tree.root->left->left->right = new node<int>(15);

	tree.root->right = new node<int>(3);
	tree.root->right->left = new node<int>(2);
	tree.root->right->right = new node<int>(4);
	tree.root->right->right->right = new node<int>(6);

	tree.traverse(tree.root);
	cout << tree.getMax() << endl;
}