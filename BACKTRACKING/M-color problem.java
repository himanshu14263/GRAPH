// PROBLEM :: M-COLOR PROBLEM

import java.util.*;
public class McolorProblem
{	
	final int V = 4;
	
	boolean isSafe(int[][] graph,int[] vertexColor,int vertex,int color)
	{
		for(int i=0;i<V;i++)
		{
			if(graph[vertex][i] == 1 && vertexColor[i]==color)
				return false;
		}
		return true;
	}
	boolean mColorUtil(int[][] graph, int m ,int[] vertexColor, int vertex)
	{
		if(vertex == V)
			return true;
		
		for(int color=1;color<=m;color++)
		{
			if(isSafe(graph,vertexColor,vertex,color))
			{
				vertexColor[vertex]=color;
				
				if(mColorUtil(graph,m,vertexColor,vertex+1))
					return true;
				
				vertexColor[vertex]=0;
			}
		}
		
		return false;
	}
	void mColor(int[][] graph, int m)
	{
		int vertexColor[] = new int[V];
		
		for(int i=0;i<V;i++)
			vertexColor[i]=0;
		
		if(mColorUtil(graph,m,vertexColor,0))
		{
			System.out.println("it is possible");
		}
		else
		{
			System.out.println("not possible");
		}
		
	}
	public static void main(String[] args)
	{
		int[][] mat = { {0, 1, 1, 1},
			            {1, 0, 1, 0},
			            {1, 1, 0, 1},
			            {1, 0, 1, 0},
					  };
		int m;
		System.out.println("enter the number of colors");
		Scanner s = new Scanner(System.in);
		m = s.nextInt();
		
		McolorProblem obj = new McolorProblem();
		obj.mColor(mat,m);
		s.close();
	}
}