#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int maxNode = 0;
//---------------------------------------------------------------------
void printNodeStructure(vector<int> v[])
{
	int matrix[maxNode+1][maxNode+1];
	
	for (int i = 0; i <= maxNode; i++)
	{
		for (int j = 0; j <= maxNode; j++)
			matrix[i][j] = 0;
	}

	for (int i = 0; i <= maxNode; i++)
	{		
		if (v[i].empty() == false)
		{
			for (auto ite = v[i].begin(); ite != v[i].end(); ite++)
				matrix[i][*ite] = 1;
		}
	}
	cout << "\nConnection matrix ---------------" << endl;
	cout << "----------------------------------" << endl;
	cout << "node\t|";
	for (int i = 0; i <= maxNode; i++)
	{
		for (int j = 0; j <= maxNode; j++)
		{
			if (i == 0)
			{
				if (j != 0)
					cout << j << " ";
			}
			else if (j == 0)
				cout << i << "\t|";
			else
				cout << matrix[i][j] << " ";
		}
		if (i == 0)
			cout << endl << "----------------------------------" << endl;
		else
			cout << endl;
	}
	cout << endl << "----------------------------------" << endl;
}
//---------------------------------------------------------------------
void runBFS(vector<int> v[], int startNode)
{
	queue<int> que;
	bool visited[maxNode+1] = {false};
	visited[startNode] = true;
	que.push(startNode);

	while(!que.empty())
	{
		int front = que.front();
		cout << front << " --> ";
		que.pop();

		for (auto ite = v[front].begin(); ite != v[front].end(); ite++)
		{
			if (visited[*ite] == false)
			{
				visited[*ite] = true;
				que.push(*ite);
			}
		}
	}
	cout << "END" << endl;
	cout << "----------------------------------" << endl;
}
//---------------------------------------------------------------------
void runDFS(vector<int> v[], int startNode, bool visited[])
{
	cout << startNode << " --> ";
	visited[startNode] = true;
	for (auto ite = v[startNode].begin(); ite != v[startNode].end(); ++ite)
	{
		if(visited[*ite] == false)
			runDFS(v,*ite,visited);
	}
}
//---------------------------------------------------------------------
int main(int argc, char** argv)
{
	vector<int> nodes[100];
	cout << "Enter the number of Edges : " ;
	int edges = 0;
	cin >> edges;

	cout << "Enter staring vertice and terminating vertice : " << endl;
	int startEdge, endEdge;
	for (int i = 0; i < edges; i++)
	{
		cin >> startEdge >> endEdge;
		if (maxNode < startEdge)
			maxNode = startEdge;
		if (maxNode < endEdge)
			maxNode = endEdge;

		nodes[startEdge].push_back(endEdge);
		//nodes[endEdge].push_back(startEdge);
	}

	printNodeStructure(nodes);

	cout << "Starting BFS -------------" << endl;
	cout << "Enter starting node : " << endl;
	int startNode = 0;
	cin >> startNode;
	if (startNode > maxNode)
	{
		cout << "No matching nodes to this value : " << startNode << endl;
		return 0;
	}
	runBFS(nodes,startNode);

	cout << "Starting DFS -------------" << endl;
	cout << "Enter starting node : " << endl;
	startNode = 0;
	cin >> startNode;
	if (startNode > maxNode)
	{
		cout << "No matching nodes to this value : " << startNode << endl;
		return 0;
	}

	bool visited[maxNode+1] = {false};
	runDFS(nodes,startNode,visited);
	cout << "END" << endl;
	cout << "----------------------------------" << endl;
	return 0;
}