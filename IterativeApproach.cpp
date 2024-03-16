#include <iostream>
#include <vector>
#include <stack>
#include <chrono>
#include <fstream>

using namespace std;

// Function to add an edge to the graph
void addEdge(vector<int> graph[], int u, int v) {
    graph[u].push_back(v);
}

// Function to calculate path sum in the graph using Iterative DFS
int calculatePathSum(vector<int> graph[], int V) {
    int totalSum = 0;

    // Stack to perform iterative DFS
    stack<pair<int, int>> stk; // (currentNode, pathSum)
    vector<bool> visited(V, false);

    // Start DFS traversal from every vertex
    for (int i = 0; i < V; ++i) {
        stk.push({i, 0}); // Initialize stack with the starting node and path sum 0

        while (!stk.empty()) {
            pair<int, int> curr = stk.top();
            stk.pop();

            int u = curr.first;
            int sumSoFar = curr.second + u; // Calculate current path sum

            if (!visited[u]) {
                visited[u] = true;

                // If the current vertex is a leaf node, add its path sum to the totalSum
                if (graph[u].empty()) {
                    totalSum += sumSoFar;
                } else {
                    for (int v : graph[u]) {
                        stk.push({v, sumSoFar}); // Push graph1acent nodes to the stack with updated path sum
                    }
                }
            }
        }
        // Clear visited array for the next DFS traversal
        fill(visited.begin(), visited.end(), false);
    }
	cout << totalSum << endl;	
    return totalSum;
}

void test(int num_nodes, vector<int> &graph, ofstream& csvFile){
    //int pathsum = 0;
    for(int i = 1; i < num_nodes; i++){
        addEdge(&graph,(i-1)/2, i);        
    }                                       
    
    auto startTime = std::chrono::high_resolution_clock::now();
    calculatePathSum(&graph, num_nodes);
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>((endTime - startTime)/3.0);
    csvFile << duration.count() << ',';

    for(int i = 0; i < 8; ++i){
        startTime = std::chrono::high_resolution_clock::now();
        calculatePathSum(&graph, num_nodes);
        endTime = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>((endTime - startTime)/3.0);
        csvFile << duration.count() << ',';
        
    }

    startTime = std::chrono::high_resolution_clock::now();
    calculatePathSum(&graph, num_nodes);
    endTime = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>((endTime - startTime)/3.0);
    csvFile << duration.count() << '\n';






    /* auto startTime = std::chrono::high_resolution_clock::now();
    calculatePathSum(&graph, num_nodes);
    calculatePathSum(&graph, num_nodes);
    calculatePathSum(&graph, num_nodes);
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>((endTime - startTime)/3.0);
    auto startTime = std::chrono::high_resolution_clock::now();
    calculatePathSum(&graph, num_nodes);
    calculatePathSum(&graph, num_nodes);
    calculatePathSum(&graph, num_nodes);
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>((endTime - startTime)/3.0);
    cout << "Total path sum in the graph: " << (pathSum/3) << endl;
    std::cout << "Exection time: " << duration.count() << " microseconds\n";
    */
    
}
int main() {
    /*  vector<int> graph2[V * 10];  */ //Adjacency list representation of the graph
    /*  vector<int> graph3[V * 100]; / */ //Adjacency list representation of the graph
    /*  vector<int> graph4[V * 1000];  */// Adjacency list representation of the graph
    /*  vector<int> graph5[V * 10000]; */ // Adjacency list representation of the graph
    //{graph1, graph2, graph3, graph4, graph5};

         
    //int node_sizes[] {10,100,1000,10000}; 
    vector<int> graph1[10];
    vector<int> graph2[100];
    vector<int> graph3[1000];
    vector<int> graph4[10000];
    vector<int> graph5[100000];

/*     for(int i = 1; i < V; i++){ */
/*         addEdge(graph1,(i-1)/2, i);         */
/*     }                                        */





    // Adding edges to the graph (example edges)
/*     addedge(graph1, 0, 1); */
/*     addedge(graph1, 0, 2); */
/*     addedge(graph1, 1, 3); */
/*     addedge(graph1, 1, 4); */
/*     addedge(graph1, 2, 5); */
/*     addedge(graph1, 2, 6); */
/*     addedge(graph1, 3, 7); */
/*     addedge(graph1, 3, 8); */

    //int pathSum = calculatePathSum(graph1, V);
    //Display the calculated path sum
    ofstream csvFile;
    csvFile.open("../Iterative_data.csv");
    test(10,*graph1,csvFile);
    test(100,*graph2,csvFile);
    test(1000,*graph3,csvFile);
    test(10000,*graph4,csvFile);
    test(100000,*graph5,csvFile);
    csvFile.close();
    cout << "Done" << endl;
	
    return 0;
}
