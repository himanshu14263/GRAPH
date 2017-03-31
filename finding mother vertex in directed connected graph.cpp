// PROBLEM :: FINDING MOTHER VERTEX IN DIRECTED CONNECTED GRAPH

// TIME COMPLEXITY :: O(V+E)

#include <bits/stdc++.h>
using namespace std;

void dfs(list<int>*adjList,bool visited[],int i)
{
	if(visited[i]==false)
	{
		visited[i]=true;

		list<int>::iterator it;
		for(it=adjList[i].begin();it!=adjList[i].end();++it)
		{
			if(visited[*it]==false)
				dfs(adjList,visited,*it);
		}
	}
}
void findMotherVertex(list<int>*adjList,int v)
{
	bool visited[v];
	for(int i=0;i<v;i++)
		visited[i]=false;

	int motherV;		// possible mother vertex.

	for(int i=0;i<v;i++)
	{
		if(visited[i]==false)
		{
			dfs(adjList,visited,i);
			motherV=i;
		}
	}

	for(int i=0;i<v;i++)
		visited[i]=false;

	dfs(adjList,visited,motherV);

	bool f=1;
	for(int i=0;i<v;i++)
	{
		if(visited[i]==false)
		{
			f=0;
			break;
		}
	}

	f?cout<<"the mother vertex is "<<motherV:cout<<"there is no mother vertex\n";
}

int main()
{
	int v=7;

	list<int>*adjList=new list<int>[v];

	adjList[0].push_back(1);
	adjList[0].push_back(2);
	adjList[1].push_back(3);
	adjList[4].push_back(1);
	adjList[5].push_back(2);
	adjList[5].push_back(6);
	adjList[6].push_back(4);
	adjList[6].push_back(0);

	findMotherVertex(adjList,v);
}
