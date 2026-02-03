#include "process.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool compareArrival(const Process& a, const Process& b) {
    return a.arrivalTime < b.arrivalTime;
}
void fcfsScheduling(vector<Process>& p) {
    sort(p.begin(), p.end(), compareArrival);
    int currentTime = 0;
    for (int i = 0; i < p.size(); i++) {
        if (currentTime < p[i].arrivalTime) {
            currentTime = p[i].arrivalTime;
        }
        p[i].startTime = currentTime;
        p[i].completionTime = p[i].startTime + p[i].burstTime;
        p[i].turnaroundTime = p[i].completionTime - p[i].arrivalTime;
        p[i].waitingTime = p[i].startTime - p[i].arrivalTime;
        currentTime = p[i].completionTime;
    }
}