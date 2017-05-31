import java.util.*;
public class TugOfWar {
	
	int N;
	int[][] sol;
	
	TugOfWar(int n)
	{
		N=n;
		sol = new int [N][N];
	}
	void printSol()
	{
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				System.out.print(sol[i][j]+" ");
			}
			System.out.println();
		}
	}
	
	boolean isSafe(int row,int col)
	{
		for(int i=col;i>=0;i--)
		{
			if(sol[row][i]==1)
				return false;
		}
		
		for(int i=row,j=col ; i>=0 && j>=0 ; i--,j--)
		{
			if(sol[i][j]==1)
				return false;
		}
		
		for(int i=row,j=col ; i<N && j>=0 ; i++,j--)
		{
			if(sol[i][j]==1)
				return false;
		}
		
		return true;
	}
	
	boolean NQUtil(int col)
	{
		if(col>=N)
			return true;
		
		for(int i=0;i<N;i++)
		{
			if(isSafe(i,col))
			{
				sol[i][col]=1;
				
				if(NQUtil(col+1))
					return true;
				
				sol[i][col]=0;		// backtracking 
			}
		}
		
		return false;
	}
	void NQ()
	{
		int col=0;
		
		if(NQUtil(col))
			printSol();
		else
			System.out.println("no solution exists");
	}
	public static void main(String[] args)
	{
		int x;
		System.out.println("enter the size of board");
		
		Scanner s = new Scanner(System.in);
		x=s.nextInt();
		
		TugOfWar tow = new TugOfWar(x);
		tow.NQ();
		s.close();
	}
}
