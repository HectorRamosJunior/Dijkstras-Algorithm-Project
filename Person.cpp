//Person.cpp
//Person cpp file, stores traveled information and makes path decisions

#include <iostream>
#include <vector>
#include "Map.h"
#include "Person.h"

using namespace std;

Person::Person(int start, int end){

	for (int i = 0; i < 15; i++){	//sets every array element to their default values
		distanceArray[i] = 10000;	//sets every node in distance array to 'inf'
		safetyArray[i] = 0;			//sets every node in safety array to 'min'
		tollArray[i] = 10000;		//sets every node in toll array to 'inf'
		previousNode[i] = 0;	//for keeping track of the nodes
		finishedSet[i] = false;		//sets every node of finishedSet array to false, for keeping track
	}

	distanceArray[start - 1] = 0;	//sets start node in array to 0
	safetyArray[start - 1] = 1;
	tollArray[start - 1] = 0;

	startNode = start; //sets the startNode for the class object
	endNode = end; //sets the endNode
	Map map;	//instantiates the map object for the Person object
}


//This function is intended to be run after Dijkstra's algorithm is run, prints the path taken
void Person::printPath(){ 
	
	bool stop = false; //sets the terminating condition for the while loop
	int currentNode = endNode;	//starts the recusive function from the end node

	cout << endl << "Going from the end location to the start location, the least path is: " << endl;
	cout << currentNode << " -> ";


	//For loop prints the elements of the prevNodeArray
	while (stop == false) // start node is hit, make the loop stop
	{

		if ((previousNode[currentNode - 1]) == startNode) //once the beginning location is hit, stop
		{
			cout << previousNode[currentNode - 1] << endl;
			stop = true; //terminates while loop
		}
		else
		{
			cout << previousNode[currentNode - 1] << " -> "; //print node
			currentNode = previousNode[currentNode - 1];	//reset the node for the recursion
		}

	}
}


int Person::leastDistance(){	//runs Dijkstra's algorithm for distance, returns the total distance 

	int currentNode;
	bool finishedSetFull = false;	//sets the condition for the while loop below

	while (finishedSetFull != true)
	{
		int min = 9999999999999;	//sets the 'min' value for the for loop below

		//The for loop below finds the 'min path' node currently
		//Out of the nodes not in the finishedSet array		
		for (int i = 0; i < 15; i++){
			if ( (finishedSet[i] == false) && (distanceArray[i] <= min)){
				min = distanceArray[i];
				currentNode = i + 1;
			}
		}

		finishedSet[currentNode - 1] = true; //Sets currentNode in the Finished Set array

		//Obtain the pathArray from the map object's class for the algorithm below
		int *pathArray = map.getPath(currentNode);

		//The foor loop runs through the path array obtained, and searches for any possible edges from the currentNode
		for (int i = 0; i < 15; i++)
		{

			//Checks if the currentNode connects to another node, and if it's in the finishedSet
			if (pathArray[i] == 1 && finishedSet[i] == false)
			{
				//Stores the distance value between the two nodes of interest
				int distance = map.getDistance(currentNode, (i + 1));

				//If the distance's path is smaller than the distanceArray element's value, replace the element's value
				//And set the previousNode to the current node for that specific element
				if ((distanceArray[currentNode - 1] + distance) < distanceArray[i])
				{
					distanceArray[i] = distanceArray[currentNode - 1] + distance;
					previousNode[i] = currentNode;
				}
			}

			else if (pathArray[i] == 2 && finishedSet[i] == false)
			{
				//Since there's two edges between the nodes of interest, store the distances of both
				int distance1 = map.getDistance(currentNode, (i + 1), 1);
				int distance2 = map.getDistance(currentNode, (i + 1), 2);


				//Run two if statements similar to the case above, but for both edges in the special case.
				if ((distanceArray[currentNode - 1] + distance1) < distanceArray[i])
				{
					distanceArray[i] = distanceArray[currentNode - 1] + distance1;
					previousNode[i] = currentNode;
				}
				if ((distanceArray[currentNode - 1] + distance2) < distanceArray[i])
				{
					distanceArray[i] = distanceArray[currentNode - 1] + distance2;
					previousNode[i] = currentNode;
				}

			}

		}
		
		finishedSetFull = true;

		for (int i = 0; i < 15; i++)
		{
			if (finishedSet[i] == false)
				finishedSetFull = false;
		}
	}
	
	return distanceArray[endNode - 1];
}

int Person::leastToll(){	//runs Dijkstra's algorithm for tolls, returns the total cost

	int currentNode; 
	bool finishedSetFull = false; //sets the condition for the while loop below

	while (finishedSetFull != true)
	{
		int min = 9999999999999; //sets the 'min' value for the for loop below

		//The for loop below finds the 'min path' node currently
		//Out of the nodes not in the finishedSet array
		for (int i = 0; i < 15; i++){
			if ((finishedSet[i] == false) && (tollArray[i] <= min)){
				min = tollArray[i];
				currentNode = i + 1;
			}
		}

		//Once the 'min' node is decided, move the node to the 'finished' set array
		finishedSet[currentNode - 1] = true; 

		//Obtain the pathArray from the map object's class for the algorithm below
		int *pathArray = map.getPath(currentNode);

		//The for loop runs through the path array obtained, and searches for any possible edges from the currentNode
		for (int i = 0; i < 15; i++)
		{

			//Checks if the currentNode connects to another node, and if it's in the finishedSet
			if (pathArray[i] == 1 && finishedSet[i] == false)
			{
				int toll = map.getToll(currentNode, (i + 1)); //gets the toll of the edge connecting the two Nodes

				//If the toll's path is smaller than the tollArray element's value, replace the element's value
				//And set the previousNode to the current node for that specific element
				if ((tollArray[currentNode - 1] + toll) < tollArray[i])
				{
					tollArray[i] = tollArray[currentNode - 1] + toll;
					previousNode[i] = currentNode;
				}
			}

			//Same if statement as above, but runs for the special case that two nodes share more than one edge
			else if (pathArray[i] == 2 && finishedSet[i] == false)
			{

				//Since there's two edges between the nodes of interest, store the toll costs of both
				int toll1 = map.getToll(currentNode, (i + 1), 1);
				int toll2 = map.getToll(currentNode, (i + 1), 2);

				//Run two if statements similar to the case above, but for both edges in the special case.
				if ((tollArray[currentNode - 1] + toll1) < tollArray[i])
				{
					tollArray[i] = tollArray[currentNode - 1] + toll1;
					previousNode[i] = currentNode;
				}

				if ((tollArray[currentNode - 1] + toll2) < tollArray[i])
				{
					tollArray[i] = tollArray[currentNode - 1] + toll2;
					previousNode[i] = currentNode;
				}
			}
		}

		//Sets the terminating while loop condition to true,
		//So that if the if condition below doesn't correct it, the algorithm ends
		finishedSetFull = true;

		//Checks the entire finishedSet array for a false value
		//If it finds one, sets the condition for the while loop to false, so that it keeps running
		for (int i = 0; i < 15; i++)
		{
			if (finishedSet[i] == false)
				finishedSetFull = false;
		}
	}

	//Function returns the endNode's total safety value after the algorithm runs
	return tollArray[endNode - 1];
}

double Person::leastDanger(){	//runs Dijkstra's algorithm for danger, returns the total safety

	int currentNode;
	bool finishedSetFull = false;


	while (finishedSetFull != true)
	{
		int max = -1; //sets the 'max' value for the for loop below

		//The for loop below finds the 'min path' node currently
		//Out of the nodes not in the finishedSet array
		for (int i = 0; i < 15; i++){
			if ((finishedSet[i] == false) && (safetyArray[i] >= max)){
				max = safetyArray[i];
				currentNode = i + 1;
			}
		}

		finishedSet[currentNode - 1] = true; //Sets currentNode in the Finished Set array

		//obtain the pathArray from the map object's class for the algorithm below
		int *pathArray = map.getPath(currentNode);

		//The foor loop runs almost identical to leastdistance and leastToll
		//Except for the case where the 'danger' is 0, the math must be done differently
		for (int i = 0; i < 15; i++)
		{
			//Both the for loops below run almost identical to the previous functions, except that
			//In the case of the currentNode's 'safety' value being 0, the safety of the edge
			//Is added instead of multiplied, which is typical of probability
			if (pathArray[i] == 1 && finishedSet[i] == false)
			{

				double safety = (1 - map.getDanger(currentNode, (i + 1))); //Inverting the probability of the danger to the 'safety' of the road
				if (safetyArray[currentNode - 1] != 0) 
				{
					safety = safety * safetyArray[currentNode - 1];
				}

				if ( safety > safetyArray[i])
				{
					safetyArray[i] = safety;
					previousNode[i] = currentNode;
				}
			}


			else if (pathArray[i] == 2 && finishedSet[i] == false)
			{
				//inverts the danger of the edges of interest to the 'safety' of the roads
				double safety1 = (1 - map.getDanger(currentNode, (i + 1), 1));
				double safety2 = (1 - map.getDanger(currentNode, (i + 1), 2));

				
				if (safetyArray[currentNode - 1] != 0) {
					safety1 = safety1 * safetyArray[currentNode - 1];
					safety2 = safety2 * safetyArray[currentNode - 1];
				}

				if (safety1 > safetyArray[i])
				{
					safetyArray[i] = safety1;
					previousNode[i] = currentNode;
				}

				if (safety2 > safetyArray[i])
				{
					safetyArray[i] = safety2;
					previousNode[i] = currentNode;
				}
			}
		}


		//Sets the terminating while loop condition to true,
		//So that if the if condition below doesn't correct it, the algorithm ends
		finishedSetFull = true;
		
		//Checks the entire finishedSet array for a false value
		//If it finds one, sets the condition for the while loop to false, so that it keeps running
		for (int i = 0; i < 15; i++)
		{
			if (finishedSet[i] == false)
				finishedSetFull = false;
		}
	}

	//Function returns the endNode's total safety value after the algorithm runs
	return safetyArray[endNode - 1];
}