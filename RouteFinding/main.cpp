//  Liza Girsova
//  CMSC 470: Artificial Intelligence
//  Professor Krebsbach
//
//  ROUTE FINDING USING BREADTH FIRST SEARCH
//  main.cpp
//  RouteFinding
//

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include "Domain.h"
#include "BFS.h"

using namespace std;

int main(int argc, const char * argv[])
{
    cout<<"Algorithm: Breadth-First Search"<<endl;
    cout<<"Domain: Route-Finding"<<endl<<endl;
    cout<<"Enter starting location: ";
    string start;
    getline(cin, start);
    cout<<"Enter final destination: ";
    string goalState;
    getline(cin, goalState);
    cout<<endl;
    
    Domain d;
    BFS newBFS;
    newBFS.runBFS(d, start, goalState);
    
    return 0;
}

