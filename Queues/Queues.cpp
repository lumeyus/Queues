// Queues.c : This file contains the 'main' function where program execution begins and ends.

#include <iostream>
#include <fstream>
#include <time.h>
#include "Implementations/geogeo1.h"

#define NUM_SIM_POINTS 12
#define SIM_TIME 1e8
#define M 5

int main()
{
	// get file information
	std::string filename;
	std::cout << "Enter the result file name: ";
	std::cin >> filename;

	std::ofstream ofile;
	ofile.open(filename.c_str());

	double Seed = 7;	// set random seed

	std::cout << "Lambda \tAvgTaskDelay" << std::endl;
	ofile << "Lambda \t AvgTaskDelay" << std::endl;

	// Initialize containers and file size
	double Lambda[NUM_SIM_POINTS] = { 0.1, 0.15, 0.2, 0.25, 0.3, 0.35, 0.4, 0.43, 0.45, 0.47, 0.48, 0.49 };
	double mu = 2;	// mean file size
	double AvgTaskDelay[NUM_SIM_POINTS] = { 0, 0, 0, 0, 0, 0, 0, 0 };

	DLinkedList myQueue;

	int sz; // file size
	double xBernoulli;
	double TotalDelay;
	double TotalNumofCompletePkts = 0;	// total num of processed packets

	for (int i = 0; i < NUM_SIM_POINTS; i++)	// num of arrival intensity
	{
		TotalDelay = 0;
		TotalNumofCompletePkts = 0;
		while (!myQueue.empty()) myQueue.removeFront();	// Keep queue empty

		for (long long t = 0; t < SIM_TIME; t++)	// start sim
		{
			// calls arrival routine
			if (myrand() < Lambda[i])
			{
				// geometric file size 
				// This is geo geo 1
				/*s = 0;
				do {
					xBernoulli = (myrand() < (1.0 / mu));
					s = s + 1;
				} while (xBernoulli == 0);*/
				// This is geo D 1
				//s = 2;	
				// This is geo X 1
				if (myrand() < ((mu - 1) * 1.0 / (M - 1)))
				{
					sz = M;
				}
				else
				{
					sz = 1;
				}
				myQueue.addBack(t, sz);	// insert file into queue
			}

			// calls departure routine
			if (!myQueue.empty())
			{
				if (myQueue.header->next->fSize > 1)
				{
					myQueue.header->next->fSize = myQueue.header->next->fSize - 1;
				}
				else
				{
					TotalDelay = TotalDelay + t - myQueue.header->next->aTime;
					TotalNumofCompletePkts++;
					myQueue.removeFront();
				}
			}
		}

		// collect data
		AvgTaskDelay[i] = TotalDelay / TotalNumofCompletePkts;
		std::cout << std::setw(12) << std::setprecision(10) << Lambda[i] << '\t' << std::setw(12) << std::setprecision(10) << AvgTaskDelay[i] << std::endl;
		ofile << std::setw(12) << std::setprecision(10) << Lambda[i] << '\t' << std::setw(12) << std::setprecision(10) << AvgTaskDelay[i] << std::endl;
	}
	return 0;
}

