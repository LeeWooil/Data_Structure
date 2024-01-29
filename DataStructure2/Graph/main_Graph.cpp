#include <iostream>
#include "GraphType.h"

int main() {
    const int MAX_VERTICES = 5;

    GraphType<int> myGraph(MAX_VERTICES);

    // Adding vertices
    myGraph.AddVertex(1);
    myGraph.AddVertex(2);
    myGraph.AddVertex(3);
    myGraph.AddVertex(4);
    myGraph.AddVertex(5);

    // Adding edges
    myGraph.AddEdge(1, 2, 1);
    myGraph.AddEdge(1, 3, 3);
    myGraph.AddEdge(2, 4, 2);
    myGraph.AddEdge(3, 4, 4);
    myGraph.AddEdge(4, 5, 5);

    // Testing WeightIs function
    std::cout << "Weight from 1 to 2: " << myGraph.WeightIs(1, 2) << std::endl;
    std::cout << "Weight from 2 to 4: " << myGraph.WeightIs(2, 4) << std::endl;

    // Testing GetToVertices function
    QueType<int> adjacentVertices;
    myGraph.GetToVertices(1, adjacentVertices);

    std::cout << "Vertices adjacent to 1: ";
    while (!adjacentVertices.IsEmpty()) {
        int vertex;
        adjacentVertices.Dequeue(vertex);
        std::cout << vertex << " ";
    }
    std::cout << std::endl;

    // Testing MarkVertex and IsMarked functions
    myGraph.MarkVertex(1);
    myGraph.MarkVertex(3);

    std::cout << "Is 1 marked? " << (myGraph.IsMarked(1) ? "Yes" : "No") << std::endl;
    std::cout << "Is 2 marked? " << (myGraph.IsMarked(2) ? "Yes" : "No") << std::endl;

    return 0;
}
