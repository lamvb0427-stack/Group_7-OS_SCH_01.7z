#include <iostream>
#include <vector>
#include <algorithm>
#include "process.h"
using namespace std;
bool compareArrival(const Process& a, const Process& b) {
    return a.arrivalTime < b.arrivalTime;}
void fcfsScheduling(vector<Process>& p) {
    sort(p.begin(), p.end(), [](Process a, Process b) {
        return a.arrivalTime < b.arrivalTime;
    });
    int currentTime = 0;
    for (int i = 0; i < p.size(); i++) {
         if (currentTime < p[i].arrivalTime) {
            currentTime = p[i].arrivalTime;
        }
        p[i].startTime = max(currentTime, p[i].arrivalTime);
        p[i].completionTime = p[i].startTime + p[i].burstTime;
        p[i].waitingTime = p[i].startTime - p[i].arrivalTime;
        p[i].turnaroundTime = p[i].completionTime - p[i].arrivalTime;
        currentTime = p[i].completionTime;
    }
}
