/* 
	Solution.cpp - Luis Ibanez - 3/6/2020
	-------------------------------------
	Implementation file for Solution.h helper function
*/

#include "Solution.h"

double Seed = 7;

// used to generate random double value
double myrand()
{
	double p;
	p = fmod(3125.0*Seed, 34359738337.0);
	Seed = p;
	p = p / 34359738337.0;
	return p;
}

// run desired queueing simulation, problem 1
void RunProblemOne(int queue_type)
{
	// get file information
	std::string* filename = GetFileName();

	std::ofstream ofile;
	ofile.open((*filename).c_str());

	double Seed = 7;	// set random seed

	std::cout << "Lambda \tAvgTaskDelay" << std::endl;
	ofile << "Lambda \t AvgTaskDelay" << std::endl;

	// initialize
	double Lambda[NUM_SIM_POINTS_P1] = { 0.1, 0.15, 0.2, 0.25, 0.3, 0.35, 0.4, 0.43, 0.45, 0.47, 0.48, 0.49 };
	double mu = 2;	// mean file size
	double AvgTaskDelay[NUM_SIM_POINTS_P1] = { 0, 0, 0, 0, 0, 0, 0, 0 };

	DLinkedList myQueue;

	int sz; // file size
	double xBernoulli;
	double TotalDelay;
	double TotalNumofCompletePkts = 0;	// total num of processed packets

	for (int i = 0; i < NUM_SIM_POINTS_P1; i++)	// num of arrival intensity
	{
		TotalDelay = 0;
		TotalNumofCompletePkts = 0;
		while (!myQueue.empty()) myQueue.removeFront();	// Keep queue empty

		for (long long t = 0; t < SIM_TIME; t++)	// start sim
		{
			// calls arrival routine
			if (myrand() < Lambda[i])
			{
				// get geometric file size 
				switch (queue_type)
				{
					case (geogeo1):
						sz = 0;
						do {
							xBernoulli = (myrand() < (1.0 / mu));
							sz++;
						} while (xBernoulli == 0);
						break;

					case (geoD1):
						sz = 2;	
						break;

					case (geoX1):
						if (myrand() < ((mu - 1) * 1.0 / (M - 1))) {
							sz = M;
						}
						else {
							sz = 1;
						}
						break;

					default:
						std::cout << "ERROR CHOOSING PROBLEM 1 QUEUE TYPE!" << std::endl;
						return;
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
	return;
}

// run desired queueing simulation, problem 2
void RunProblemTwo(int queue_type)
{
	// get file information
	std::string* filename = GetFileName();

	std::ofstream ofile;
	ofile.open((*filename).c_str());

	std::cout << "NumOfServers \tAvgDropRate" << std::endl;
	ofile << "NumOfServers \tAvgDropRate" << std::endl;

	// initialize
	int ServerStatus[10];
	int NewStatus[10];
	int busy;
	double TotalNumofSentPkts; // total number of packets issued
	double TotalNumofDropPkts; // total number of packets dropped
	int sz; // file size
	double xBernoulli;

	// define
	double NumofServers[NUM_SIM_POINTS_P2] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	double Lambda = 0.8;  // arrival rate
	double mu = 2;    // mean file size 
	double AvgDropRate[NUM_SIM_POINTS_P2] = { 0, 0, 0, 0, 0 };
	

	for (int i = 0; i < NUM_SIM_POINTS_P2; i++)	// num of arrival intensity
	{
		// init
		TotalNumofSentPkts = 0;
		TotalNumofDropPkts = 0;
		busy = 0;

		// initalize server statuses
		for (int k = 0; k < NumofServers[i]; k++) 
		{
			ServerStatus[k] = 0;
		}

		for (int t = 0; t < SIM_TIME; t++) 
		{
			// calls arrival routine
			if (myrand() < Lambda)
			{
				TotalNumofSentPkts++;
				busy = 1;
				for (int k = 0; k < NumofServers[i]; k++)
				{
					if (ServerStatus[k] == 0)
					{
						busy = 0;
						// geometric file size 
						switch (queue_type)
						{
							case (geogeokk):
								sz = 0;
								do {
									xBernoulli = (myrand() < (1.0 / mu));
									sz++;
								} while (xBernoulli == 0);
								break;
							case (geoDkk):
								sz = mu;
								break;
							case (geoXkk):
								if (myrand() < ((mu - 1)*1.0 / (M - 1)))
								{
									sz = M;
								}
								else
								{
									sz = 1;
								}
								break;
							default:
								std::cout << "ERROR CHOOSING PROBLEM 2 QUEUE TYPE!" << std::endl;
								return;
						}
						ServerStatus[k] = sz;
						break;
					}
				}
				if (busy == 1)
				{
					TotalNumofDropPkts++;
				}
			}

			// calls departure routine
			for (int k = 0; k < NumofServers[i]; k++)
			{
				if (ServerStatus[k] >= 1)
				{
					ServerStatus[k] = ServerStatus[k] - 1;
				}
			}
		}

		// collect data
		AvgDropRate[i] = TotalNumofDropPkts / TotalNumofSentPkts;
		std::cout << std::setw(12) << std::setprecision(10) << NumofServers[i] << '\t' << std::setw(12) << std::setprecision(10) << AvgDropRate[i] << std::endl;
		ofile << std::setw(12) << std::setprecision(10) << NumofServers[i] << '\t' << std::setw(12) << std::setprecision(10) << AvgDropRate[i] << std::endl;
	}
	return;
}

// gets output filename from user
std::string* GetFileName()
{
	std::string file_name;
	std::cout << "Enter the result file name: ";
	std::cin >> file_name;
	return new std::string(file_name);
}
