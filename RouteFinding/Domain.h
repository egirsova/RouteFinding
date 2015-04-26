//  Liza Girsova
//  CMSC 470: Artificial Intelligence
//  Professor Krebsbach
//
//  ROUTE FINDING USING BREADTH FIRST SEARCH
//  Domain.h
//  RouteFinding
//

#ifndef __RouteFinding__Domain__
#define __RouteFinding__Domain__

#include <iostream>
#include <map>
#include <string>
#include <list>

using namespace std;

class Node
{
public:
    string state;
    int cost;
    Node *parent;
    template<typename T, typename S> Node(T state, S cost, Node* parent);
};

class Domain
{
public:
    //Key: current city. T: pair that consists of the potential city name (to travel to) and distance
    typedef multimap<string, pair<string,int>> CityMap;
    CityMap currentCity;
    CityMap::iterator itr, itr_low, itr_high;
    
    // Creates the initial state. Adds all potential routes and distances. Returns the initial state.
    template<typename T>
    Node createInitialState(T startState){
        currentCity.insert(make_pair("Oradea", make_pair("Zerind", 71)));
        currentCity.insert(make_pair("Oradea", make_pair("Sibiu", 151)));
        currentCity.insert(make_pair("Zerind", make_pair("Oradea", 71)));
        currentCity.insert(make_pair("Zerind", make_pair("Arad", 75)));
        currentCity.insert(make_pair("Arad", make_pair("Zerind", 75)));
        currentCity.insert(make_pair("Arad", make_pair("Sibiu", 140)));
        currentCity.insert(make_pair("Arad", make_pair("Timisoara", 118)));
        currentCity.insert(make_pair("Timisoara", make_pair("Arad", 118)));
        currentCity.insert(make_pair("Timisoara", make_pair("Lugoj", 111)));
        currentCity.insert(make_pair("Lugoj", make_pair("Timisoara", 111)));
        currentCity.insert(make_pair("Lugoj", make_pair("Mehadia", 70)));
        currentCity.insert(make_pair("Mehadia", make_pair("Lugoj", 70)));
        currentCity.insert(make_pair("Mehadia", make_pair("Drobeta", 75)));
        currentCity.insert(make_pair("Drobeta", make_pair("Mehadia", 75)));
        currentCity.insert(make_pair("Drobeta", make_pair("Craiova", 120)));
        currentCity.insert(make_pair("Craiova", make_pair("Drobeta", 120)));
        currentCity.insert(make_pair("Craiova", make_pair("Rimnicu Vilcea", 146)));
        currentCity.insert(make_pair("Craiova", make_pair("Pitesti", 138)));
        currentCity.insert(make_pair("Rimnicu Vilcea", make_pair("Craiova", 146)));
        currentCity.insert(make_pair("Rimnicu Vilcea", make_pair("Pitesti", 97)));
        currentCity.insert(make_pair("Rimnicu Vilcea", make_pair("Sibiu", 80)));
        currentCity.insert(make_pair("Sibiu", make_pair("Rimnicu Vilcea", 80)));
        currentCity.insert(make_pair("Sibiu", make_pair("Arad", 140)));
        currentCity.insert(make_pair("Sibiu", make_pair("Oradea", 151)));
        currentCity.insert(make_pair("Sibiu", make_pair("Fagaras", 99)));
        currentCity.insert(make_pair("Fagaras", make_pair("Sibiu", 99)));
        currentCity.insert(make_pair("Fagaras", make_pair("Bucharest", 211)));
        currentCity.insert(make_pair("Pitesti", make_pair("Rimnicu Vilcea", 97)));
        currentCity.insert(make_pair("Pitesti", make_pair("Craiova", 138)));
        currentCity.insert(make_pair("Pitesti", make_pair("Bucharest", 101)));
        currentCity.insert(make_pair("Bucharest", make_pair("Pitesti", 101)));
        currentCity.insert(make_pair("Bucharest", make_pair("Fagaras", 211)));
        currentCity.insert(make_pair("Bucharest", make_pair("Giurgiu", 90)));
        currentCity.insert(make_pair("Bucharest", make_pair("Urziceni", 85)));
        currentCity.insert(make_pair("Giurgiu", make_pair("Bucharest", 90)));
        currentCity.insert(make_pair("Urziceni", make_pair("Bucharest", 85)));
        currentCity.insert(make_pair("Urziceni", make_pair("Hirsova", 98)));
        currentCity.insert(make_pair("Urziceni", make_pair("Vaslui", 142)));
        currentCity.insert(make_pair("Hirsova", make_pair("Urziceni", 98)));
        currentCity.insert(make_pair("Hirsova", make_pair("Eforie", 86)));
        currentCity.insert(make_pair("Eforie", make_pair("Hirsova", 86)));
        currentCity.insert(make_pair("Vaslui", make_pair("Urziceni", 142)));
        currentCity.insert(make_pair("Vaslui", make_pair("Iasi", 92)));
        currentCity.insert(make_pair("Iasi", make_pair("Vaslui", 92)));
        currentCity.insert(make_pair("Iasi", make_pair("Neamt", 87)));
        currentCity.insert(make_pair("Neamt", make_pair("Iasi", 87)));
        
        // Creates rootNode
        Node tempRootNode(startState, 0, nullptr);
        Node* rootPointer = &tempRootNode;
        Node rootNode(startState, 0, rootPointer);
        return rootNode;
    }
        
    // Prints the final solution/goal in a user-friendly way
    template <typename T, typename S>
    void printFinal(T currentNode, S rootNode){
        Node* currentNodePoint = &currentNode;  // Used because we want to compare pointers
        cout<<"Path: "<<endl;
        list<string> path;
        list<string>::iterator itr;
        while(currentNodePoint != rootNode->parent){
            path.push_front(currentNodePoint->state);
            currentNodePoint = currentNodePoint->parent;
        }
        for(itr = path.begin(); itr != path.end(); ++itr){
            cout<<*itr<<endl;
        }
    }
    
    // Checks for goalState
    template<typename T, typename S>
    bool goalState(T currentState, S goalState){
        if (currentState == goalState)
            return true;
        else
            return false;
    }
    
    // Remaining methods that are not templated
    list<Node> successorFn(Node* currentNode, Node* rootNode);    
    bool checkDuplicates(Node* tempNode, Node* parent);
    void print(string state);
    int  getDepth(Node* currentNode, Node* rootNode);
    int getPathCost(Node* currentNode, Node* rootNode);
    
};

#endif /* defined(__RouteFinding__Domain__) */
