//Main.cpp
#include "Map.h"
#include "Person.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {

	Person person1(12, 2), person2(11, 5);  //Two Distance Problems
	Person person3(2, 11);				    //Toll problem
	Person person4(12, 2);					//Danger Problem
	Person person5(5, 9);					//Traveling Salesman Problem

	double result;

	result = person1.leastDistance();
	person1.printPath();	//Print Distance Path
	cout << "The shortest distance between node " << person1.startNode
		<< " and " << person1.endNode << " is " << result << " miles." << endl << endl;
	
	result = person2.leastDistance();
	person2.printPath();	//Print Distance Path
	cout << "The shortest distance between node " << person2.startNode
		<< " and " << person2.endNode << " is " << result << " miles." << endl << endl;
	

	result = person3.leastToll();
	person3.printPath();	//Print Cheapest Path
	cout << "The cheapest path between node " << person3.startNode
		<< " and " << person3.endNode << " costs " << result << " dollars." << endl << endl;

	result = person4.leastDanger();
	person4.printPath();	// Print Safety Path
	cout << "The safest path between node " << person4.startNode
		<< " and " << person4.endNode << " has a " << result*100 << "% chance of avoiding an exam." << endl << endl;


	cin.get();
	return 0;
}
