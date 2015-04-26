//  Liza Girsova
//  CMSC 470: Artificial Intelligence
//  Professor Krebsbach
//
//  ROUTE FINDING USING BREADTH FIRST SEARCH
//  Domain.cpp
//  RouteFinding
//

#include "Domain.h"
#include <string>
#include <map>

// Templated constructor for the node
template<typename T, typename S> Node::Node(T state, S cost, Node* parent){
    Node::state = state;
    Node::cost = cost;
    Node::parent = parent;
}

// Determines possible children of currentNode and returns a list of these nodes
list<Node> Domain::successorFn(Node* currentNode, Node* rootNode){
    list<Node> tempList;
    itr_low = currentCity.lower_bound(currentNode->state);
    itr_high = currentCity.upper_bound(currentNode->state);
    int count = currentCity.count(currentNode->state);
    for(itr = itr_low; itr != itr_high; ++itr){
        pair<string, int> tempPair((itr->first, (itr->second)));  // Used to find route options
        string possibleCity = tempPair.first;
        int newDistance = tempPair.second+currentNode->cost;
        Node tempNode(possibleCity, newDistance, currentNode); // Makes temp node to compare for duplicate
        if(!(checkDuplicates(&tempNode, rootNode)))
        tempList.push_back(tempNode);
    }
    return tempList;
}

// Method to check for potential duplicates. Returns true when duplicates present.
bool Domain::checkDuplicates(Node* tempNode, Node* rootNode){
    Node* compareNode = tempNode;  // compareNode used to go through path to compare to potential node
    while(compareNode != rootNode->parent){
        compareNode = compareNode->parent;
        if(compareNode->state == tempNode->state)
            return true;        
    }
    return false;

}

// Used to print the state in the way that it is represented
void Domain::print(string state){
    cout<<state<<endl;
}

// Determines the path cost
int Domain::getPathCost(Node* currentNode, Node* rootNode){
    return currentNode->cost;
}

// Determines depth
int Domain::getDepth(Node* currentNode, Node* rootNode){
    int pathCount = 0;
    while(currentNode != rootNode->parent){
        currentNode = currentNode->parent;
        pathCount++;
    }
    return pathCount;
}

