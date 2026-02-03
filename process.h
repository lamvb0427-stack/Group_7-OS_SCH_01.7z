#ifndef PROCESS_H
#define PROCESS_H
#include <string>
#include <iostream>
using namespace std;
struct Process {
    string pid;
    int arrivalTime;
    int burstTime;
    int startTime = 0;
    int completionTime = 0;
    int waitingTime = 0;
    int turnaroundTime = 0;
};
#endif
