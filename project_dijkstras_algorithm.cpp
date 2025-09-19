#include <iostream>   // for input and output
#include <limits.h>   // for using INT_MAX as infinity
using namespace std;

#define MAXNODES 100   // maximum number of nodes allowed


// ARRAYS USED IN PROGRAM

int dijkstraGraphArr[MAXNODES][MAXNODES];   // graph stored as a matrix
int dijkstraDistanceArr[MAXNODES];          // keeps shortest distance from start
bool dijkstraVisitedArr[MAXNODES];          // marks if a node is already checked
int dijkstraParentArr[MAXNODES];            // stores path by saving parent of each node


// FUNCTION: dijkstraFindMinIndex
// Finds the node with the smallest distance value
// Only looks at nodes that are not visited yet

int dijkstraFindMinIndex(int totalNodes) {
    int minValue = INT_MAX;   // start with a very large number
    int minIndex = -1;        // no node chosen yet

    for (int node = 0; node < totalNodes; node++) {
        if (!dijkstraVisitedArr[node] && dijkstraDistanceArr[node] < minValue) {
            minValue = dijkstraDistanceArr[node];
            minIndex = node;
        }
    }
    return minIndex; // return node with the smallest distance
}


// FUNCTION: dijkstraRunAlgo
// Steps of Dijkstra’s algorithm:
// 1. Set all distances to infinity, none visited
// 2. Choose node with smallest distance
// 3. Update neighbors if shorter path found
// 4. Repeat until all done
// 5. Show shortest cost and path

void dijkstraRunAlgo(int totalNodes, int startNode, int endNode) {
    // Step 1: Set all arrays ready
    for (int i = 0; i < totalNodes; i++) {
        dijkstraDistanceArr[i] = INT_MAX;   // all nodes far at first
        dijkstraVisitedArr[i] = false;      // none visited yet
        dijkstraParentArr[i] = -1;          // no parent
    }

    dijkstraDistanceArr[startNode] = 0;     // distance from start to itself is 0

    // Step 2 and 3: check all nodes
    for (int count = 0; count < totalNodes - 1; count++) {
        int currentNode = dijkstraFindMinIndex(totalNodes); // pick closest node
        if (currentNode == -1) break;  // no node left
        dijkstraVisitedArr[currentNode] = true; // mark it as done

        // go through neighbors
        for (int neighbor = 0; neighbor < totalNodes; neighbor++) {
            if (!dijkstraVisitedArr[neighbor] && dijkstraGraphArr[currentNode][neighbor] != 0 &&
                dijkstraDistanceArr[currentNode] != INT_MAX &&
                dijkstraDistanceArr[currentNode] + dijkstraGraphArr[currentNode][neighbor] < dijkstraDistanceArr[neighbor]) {
                
                // update distance if new path is shorter
                dijkstraDistanceArr[neighbor] = dijkstraDistanceArr[currentNode] + dijkstraGraphArr[currentNode][neighbor];
                // set parent for path
                dijkstraParentArr[neighbor] = currentNode;
            }
        }
    }

    // Step 4: Print result
    if (dijkstraDistanceArr[endNode] == INT_MAX) {
        cout << "No path exists from " << startNode << " to " << endNode << endl;
        return;
    }

    cout << "Shortest cost from " << startNode << " to " << endNode << " is: " << dijkstraDistanceArr[endNode] << endl;

    // build path
    cout << "Path: ";
    int pathNodes[MAXNODES], pathLength = 0;
    for (int v = endNode; v != -1; v = dijkstraParentArr[v]) {
        pathNodes[pathLength++] = v;   // store in reverse
    }

    // print path forward
    for (int i = pathLength - 1; i >= 0; i--) {
        cout << pathNodes[i];
        if (i != 0) cout << " -> ";
    }
    cout << endl;
}


// MAIN FUNCTION
// Takes graph input from user, runs Dijkstra

int main() {
    int totalNodes, totalEdges;

    cout << "Enter number of vertices: ";
    cin >> totalNodes;
    cout << "Enter number of edges: ";
    cin >> totalEdges;

    // fill graph with 0 first (no edges)
    for (int i = 0; i < totalNodes; i++) {
        for (int j = 0; j < totalNodes; j++) {
            dijkstraGraphArr[i][j] = 0;
        }
    }

    // input graph edges
    cout << "Enter edges in format: u v w (0-indexed nodes)\n";
    for (int i = 0; i < totalEdges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dijkstraGraphArr[u][v] = w;  // u to v
        dijkstraGraphArr[v][u] = w;  // v to u
    }

    int startNode, endNode;
    cout << "Enter start node (0-" << totalNodes - 1 << "): ";
    cin >> startNode;
    cout << "Enter end node (0-" << totalNodes - 1 << "): ";
    cin >> endNode;

    dijkstraRunAlgo(totalNodes, startNode, endNode);

    return 0;
}
