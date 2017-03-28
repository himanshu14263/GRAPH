// PROBLEM :: DFS OF GRAPH (ADJACENCY LIST) BOTH ITERATIVE AND RECURSIVE SOLUTION.

#include <bits/stdc++.h>
using namespace std;

// iterative solution
void dfs(list<int>* &adjList,int v,int strt)
{
	stack<int>s;
	bool visited[v];
	for(int i=0;i<v;i++)
		visited[i]=false;

	s.push(strt);
	visited[strt]=true;

	while(s.empty()==false)
	{
		int strt=s.top();
		cout<<strt<<" ";
		s.pop();

		list<int>::iterator it;
		for(it=adjList[strt].begin();it!=adjList[strt].end();++it)
		{
			if(visited[*it]==false)
			{
				s.push(*it);
				visited[*it]=true;
			}
		}
	}
}

// recursive solution
void dfsRecurUtil(list<int>* &adjList,bool visited[],int strt)
{
	cout<<strt<<" ";
	list<int>::iterator it;
	for(it=adjList[strt].begin();it!=adjList[strt].end();++it)
	{
		if(visited[*it]==false)
		{
			visited[*it]=true;
			dfsRecurUtil(adjList,visited,*it);
		}
	}
}
void dfsRecur(list<int>* &adjList,int v,int strt)
{
	bool visited[v];

	for(int i=0;i<v;i++)
		visited[i]=false;

	visited[strt]=true;

	dfsRecurUtil(adjList,visited,strt);
}


int main()
{
	int v=4;

	list<int>*adjList=new list<int>[v];

	// adding edges
	adjList[0].push_back(1);
	adjList[0].push_back(2);
	adjList[1].push_back(2);
	adjList[2].push_back(3);
	adjList[2].push_back(0);
	adjList[3].push_back(3);

	int strt=2;
	cout<<"the dfs of the given graph is :: ";
	dfsRecur(adjList,v,strt);

}
