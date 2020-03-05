# Queue Simulations (ELE 408 - Embedded System Design Homework 3)
Implementing simulations for different queue types and evaluating their performance using C.

# Problem 1:
Implement the following queues:
1. Geo/Geo/1  : arrival is Bernoulli with mean 𝜆 and file size follows from geometric distribution with mean 1/𝜇
2. Geo/D/1    : arrival follows Bernoulli distribution with mean 𝜆, and file size is always equal to 1/𝜇
3. Geo/X/1    : arrival follows Bernoulli distribution with mean 𝜆, and the file size is equal to M with probability (1/𝜇 - 1)/(M - 1), and 1 otherwise (Take M = 5 for simulation)


and compare their mean delay performance under First-Come-First-Serve (FCFS) and Round-Robin (RR) policies.
Plot their mean delay against 𝜆 ∈ (0, 0.5) when service rate is 𝜇 = 0.5 (for both FCFS and RR policies).

# Problem 2:
Implement the following queues:
1. Geo/Geo/k/k  : arrival is Bernoulli with mean 𝜆 and file size follows from geometric distribution with mean 1/𝜇
2. Geo/D/k/k    : arrival follows Bernoulli distribution with mean 𝜆, and file size is always equal to 1/𝜇
3. Geo/X/k/k    : arrival follows Bernoulli distribution with mean 𝜆, and the file size is equal to M with probability (1/𝜇 - 1)/(M - 1), and 1 otherwise (Take M = 5 for simulation)

Plot the blocking probability against k when arrival rate 𝜆 = 0.8 and service rate 𝜇 = 0.4.
In all these queueing systems, there are k servers and at most k files in the systems.
