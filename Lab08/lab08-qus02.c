// C# implementation of the above approach
using System;
using System.Collections.Generic;

class GFG
{

// A utility function to add an edge in an
// undirected graph.
static void addEdge(List<int> []adj,
					int u, int v)
{
	adj[u].Add(v);
	adj[v].Add(u);
}

// A utility function to delete an edge in an
// undirected graph.
static void delEdge(List<int> []adj,
					int u, int v)
{
	// Traversing through the first vector list
	// and removing the second element from it
	for (int i = 0; i < adj[u].Count; i++)
	{
		if (adj[u][i] == v)
		{
			adj[u].RemoveAt(i);
			break;
		}
	}

	// Traversing through the second vector list
	// and removing the first element from it
	for (int i = 0; i < adj[v].Count; i++)
	{
		if (adj[v][i] == u)
		{
			adj[v].RemoveAt(i);
			break;
		}
	}
}

// A utility function to print the adjacency list
// representation of graph
static void printGraph(List<int> []adj, int V)
{
	for (int v = 0; v < V; ++v)
	{
		Console.Write("vertex " + v + " ");
		foreach (int x in adj[v])
			Console.Write("-> " + x);
		Console.Write("\n");
	}
	Console.Write("\n");
}

// Driver code
public static void Main(String[] args)
{
	int V = 5;
	List<int> []adj = new List<int>[V];
		for (int i = 0; i < V; i++)
			adj[i] = new List<int>();

	// Adding edge as shown in the example figure
	addEdge(adj, 0, 1);
	addEdge(adj, 0, 4);
	addEdge(adj, 1, 2);
	addEdge(adj, 1, 3);
	addEdge(adj, 1, 4);
	addEdge(adj, 2, 3);
	addEdge(adj, 3, 4);

	// Printing adjacency matrix
	printGraph(adj, V);

	// Deleting edge (1, 4)
	// as shown in the example figure
	delEdge(adj, 1, 4);

	// Printing adjacency matrix
	printGraph(adj, V);
}
}

// This code is contributed by PrinciRaj1992
