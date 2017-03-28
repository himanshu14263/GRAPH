// PROBLEM :: CHECKING IF THERE IS CYCLE IN THE GRAPH

// TIME COMPLEXITY :: O(V+E)

#include <bits/stdc++.h>
using namespace std;

bool isCyclic(int strt,bool visited[],bool recStack[],list<int>*&adjList)
{
	if(visited[strt]==false)
	{
		visited[strt]=true;
		recStack[strt]=true;

		list<int >::iterator it;

			for(it=adjList[strt].begin();it!=adjList[strt].end();++it)
			{
				if(visited[*it]==false && isCyclic(*it,visited,recStack,adjList))
					return true;
				else if (recStack[*it])
					return true;
			}
	}

	recStack[strt]=false;
	return false;
}
bool dfs(list<int>*&adjList,int v,int strt)
{
	bool visited[v];
	bool recStack[v];

	for(int i=0;i<v;i++)
	{
		visited[i]=false;
		recStack[i]=false;
	}

	for(int i=0;i<v;i++)
	{
		if(isCyclic(i,visited,recStack,adjList))
			return true;
	}
	return false;
}
int main()
{
	int v=4;

	list<int>*adjList=new list<int>[v];

	// adding edges
	adjList[0].push_back(1);
	adjList[0].push_back(2);
	adjList[1].push_back(2);
	adjList[2].push_back(0);
	adjList[2].push_back(3);
	adjList[3].push_back(3);

	int strt=2;
	cout<<"if cycle exists in the graph :: ";
	if(dfs(adjList,v,strt))
		cout<<"yes \n";
	else
		cout<<"no\n";

}
