#include <iostream>
#include <vector>
#include <unordered_map>
#include <chrono>
#include <fstream>
using namespace std;

// Function to perform depth-first search (DFS) and calculate path sum recursively with memoization
void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
}

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

void test(int num_nodes, vector<int> &adj, ofstream& csvFile){
    //int pathsum = 0;
    for(int i = 1; i < num_nodes; i++){
        addEdge(&adj,(i-1)/2, i);        
    }                                       
    
    auto startTime = std::chrono::high_resolution_clock::now();
    calculatePathSum(&adj, num_nodes);
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>((endTime - startTime)/3.0); // Why did you divide by three?
    csvFile << duration.count() << ',';

    for(int i = 0; i < 8; ++i){
        startTime = std::chrono::high_resolution_clock::now();
        calculatePathSum(&adj, num_nodes);
        endTime = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>((endTime - startTime)/3.0);
        csvFile << duration.count() << ',';
        
    }

    startTime = std::chrono::high_resolution_clock::now();
    calculatePathSum(&adj, num_nodes);
    endTime = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>((endTime - startTime)/3.0);
    csvFile << duration.count() << '\n';
}



int main() {
    //int V = 5; // Number of vertices
    //vector<int> adj[V]; // Adjacency list representation of the graph

    // Adding edges to the graph (example edges)
    /* adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[1].push_back(4); */

    vector<int> adj1[10];
    vector<int> adj2[100];
    vector<int> adj3[1000];
    vector<int> adj4[10000];
    vector<int> adj5[100000];
    ofstream csvFile;

    csvFile.open("../Memoization_data.csv");
    test(10,*adj1,csvFile);
    test(100,*adj2,csvFile);
    test(1000,*adj3,csvFile);
    test(10000,*adj4,csvFile);
    test(100000,*adj5,csvFile);
    csvFile.close();

    // Calculate the path sum in the graph using recursion with memoization
    //int pathSum = calculatePathSum(adj, V);

    // Display the calculated path sum
    //cout << "Total path sum in the graph: " << pathSum << endl;

    return 0;
}

