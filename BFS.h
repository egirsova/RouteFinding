//  Liza Girsova
//  CMSC 470: Artificial Intelligence
//  Professor Krebsbach
//  
//  ROUTE FINDING USING BREADTH FIRST SEARCH
//  BFS.h
//  RouteFinding
//


#ifndef __RouteFinding__BFS__
#define __RouteFinding__BFS__

#include <iostream>
#include <stdlib.h>
#include <queue>
#include <string>
#include "Domain.h"

using namespace std;

class BFS{
public:
    queue<Node> queue;  // Creates queue to store the Nodes
    
    template<typename T, typename S, typename R>
    void runBFS(T domain, S initialState, R goalState){ // Runs the BFS algorithm
        int nodeCount = 0;
        int nodeExpansions = 0;
        // Creates rootNode based on initialState
        Node rootNode = domain.createInitialState(initialState); 
        queue.push(rootNode);
        nodeCount++;
        
        while(!(domain.goalState(queue.front().state, goalState))){  // Loops to add nodes to queue
            if(nodeExpansions < 50){
                cout<<"Current Node Expansion: ";
                domain.print(queue.front().state);
            }
            nodeExpansions++;
            list<Node> tempList; // Creates a temporary list that stores the children of Node
            tempList = domain.successorFn(&queue.front(), &rootNode);
            while(!tempList.empty()){
                queue.push(tempList.front());
                nodeCount++;
                tempList.pop_front();
            }
            queue.pop();
        }
        cout<<endl<<"GOAL REACHED: ";
        domain.print(queue.front().state);
        cout<<endl;
        cout<<"Nodes generated: "<< nodeCount<<endl;
        cout<<"Nodes expanded: "<<nodeExpansions<<endl;
        cout<<"Depth: "<<domain.getDepth(&queue.front(), &rootNode)<<endl;
        cout<<"Path Cost: "<<domain.getPathCost(&queue.front(), &rootNode)<<endl<<endl;
        domain.printFinal(queue.front(), &rootNode);
    }
};

#endif /* defined(__RouteFinding__File__) */
