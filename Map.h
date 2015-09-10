//Map.h
//Map header file, stores node/edge information

#ifndef PATHS_H
#define PATHS_H
#include <iostream>

using namespace std;

struct Edge { 
	string name;
	int distance;
	double danger;
	int toll;
};

class Map {

public:
	Map();									//Default Constructor
	string orderNumerically(int *, int *);	//For numbering the nodes correctly for the edge convention
	string orderNumerically(int *, int *, int);	//For numbering the nodes correctly for the edge convention

	int* getPath(int);

	int getDistance(int, int);			//get distance of edge
	int getDistance(int, int, int);		//Special case for more than 1 path between nodes

	double getDanger(int, int);			//get danger of edge
	double getDanger(int, int, int);	//Special case for more than 1 path between nodes

	int getToll(int, int);				//get toll of edge
	int getToll(int, int, int);		//Special case for more than 1 path between nodes


private:
	int pathArray[15][15];				//Stores how many edges connect the nodes in a matrix
	int outputArray[15];

	Edge edgeArray[21];					//Array of Edges of the map, stores all the edge data

};

#endif

