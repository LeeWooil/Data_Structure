#include "GraphType_LinkedList.h"

// Other member function definitions...

int main() {
    DirectedGraphList<int> dGraph;

    try {
        // Creating the graph, inserting the vertices and edges
        dGraph.insertVertex(0);
        dGraph.insertVertex(1);
        dGraph.insertVertex(2);
        dGraph.insertVertex(3);

        dGraph.insertEdge(0, 3);
        dGraph.insertEdge(1, 2);
        dGraph.insertEdge(2, 3);
        dGraph.insertEdge(3, 1);
        dGraph.insertEdge(0, 2);

        // Display the graph
        dGraph.display();
        std::cout << "\n";

        // Deleting an edge
        dGraph.deleteEdge(0, 2);

        // Display the graph
        dGraph.display();
        std::cout << "\n";

        // Deleting a vertex
        dGraph.deleteVertex(0);

        // Display the graph
        dGraph.display();

        // Check if there is an edge between two vertices
        std::cout << "Edge exist : " << (dGraph.edgeExists(2, 3) ? "True" : "False") << "\n";

        // Display Indegree and Outdegree of a vertex
        std::cout << "Outdegree : " << dGraph.getOutdegree(3) << "\n";
        std::cout << "Indegree : " << dGraph.getIndegree(3) << "\n";

    }
    catch (std::exception& e) {
        std::cout << e.what() << "\n";
    }

    return 0;
}
