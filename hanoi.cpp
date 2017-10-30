#include <iostream>
#include <stack>
using namespace std;

void hanoi(int stackSize, stack<int> &source, stack<int> &target, stack<int> &aux)
{
  if (stackSize == 0)
    return;
  
  hanoi(stackSize-1,source,aux,target);
  target.push(source.top());

  source.pop();
  hanoi(stackSize-1,aux,target,source); 
}

//--------------------------------------------------
// To execute C++, please define "int main()"
int main() {
  
  stack<int> initial;
  stack<int> target;
  stack<int> aux;
  initial.push(5);
  initial.push(4);
  initial.push(3);
  initial.push(2);
  initial.push(1);
  
  cout << "------------------------\n";
  hanoi(5,initial,aux,target);
  
  while (!aux.empty())
  {
    cout << aux.top() << endl;
    aux.pop();
    
  }
  return 0;
}
