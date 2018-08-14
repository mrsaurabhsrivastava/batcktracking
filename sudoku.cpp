//https://practice.geeksforgeeks.org/problems/solve-the-sudoku/0
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<string>
#include<cstring>
#define FOR(i,n) for(int i = 0; i < n; i++)

using namespace std;
struct cell 
{
	int dRow;
	int dCol;
};

bool gIsSafe(int xInput[9][9], const cell& c, int value) 
{
	FOR(i, 9) 
	{
		
	}	
}


void gSolveSoduku(int xInput [9][9]) 
{

}


int main() 
{
	std::ios_base::sync_with_stdio(false);
	int lTests;
	cin>>lTests;
	FOR(i, lTests) 
	{
		int lInput[9][9];
		FOR(j, 9*9)
			cin>>lInput[j/9][j%9];
	}
	
}
