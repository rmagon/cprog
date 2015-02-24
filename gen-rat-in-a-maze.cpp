#include <iostream>
using namespace std;
#define N 5 //Size of the NxN matrix

//Utility Function prints the matrix
void printMatrix(int mat[N][N])
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}

//returns true if mat[x][y] is not out of range and not 0
bool canVisit(int mat[N][N],int x,int y,int visit[N][N])
{
	if(x>=0&&x<N&&y>=0&&y<N&&mat[x][y]==1&&visit[x][y]==0)
	{
		return true;
	}
	return false;
}

bool solveMazeUtl(int mat[N][N],int x,int y,int sol[N][N],int visit[N][N])
{
	if((x==N-1)&&(y==N-1)) 
	{
		sol[x][y]=1;
		return true;
	}
	else if(canVisit(mat,x,y,visit)==true) 
	{
		//Add 1 to our path
		sol[x][y] = 1;
		visit[x][y] = 1;
		//check if we can move in x direction
		if(solveMazeUtl(mat,x+1,y,sol,visit)==true)
		{
			return true;
		}
		else if(solveMazeUtl(mat,x,y+1,sol,visit)==true) //check if we can move in y direction
		{
			return true;
		}
		else if(solveMazeUtl(mat,x,y-1,sol,visit)==true) //check if we can move in y direction
		{
			return true;
		}
		else if(solveMazeUtl(mat,x-1,y,sol,visit)==true) //check if we can move in y direction
		{
			return true;
		}
		//if we can't move then return false and remove the point from solution
		sol[x][y] = 0;
		return false;
	}
	return false;
}

bool solveMaze(int maze[N][N])
{
	int sol[N][N] = { {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };
    
    int visit[N][N] = { {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
    };
    
    if(solveMazeUtl(maze, 0, 0, sol,visit) == false)
    {
        printf("Solution doesn't exist");
        return false;
    }
 
    printMatrix(sol);
    return true;
}
int main() {
	
	int maze[N][N]  =  { 
		{1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0},
        {1, 0, 1, 1, 1},
        {1, 0, 1, 0, 1},
        {1, 1, 1, 0, 1}
    };
 
    solveMaze(maze);

    return 0;
}