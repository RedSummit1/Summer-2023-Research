#include <iostream>
#include <vector>

using namespace std;

// Function to add an edge to the graph
void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
}

// Function to perform depth-first search (DFS) and calculate path sum recursively
void calculatePathSumUtil(vector<int> adj[], int u, int sumSoFar, int& totalSum) {
    // Add the current vertex value to the sumSoFar
    sumSoFar += u;

    // If the current vertex has no neighbors (leaf node), add its path sum to the totalSum
    if (adj[u].empty()) {
        totalSum += sumSoFar;
        return;
    }

    // Recursively traverse each neighbor of the current vertex
    for (int v : adj[u]) {
        calculatePathSumUtil(adj, v, sumSoFar, totalSum);
    }
}

// Function to calculate path sum in the graph using recursion
int calculatePathSum(vector<int> adj[], int V) {
    int totalSum = 0;

    // Start DFS traversal from every vertex
    for (int i = 0; i < V; ++i) {
        calculatePathSumUtil(adj, i, 0, totalSum);
    }

    return totalSum;
}

int main() {
    int V = 5; // Number of vertices

    // Adjacency list representation of the graph
    vector<int> adj[V];

    // Adding edges to the graph
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);

    // Calculate the path sum in the graph using recursion
    int pathSum = calculatePathSum(adj, V);

    // Display the calculated path sum
    cout << "Total path sum in the graph: " << pathSum << endl;

    return 0;
}
