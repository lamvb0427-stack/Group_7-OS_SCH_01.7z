#ifndef PROCESS_H
#define PROCESS_H
struct Process {
    int pid;
    int arrivalTime;
    int burstTime;
    int startTime;
    int completionTime;
    int waitingTime;
    int turnaroundTime;
};
#endif
