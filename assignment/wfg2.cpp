#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cout << "Enter the number of processes:"; // Entering the number of processes
	cin >> n;
	int a[n][n];			 // creating a matrix of size n*n for storing the processes graph
	vector<int> edges_start; // vector for storing the starting point of the edges
	vector<int> edges_end;	 // vector for storing the ending point of the edges

	// Entering the values of the process matrix
	cout << "\nEnter the value of matrix:";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "\nEnter the value of a" << i << j;
			cin >> a[i][j];
		}
	}
	// filling the vectors with the vertices of the edges
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == 1)
			{
				edges_start.push_back(i);
				edges_end.push_back(j);
			}
		}
	}
	// printing the edges
	cout << "Edges are:\n";
	for (int i = 0; i < edges_start.size(); i++)
	{
		cout << "Edge is from process " << edges_start[i] << "to " << edges_end[i] << "\n";
	}

	// creating the wait for graph
	int no_of_resources = edges_start.size();		   // number of resources=number of edges
	int m = n + no_of_resources;					   // total number of vertices in the wait for graph
	int wfg[n + no_of_resources][n + no_of_resources]; // wait for graph matrix
	// initializing the wait for graph matrix with 0
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			wfg[i][j] = 0;
		}
		cout << "\n";
	}
	// filling the wait for graph matrix with the edges
	for (int i = 0; i < no_of_resources; i++)
	{
		int l = edges_start[i];
		int k = edges_end[i];
		wfg[l][n + i] = 1; // edge start from process l to resource ith resource which is at n+i position in the matrix
		wfg[n + i][k] = 1; // edge start from resource ith resource which is at n+i position in the matrix to process k
	}
	// printing the wait for graph matrix
	cout << "   ";
	for (int i = 0; i < m; i++)
	{
		if (i < n)
			cout << "P" << i + 1 << "\t";
		else
			cout << "R" << i + 1 - n << "\t";
	}
	cout << "\n";
	for (int i = 0; i < m; i++)
	{
		if (i < n)
			cout << "P" << i + 1 << " ";
		else
			cout << "R" << i + 1 - n << " ";
		for (int j = 0; j < m; j++)
		{
			cout << wfg[i][j] << "\t";
		}

		cout << "\n";
	}
}
