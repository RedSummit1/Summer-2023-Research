#include <iostream>
#include <chrono>
#include <vector>
#include <stack>

using namespace std;

// Function to add an edge to the graph
void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
}

// Function to calculate path sum in the graph using Iterative DFS
int calculatePathSum(vector<int> adj[], int V) {
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
                if (adj[u].empty()) {
                    totalSum += sumSoFar;
                } else {
                    for (int v : adj[u]) {
                        stk.push({v, sumSoFar}); // Push adj1acent nodes to the stack with updated path sum
                    }
                }
            }
        }
        // Clear visited array for the next DFS traversal
        fill(visited.begin(), visited.end(), false);
    }

    return totalSum;
}

/* void test(int num_nodes, vector<int>& adj){ */
/*     for(int i = 1; i < num_nodes; i++){ */
/*         addEdge(*adj,(i-1)/2, i);         */
/*     }                                       */ 
/* } */
/*  */
int main() {
    //Going to creat
    /*  vector<int> adj2[V * 10];  */ //Adjacency list representation of the graph
    /*  vector<int> adj3[V * 100]; / */ //Adjacency list representation of the graph
    /*  vector<int> adj4[V * 1000];  */// Adjacency list representation of the graph
    /*  vector<int> adj5[V * 10000]; */ // Adjacency list representation of the graph
    //{adj1, adj2, adj3, adj4, adj5};

         
    int V = 100; 
    vector<int> adj1[V];

    for(int i = 1; i < V; i++){
        addEdge(adj1,(i-1)/2, i);        
    }                                       





    // Adding edges to the graph (example edges)
/*     addedge(adj1, 0, 1); */
/*     addedge(adj1, 0, 2); */
/*     addedge(adj1, 1, 3); */
/*     addedge(adj1, 1, 4); */
/*     addedge(adj1, 2, 5); */
/*     addedge(adj1, 2, 6); */
/*     addedge(adj1, 3, 7); */
/*     addedge(adj1, 3, 8); */

    int pathSum = calculatePathSum(adj1, V);
    //Display the calculated path sum
    cout << "Total path sum in the graph: " << pathSum << endl;

    return 0;
}
