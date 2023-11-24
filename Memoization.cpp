#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Function to perform depth-first search (DFS) and calculate path sum recursively with memoization
void calculatePathSumUtil(vector<int> adj[], int u, int sumSoFar, int& totalSum, unordered_map<int, int>& memo) {
    // Add the current vertex value to the sumSoFar
    sumSoFar += u;

    // If the current vertex has no neighbors (leaf node), add its path sum to the totalSum
    if (adj[u].empty()) {
        totalSum += sumSoFar;
        return;
    }

    // Check if the path sum for the current node is already memoized
    if (memo.find(u) != memo.end()) {
        totalSum += memo[u] + sumSoFar; // Use memoized value and current sum
        return;
    }

    // Recursively traverse each neighbor of the current vertex
    for (int v : adj[u]) {
        calculatePathSumUtil(adj, v, sumSoFar, totalSum, memo);
    }

    // Memoize the path sum for the current node
    memo[u] = sumSoFar;
}

// Function to calculate path sum in the graph using recursion with memoization
int calculatePathSum(vector<int> adj[], int V) {
    int totalSum = 0;
    unordered_map<int, int> memo; // Memoization map

    // Start DFS traversal from every vertex
    for (int i = 0; i < V; ++i) {
        calculatePathSumUtil(adj, i, 0, totalSum, memo);
    }

    return totalSum;
}

int main() {
    int V = 5; // Number of vertices
    vector<int> adj[V]; // Adjacency list representation of the graph

    // Adding edges to the graph (example edges)
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[1].push_back(4);

    // Calculate the path sum in the graph using recursion with memoization
    int pathSum = calculatePathSum(adj, V);

    // Display the calculated path sum
    cout << "Total path sum in the graph: " << pathSum << endl;

    return 0;
}

