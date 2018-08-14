//https://practice.geeksforgeeks.org/problems/n-queen-problem/0
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#define FOR(i,n) for(int i = 0; i < n; i++)

using namespace std;

struct cell 
{
	int dRow;
	int dCol;
};

bool gIsSafe(const vector<cell>& xArray, const cell& xCell) 
{
	bool lIsSafe = true;
	for (int i = 0; i < xArray.size()-1; i++) 
	{
		cell c = xArray[i];
		int row = c.dRow;
		int col = c.dCol;
		if (row == xCell.dRow || col == xCell.dCol) 
			return false;
		
		if (abs(row-xCell.dRow) == abs(col-xCell.dCol))
			return false;
	}
	return true;
	
}

void gQueenPlaceInCol(vector<cell>& xArray, int xCol, int n, vector<vector<int>>& xResult) 
{
	if (xCol >= n) 
		return;

	for (int i = 0; i < n; i++) 
	{
		cell nc = {i, xCol};
		xArray.push_back(nc);
		if (gIsSafe(xArray, nc)) 
		{
			if (xCol == n-1) 
			{
				// this is a result 
				vector<int> lVec;
				FOR(j,n) 
				{
					lVec.push_back(xArray[j].dRow+1);
				}
				xResult.push_back(lVec);
			}
			gQueenPlaceInCol(xArray, xCol+1, n, xResult);
		}
		xArray.pop_back();
		
	}
	return;
}
 
vector<vector<int> > gQueenPlaced(int n)
{
	vector<vector<int>> lResult;
	vector<cell> lArray;
	gQueenPlaceInCol(lArray, 0, n, lResult); 
	return lResult;
}

int main() 
{
	std::ios_base::sync_with_stdio(false);
	int lTestcase;
	cin>>lTestcase;
	FOR(i, lTestcase)
	{
		int n;
		cin>>n;
		vector<vector<int> >lResult = gQueenPlaced(n);
		if (lResult.size()) 
		{
			FOR(k, lResult.size()) 
			{
				cout<<"[";
				FOR(j, lResult[k].size()) 
					cout<<lResult[k][j]<<" ";
				cout<<"] ";
			}
		}
		else 
			cout<<-1;
		cout<<"\n";
	}
	
}
