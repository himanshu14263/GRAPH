// PROBLEM :: LONGEST DISTANCE IN DAG FROM THE STARTING FROM GIVEN VERTEX

#include<bits/stdc++.h>
using namespace std;

void topologicalSortUtil(list<pair<int,int> >*adjList,bool visited[],stack<int>&s,int i)
{
	visited[i]=true;

	list<pair<int,int> >::iterator it;
	for(it=adjList[i].begin();it!=adjList[i].end();++it)
	{
		if(visited[(*it).first]==false)
			topologicalSortUtil(adjList,visited,s,(*it).first);
	}

	s.push(i);
}

void longestPath(list<pair<int,int> >*adjList,int s,int v)
{
		stack<int>st;
		bool visited[v];

		for(int i=0;i<v;i++)
			visited[v]=false;

		for(int i=0;i<v;i++)
		{
			if(visited[i]==false)
				topologicalSortUtil(adjList,visited,st,i);
		}


		int distance[v];
		for(int i=0;i<v;i++)
		{
			distance[i]=INT_MIN;
		}

		distance[s]=0;

		while(st.empty()==false)
		{
			int u=st.top();
			st.pop();

			list<pair<int,int> >::iterator it;

			if(distance[u]!=INT_MIN)
			{
				for(it=adjList[u].begin();it!=adjList[u].end();++it)
				{
					if(distance[(*it).first]<(distance[u]+((*it).second)))
						distance[(*it).first]=(distance[u]+((*it).second));
				}
			}
		}

		for(int i=0;i<v;i++)
		{
			(distance[i]==INT_MIN) ? cout<<"INF ": cout<<distance[i]<<" ";
		}

}
int main()
{
	int v=6;
	list<pair<int,int> > * adjList=new list<pair<int,int> >[v];

// adjList[u].push_back(make_pair(v,weight))
	adjList[3].push_back(make_pair(1,1));
	adjList[2].push_back(make_pair(3,1));
	adjList[2].push_back(make_pair(1,1));
	adjList[4].push_back(make_pair(1,5));
	adjList[4].push_back(make_pair(0,3));
	adjList[5].push_back(make_pair(0,3));
	adjList[5].push_back(make_pair(2,3));

	int s;
	cout<<"enter the starting point\n";
	cin>>s;

	longestPath(adjList,s,v);

}
