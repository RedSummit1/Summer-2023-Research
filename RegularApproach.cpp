#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>

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


void test(int num_nodes, vector<int> &adj, ofstream& csvFile){
    //int pathsum = 0;
    for(int i = 1; i < num_nodes; i++){
        addEdge(&adj,(i-1)/2, i);        
    }                                       
    
    auto startTime = std::chrono::high_resolution_clock::now();
    calculatePathSum(&adj, num_nodes);
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>((endTime - startTime)/3.0);
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

    // Adjacency list representation of the graph
    //vector<int> adj[V];

    // Adding edges to the graph
   /*  addEdge(adj, 0, 1); */
   /*  addEdge(adj, 0, 2); */
   /*  addEdge(adj, 1, 3); */
   /*  addEdge(adj, 1, 4); */
    vector<int> adj1[10];
    vector<int> adj2[100];
    vector<int> adj3[1000];
    vector<int> adj4[10000];
    vector<int> adj5[100000];

    // Calculate the path sum in the graph using recursion
    //int pathSum = calculatePathSum(adj, V);

    // Display the calculated path sum
    //cout << "Total path sum in the graph: " << pathSum << endl;
    ofstream csvFile;
    csvFile.open("../Regular_data.csv");
    test(10,*adj1,csvFile);
    test(100,*adj2,csvFile);
    test(1000,*adj3,csvFile);
    test(10000,*adj4,csvFile);
    test(100000,*adj5,csvFile);
    csvFile.close();

    return 0;
}
