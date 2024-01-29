#pragma once
#include <iostream>
#include <string>

template<class ItemType>
class VertexNode;

template<class ItemType>
class EdgeNode;

template<class ItemType>
class DirectedGraphList {
private:
    int nVertices;
    int nEdges;

public:
    VertexNode<ItemType>* start;

private:
    VertexNode<ItemType>* findVertex(ItemType vertexName);
    void deleteFromEdgeLists(ItemType vertexName);
    void deleteFromVertexList(ItemType vertexName);

public:
    DirectedGraphList();
    ~DirectedGraphList();
    void insertVertex(ItemType vertexName);
    void insertEdge(ItemType source, ItemType destination);
    void deleteVertex(ItemType vertexName);
    void deleteEdge(ItemType source, ItemType destination);
    void display();
    bool edgeExists(ItemType source, ItemType destination);
    int getOutdegree(ItemType vertex);
    int getIndegree(ItemType vertex);
};

template<class ItemType>
class VertexNode {
public:
    ItemType name;
    VertexNode<ItemType>* nextVertex;
    EdgeNode<ItemType>* firstEdge;

public:
    VertexNode(ItemType name) {
        this->name = name;
        nextVertex = nullptr;
        firstEdge = nullptr;
    }
};

template<class ItemType>
class EdgeNode {
public:
    VertexNode<ItemType>* endVertex;
    EdgeNode<ItemType>* nextEdge;

public:
    EdgeNode(VertexNode<ItemType>* v) {
        this->endVertex = v;
        nextEdge = nullptr;
    }
};

template<class ItemType>
DirectedGraphList<ItemType>::DirectedGraphList() {
    nVertices = 0;
    nEdges = 0;
    start = nullptr;
}

template<class ItemType>
DirectedGraphList<ItemType>::~DirectedGraphList() {
    VertexNode<ItemType>* vertexPtr, * tempVertex;
    EdgeNode<ItemType>* edgePtr, * tempEdge;

    vertexPtr = start;
    while (vertexPtr != nullptr) {
        edgePtr = vertexPtr->firstEdge;
        while (edgePtr != nullptr) {
            tempEdge = edgePtr;
            edgePtr = edgePtr->nextEdge;
            delete tempEdge;
        }

        tempVertex = vertexPtr;
        vertexPtr = vertexPtr->nextVertex;
        delete tempVertex;
    }
}

template<class ItemType>
void DirectedGraphList<ItemType>::insertVertex(ItemType vertexName) {
    VertexNode<ItemType>* ptr, * temp;
    bool vertexFound = false;

    ptr = start;

    if (ptr == nullptr) {
        temp = new VertexNode<ItemType>(vertexName);
        start = temp;
        nVertices++;
    }
    else {
        while (ptr->nextVertex != nullptr) {
            if (ptr->name == vertexName) {
                vertexFound = true;
                break;
            }
            ptr = ptr->nextVertex;
        }

        if (vertexFound || ptr->name == vertexName) {
            std::cout << "Vertex already present\n";
        }
        else {
            temp = new VertexNode<ItemType>(vertexName);
            ptr->nextVertex = temp;
            nVertices++;
        }
    }
}

template<class ItemType>
VertexNode<ItemType>* DirectedGraphList<ItemType>::findVertex(ItemType vertexName) {
    VertexNode<ItemType>* ptr = start;

    while (ptr != nullptr) {
        if (ptr->name == vertexName)
            break;

        ptr = ptr->nextVertex;
    }

    return ptr;
}

template<class ItemType>
void DirectedGraphList<ItemType>::insertEdge(ItemType source, ItemType destination) {
    VertexNode<ItemType>* u, * v;
    EdgeNode<ItemType>* edgePtr, * temp;

    bool edgeFound = false;

    if (source == destination) {
        std::cout << "Invalid Edge: source and destination vertices are the same\n";
    }
    else {
        u = findVertex(source);
        v = findVertex(destination);

        if (u == nullptr) {
            std::cout << "Source vertex not present, first insert vertex " << source << "\n";
        }
        else if (v == nullptr) {
            std::cout << "Destination vertex not present, first insert vertex " << destination << "\n";
        }
        else {
            if (u->firstEdge == nullptr) {
                temp = new EdgeNode<ItemType>(v);
                u->firstEdge = temp;
                nEdges++;
            }
            else {
                edgePtr = u->firstEdge;

                while (edgePtr->nextEdge != nullptr) {
                    if (edgePtr->endVertex->name == v->name) {
                        edgeFound = true;
                        break;
                    }

                    edgePtr = edgePtr->nextEdge;
                }

                if (edgeFound || edgePtr->endVertex->name == destination) {
                    std::cout << "Edge already present\n";
                }
                else {
                    temp = new EdgeNode<ItemType>(v);
                    edgePtr->nextEdge = temp;
                    nEdges++;
                }
            }
        }
    }
}
template<class ItemType>
void DirectedGraphList<ItemType>::deleteVertex(ItemType vertexName) {
    deleteFromEdgeLists(vertexName);
    deleteFromVertexList(vertexName);
}
template<class ItemType>
void DirectedGraphList<ItemType>::deleteEdge(ItemType source, ItemType destination) {
    VertexNode<ItemType>* vertexPtr;
    EdgeNode<ItemType>* edgePtr, * temp;

    vertexPtr = findVertex(source);

    if (vertexPtr == nullptr) {
        std::cout << "Edge not found\n";
    }
    else {
        edgePtr = vertexPtr->firstEdge;

        if (edgePtr == nullptr) {
            std::cout << "Edge not found\n";
        }
        else {
            if (edgePtr->endVertex->name == destination) {
                vertexPtr->firstEdge = edgePtr->nextEdge;
                delete edgePtr;
                nEdges--;
            }
            else {
                while (edgePtr->nextEdge != nullptr) {
                    if (edgePtr->nextEdge->endVertex->name == destination) {
                        break;
                    }
                    edgePtr = edgePtr->nextEdge;
                }

                if (edgePtr->nextEdge == nullptr) {
                    std::cout << "Edge not found\n";
                }
                else {
                    temp = edgePtr->nextEdge;
                    edgePtr->nextEdge = edgePtr->nextEdge->nextEdge;
                    delete temp;
                    nEdges--;
                }
            }
        }
    }
}

template<class ItemType>
void DirectedGraphList<ItemType>::deleteFromEdgeLists(ItemType vertexName) {
    VertexNode<ItemType>* vertexPtr;
    EdgeNode<ItemType>* edgePtr, * temp;

    vertexPtr = start;

    while (vertexPtr != nullptr) {
        if (vertexPtr->firstEdge != nullptr) {
            if (vertexPtr->firstEdge->endVertex->name == vertexName) {
                temp = vertexPtr->firstEdge;
                vertexPtr->firstEdge = vertexPtr->firstEdge->nextEdge;
                delete temp;
                nEdges--;
                continue;
            }

            edgePtr = vertexPtr->firstEdge;
            while (edgePtr->nextEdge != nullptr) {
                if (edgePtr->nextEdge->endVertex->name == vertexName) {
                    temp = edgePtr->nextEdge;
                    edgePtr->nextEdge = edgePtr->nextEdge->nextEdge;
                    delete temp;
                    nEdges--;
                    continue;
                }
                edgePtr = edgePtr->nextEdge;
            }
        }

        vertexPtr = vertexPtr->nextVertex;
    }
}

template<class ItemType>
void DirectedGraphList<ItemType>::deleteFromVertexList(ItemType vertexName) {
    VertexNode<ItemType>* vertexPtr, * tempVertex = nullptr;
    EdgeNode<ItemType>* edgePtr, * tempEdge;

    if (start == nullptr) {
        std::cout << "No vertices to be deleted\n";
        return;
    }

    if (start->name == vertexName) {
        tempVertex = start;
        start = start->nextVertex;
    }
    else {
        vertexPtr = start;
        while (vertexPtr->nextVertex != nullptr) {
            if (vertexPtr->nextVertex->name == vertexName)
                break;
            vertexPtr = vertexPtr->nextVertex;
        }

        if (vertexPtr->nextVertex != nullptr) {
            tempVertex = vertexPtr->nextVertex;
            vertexPtr->nextVertex = vertexPtr->nextVertex->nextVertex;
        }
        else {
            std::cout << "Vertex not found\n";
        }
    }

    if (tempVertex) {
        // Before deleting the tempVertex, delete all the edges going from this vertex
        edgePtr = tempVertex->firstEdge;
        while (edgePtr != nullptr) {
            tempEdge = edgePtr;
            edgePtr = edgePtr->nextEdge;
            delete tempEdge;
            nEdges--;
        }

        delete tempVertex;
        nVertices--;
    }
}

// Implement other member functions: display, edgeExists, getOutdegree, getIndegree

template<class ItemType>
void DirectedGraphList<ItemType>::display() {
    VertexNode<ItemType>* vertexPtr;
    EdgeNode<ItemType>* edgePtr;

    vertexPtr = start;

    while (vertexPtr != nullptr) {
        std::cout << "Vertex: " << vertexPtr->name << "\n";

        edgePtr = vertexPtr->firstEdge;
        while (edgePtr != nullptr) {
            std::cout << "Edge: " << vertexPtr->name << " -> " << edgePtr->endVertex->name << "\n";
            edgePtr = edgePtr->nextEdge;
        }

        vertexPtr = vertexPtr->nextVertex;
    }
}

template<class ItemType>
bool DirectedGraphList<ItemType>::edgeExists(ItemType source, ItemType destination) {
    VertexNode<ItemType>* vertexPtr;
    EdgeNode<ItemType>* edgePtr;
    bool edgeFound = false;

    vertexPtr = findVertex(source);

    if (vertexPtr) {
        edgePtr = vertexPtr->firstEdge;
        while (edgePtr != nullptr) {
            if (edgePtr->endVertex->name == destination) {
                edgeFound = true;
                break;
            }
            edgePtr = edgePtr->nextEdge;
        }
    }

    return edgeFound;
}

template<class ItemType>
int DirectedGraphList<ItemType>::getOutdegree(ItemType vertex) {
    VertexNode<ItemType>* vertexPtr;
    EdgeNode<ItemType>* edgePtr;
    int outdegree = 0;

    vertexPtr = findVertex(vertex);
    if (vertexPtr == nullptr)
        throw std::exception("Invalid Vertex");

    edgePtr = vertexPtr->firstEdge;
    while (edgePtr != nullptr) {
        outdegree++;
        edgePtr = edgePtr->nextEdge;
    }

    return outdegree;
}

template<class ItemType>
int DirectedGraphList<ItemType>::getIndegree(ItemType vertex) {
    VertexNode<ItemType>* vertexPtr;
    EdgeNode<ItemType>* edgePtr;
    int indegree = 0;

    if (findVertex(vertex) == nullptr)
        throw std::exception("Invalid Vertex");

    vertexPtr = start;
    while (vertexPtr != nullptr) {
        edgePtr = vertexPtr->firstEdge;
        while (edgePtr != nullptr) {
            if (edgePtr->endVertex->name == vertex) {
                indegree++;
            }
            edgePtr = edgePtr->nextEdge;
        }
        vertexPtr = vertexPtr->nextVertex;
    }

    return indegree;
}
