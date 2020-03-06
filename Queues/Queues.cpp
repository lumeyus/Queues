/*
	Queues.cpp - Luis Ibanez - 3/6/2020
	-----------------------------------
	This file contains the 'main' function where program execution begins and ends.
	Grabs output file name from user input and performs the queueing simulation.

*/
#include "Implementations/Solution.h"

int main()
{
	// problem 1
	//int p1_queue = geogeo1;
	//RunProblemOne(p1_queue);
	//p1_queue = geoD1;
	//RunProblemOne(p1_queue);
	//p1_queue = geoX1;
	//RunProblemOne(p1_queue);

	// problem 2
	int p2_queue = geogeokk;
	RunProblemTwo(p2_queue);
	p2_queue = geoDkk;
	RunProblemTwo(p2_queue);
	p2_queue = geoXkk;
	RunProblemTwo(p2_queue);
	return 0;
}

