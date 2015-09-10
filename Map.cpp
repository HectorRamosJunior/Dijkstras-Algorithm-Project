//Map.cpp
//For storing all relevant edge/node information

#include <iostream>
#include <string>
#include <sstream>
#include "Map.h"

using namespace std;


Map::Map() {		//Default Constructor, initializes all relevant map information		    	
							  
	//pathArray matrix stores the number of edges between the nodes defined	
	
	for (int i = 0; i < 15; i++){
		outputArray[i] = 0;
		for (int j = 0; j < 15; j++){
			pathArray[i][j] = 0;
			
		}
	}
		
	//The node/path matrix is shown below
	/*
	//1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15 
	{ 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, //node1, Cardinal City
	{ 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, //node2, Bob the Knight's Castle
	{ 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, //node3, Ye Energy Alternative
	{ 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, //node4, Mooseville
	{ 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, //node5, Grandma's House
	{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, //node6, Big Hole
	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, //node7, The Professor's Tower
	{ 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0 }, //node8, Old Queen's
	{ 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0 }, //node9, Nunnery
	{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0 }, //node10, Three Silos
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 }, //node11, NYC
	{ 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0 }, //node12, Scarlet's Hamlet
	{ 0, 0, 0, 0, 0, 0, 0, 2, 1, 0, 1, 1, 0, 0, 1 }, //node13, Phil's City
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0 }, //node14, South City
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0 }, //node15, Chateau
	//1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15 
	*/
	pathArray[0][1] = 1;  pathArray[0][4] = 1;
	pathArray[1][0] = 1;  pathArray[1][2] = 1;  pathArray[1][6] = 1;
	pathArray[2][1] = 1;  pathArray[2][3] = 1;  pathArray[2][7] = 1;
	pathArray[3][2] = 1;  pathArray[3][8] = 1;
	pathArray[4][0] = 1;  pathArray[4][5] = 1;  pathArray[4][9] = 1;
	pathArray[5][4] = 1;
	pathArray[6][1] = 1;  pathArray[6][11] = 1;
	pathArray[7][2] = 1;  pathArray[7][8] = 1;  pathArray[7][12] = 2;
	pathArray[8][3] = 1;  pathArray[8][7] = 1;  pathArray[8][12] = 1;
	pathArray[9][4] = 1;  pathArray[9][11] = 1;  pathArray[9][13] = 1;
	pathArray[10][12] = 1;  pathArray[10][14] = 1;
	pathArray[11][6] = 1;  pathArray[11][9] = 1;  pathArray[11][12] = 1; pathArray[11][13] = 1;
	pathArray[12][7] = 2;  pathArray[12][8] = 1;  pathArray[12][10] = 1;  pathArray[12][11] = 1; pathArray[12][14] = 1;
	pathArray[13][9] = 1;  pathArray[13][11] = 1; 
	pathArray[14][10] = 1;  pathArray[14][12] = 1;  


	edgeArray[0] = { "edge12", 34, 0.10, 0 }; //route21				//Data Stored as follows:
	edgeArray[1] = { "edge15", 30, 0.03, 0 }; //route20				//{Name, Distance, Danger, Toll}
	edgeArray[2] = { "edge23", 63, 0.25, 0 }; //route10
	edgeArray[3] = { "edge27", 50, 0.95, 0 }; //route13
	edgeArray[4] = { "edge34", 59, 0.10, 0 }; //route8
	edgeArray[5] = { "edge38", 54, 0.10, 10 }; //route9
	edgeArray[6] = { "edge49", 41, 0.05, 10 }; //route7				//Edges named via the convention:
	edgeArray[7] = { "edge56", 15, 0.10, 0 }; //route19				//edge (node1) (node2) 
	edgeArray[8] = { "edge510", 35, 0.10, 0 }; //route18			//node1 < node2; numerical order
	edgeArray[9] = { "edge712", 50, 0.95, 0 }; //route12			
	edgeArray[10] = { "edge89", 51, 0.10, 0 }; //route6
	edgeArray[11] = { "edge8131", 61, 0.10, 10 }; //route5			/Special case, two paths
	edgeArray[12] = { "edge8132", 135, 0.00, 0 }; //route16			//add 1-2 to the end of the path
	edgeArray[13] = { "edge913", 100, 0.05, 0 }; //route4
	edgeArray[14] = { "edge1012", 80, 0.20, 0 }; //route14
	edgeArray[15] = { "edge1014", 40, 0.05, 0 }; //route17
	edgeArray[16] = { "edge1113", 70, 0.20, 10 }; //route2
	edgeArray[17] = { "edge1115", 50, 0.05, 0 }; //route1
	edgeArray[18] = { "edge1214", 35, 0.10, 0 }; //route15
	edgeArray[19] = { "edge1213", 35, 0.01, 0 }; //route11
	edgeArray[20] = { "edge1315", 25, 0.10, 0 }; //route3

}

string Map::orderNumerically(int *node1, int *node2){
	if ( (*node1) > (*node2) ){		//Since the edges are ordered numerically, node1<node2 must be followed
		int temp;

		temp = (*node1);		//Swaps the node parameters entered around to give the proper edge
		(*node1) = (*node2);
		(*node2) = temp;
	}

	std::ostringstream nodeString;
	nodeString << (*node1) << (*node2);

	string edgeName = "edge";
	edgeName += nodeString.str();		//adds the nodes to the string for identification

	return edgeName;
}

string Map::orderNumerically(int *node1, int *node2, int pathNumber){
	if ((*node1) > (*node2)){		//Since the edges are ordered numerically, node1<node2 must be followed
		int temp;

		temp = (*node1);		//Swaps the node parameters entered around to give the proper edge
		(*node1) = (*node2);
		(*node2) = temp;
	}

	std::ostringstream nodeString;
	nodeString << (*node1) << (*node2) << pathNumber;

	string edgeName = "edge";
	edgeName += nodeString.str();		//adds the nodes to the string for identification

	return edgeName;
}

int* Map::getPath(int node1){
	int node = node1 - 1;


	for (int i = 0; i < 15; i++){
		outputArray[i] = pathArray[node][i];
		//cout << outputArray[i] << " ";
	}

	//cout << endl;
	
	return outputArray;
}

int Map::getDistance(int node1, int node2){

	string edgeName = orderNumerically(&node1, &node2);	//sorts the nodes, returns edgeName

	for (int i = 0; i < 21; i++){		//finds the edge element desired, returns distance
		if (edgeArray[i].name == edgeName)
			return edgeArray[i].distance;
	}

}

int Map::getDistance(int node1, int node2, int pathNumber){

	string edgeName = orderNumerically(&node1, &node2, pathNumber);	//sorts the node numerically for the edgeName convention

	for (int i = 0; i < 21; i++){		//finds the edge element desired, returns distance
		if (edgeArray[i].name == edgeName)
			return edgeArray[i].distance;
	}

}

double Map::getDanger(int node1, int node2){

	string edgeName = orderNumerically(&node1, &node2);	//sorts the nodes, returns edgeName

	for (int i = 0; i < 21; i++){		//finds the edge element desired, returns distance
		if (edgeArray[i].name == edgeName)
			return edgeArray[i].danger;
	}

}

double Map::getDanger(int node1, int node2, int pathNumber){

	string edgeName = orderNumerically(&node1, &node2, pathNumber);	//sorts the node numerically for the edgeName convention

	for (int i = 0; i < 21; i++){		//finds the edge element desired, returns distance
		if (edgeArray[i].name == edgeName)
			return edgeArray[i].danger;
	}

}

int Map::getToll(int node1, int node2){

	string edgeName = orderNumerically(&node1, &node2);	//sorts the nodes, returns edgeName

	for (int i = 0; i < 21; i++){		//finds the edge element desired, returns distance
		if (edgeArray[i].name == edgeName)
			return edgeArray[i].toll;
	}

}

int Map::getToll(int node1, int node2, int pathNumber){

	string edgeName = orderNumerically(&node1, &node2, pathNumber);	//sorts the node numerically for the edgeName convention

	for (int i = 0; i < 21; i++){		//finds the edge element desired, returns distance
		if (edgeArray[i].name == edgeName)
			return edgeArray[i].toll;
	}

}