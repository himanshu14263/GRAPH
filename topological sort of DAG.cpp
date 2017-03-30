// PROBLEM :: TOPOLOGICAL SORT OF DIRECTED ACYCLIC GRAPH (DAG).

// TIME COMPLEXITY :: O(V+E)

#include <bits/stdc++.h>
using namespace std;

void topologicalSortUtil(list<int>*adjList,bool visited[],stack<int>&s,int i)
{
	visited[i]=true;

	list<int>::iterator it;
	for(it=adjList[i].begin();it!=adjList[i].end();++it)
	{
		if(visited[*it]==false)
			topologicalSortUtil(adjList,visited,s,*it);
	}

	s.push(i);
}
void topologicalSort(list<int>*adjList,int v)
{
	stack<int>s;
	bool visited[v];

	for(int i=0;i<v;i++)
		visited[v]=false;

	for(int i=0;i<v;i++)
	{
		if(visited[i]==false)
			topologicalSortUtil(adjList,visited,s,i);
	}

	// printing topological sort

	cout<<"the topological sort of the graph is :: ";
	while(s.empty()==false)
	{
		cout<<s.top()<<" ";
		s.pop();
	}
}
int main()
{
	int v=6;
	list<int> * adjList=new list<int>[v];

	adjList[3].push_back(1);
	adjList[2].push_back(3);
	adjList[4].push_back(1);
	adjList[4].push_back(0);
	adjList[5].push_back(0);
	adjList[5].push_back(2);

	topologicalSort(adjList,v);

}
