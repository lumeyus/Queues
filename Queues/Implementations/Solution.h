/*
	Solution.h - Luis Ibanez - 3/6/2020
	-----------------------------------
	Contains helper functions used to simulate all the queues defined by 
	the problems assigned in homework 3. Also contains declaration of several 
	helper functions to assist with running the simulation.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <math.h>
#include <time.h>
#include "../Data Structures/DLL.h"

#define NUM_SIM_POINTS_P1 12
#define NUM_SIM_POINTS_P2 10
#define SIM_TIME 1e8
#define M 5

// used to generate random double value
double myrand();

// run the desired queueing simulation, problem 1
void RunProblemOne(int queue_type);

// run the desired queueing simulation, problem 2
void RunProblemTwo(int queue_type);

// gets desired output filename from user
std::string* GetFileName();