// PROBLEM :: KAHN'S ALGORITHM FOR TOPOLOGICAL SORTING.
// TIME COMPLEXITY :: O(V+E)

#include<bits/stdc++.h>
using namespace std;

void addEdges(list<int>adjList[],int u,int v)
{
	adjList[u].push_back(v);
}

void topologicalSort(list<int>adjList[],int v)
{
	int incoming[v];
	memset(incoming,0,sizeof(incoming));

	// creating incoming array
	for(int i=0;i<v;i++)
	{
		list<int>::iterator it;
		for(it=adjList[i].begin();it!=adjList[i].end();++it)
		{
			incoming[*it]++;
		}
	}

	queue<int>q;
	for(int i=0;i<v;i++)
	{
		if(incoming[i]==0)
			q.push(i);
	}

	int cnt=0;

	vector<int>topologicalAns;

	while(q.empty()==false)
	{
		int u=q.front();
		q.pop();
		topologicalAns.push_back(u);

		list<int>::iterator it;
		for(it=adjList[u].begin();it!=adjList[u].end();++it)
		{
			incoming[*it]--;
			if(incoming[*it]==0)
				q.push(*it);
		}

		cnt++;
	}

	if(cnt!=v)
	{
		cout<<"there exists a cycle in the graph\n";
		return;
	}

	for(int i=0;i<v;i++)
		cout<<topologicalAns[i]<<" ";
	cout<<endl;

}

int main()
{
	int v;
	cout<<"enter the number of vertices\n";
	cin>>v;
	list<int>adjList[v];

	int e;
	cout<<"enter the number of edges\n";
	cin>>e;

	for(int i=0;i<e;i++)
	{
		cout<<"enter the edges\n";
		int e1,e2;
		cin>>e1>>e2;
		addEdges(adjList,e1,e2);
	}

	topologicalSort(adjList,v);
}
