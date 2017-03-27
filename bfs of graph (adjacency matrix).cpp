// BFS OF A GRAPH (ADJACENCY LIST)

#include <bits/stdc++.h>
using namespace std;

void bfs(list<int>* &adjList,int v,int strt)
{
	queue<int>q;
	bool visited[v];
	for(int i=0;i<v;i++)
		visited[i]=0;

	q.push(strt);
	visited[strt]=true;

	while(q.empty()==false)
	{
		int s=q.front();
		cout<<s<<" ";
		q.pop();

		list<int>::iterator it;

		for(it=adjList[s].begin();it!=adjList[s].end();it++)
		{
			if(visited[*it]==false)
			{
				q.push(*it);
				visited[*it]=true;
			}
		}
	}
}
int main()
{
	int v=4;

	list<int>* adjList=new list<int>[v];

	adjList[0].push_back(1);
	adjList[0].push_back(2);
	adjList[1].push_back(2);
	adjList[2].push_back(0);
	adjList[2].push_back(3);
	adjList[3].push_back(3);

	int strt=2;

	cout<<"the bfs of graph is :: ";
	bfs(adjList,v,strt);

}
