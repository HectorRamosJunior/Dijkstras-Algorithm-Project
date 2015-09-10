//Person.h
//Person header file, stores traveled information and makes path decisions

#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <vector>
#include "Map.h"

using namespace std;

class Person{
public:
	Person(int, int);	//Default Constructor, takes current/end node as input

	int leastDistance();	//runs Dijkstra's algorithm for the distance values
	double leastDanger();	//runs Dijkstra's algorithm for the danger values
	int leastToll();		//runs Dijkstra's algorithm for the toll values
	void printPath();	//runs a recursive print on the previousNode array

	int startNode, endNode;	//store the start/end nodes for the problem


private:
	Map map;
	bool finishedSet[15];	//stores the finished nodes for Dijkstra's algorithm

	int distanceArray[15], tollArray[15]; //the respective arrays for Dijkstra's algorithm values
	double safetyArray[15];

	int previousNode[15];	//stores the node's 'shortest' path node it was connected to previously

};


#endif