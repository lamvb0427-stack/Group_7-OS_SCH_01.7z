#include <vector>
#include "process.h"
#include <iostream>
#include <limits> 
using namespace std;
void SJF(vector<Process>& p) {
    int n = p.size();
    int currentTime = 0, completed = 0;
    vector<bool> isCompleted(n, false);
    while (completed < n) {
        int idx = -1;
        int minBurst = numeric_limits<int>::max();
        for (int i = 0; i < n; i++) {
           if (!isCompleted[i] && p[i].arrivalTime <= currentTime) {
                if (p[i].burstTime < minBurst) {
                    minBurst = p[i].burstTime;
                    idx = i;
                }
                else if (p[i].burstTime == minBurst) {
                    if (p[i].arrivalTime < p[idx].arrivalTime) {
                        idx = i;
                    }
                }
            }
        }
       if (idx != -1) {
          p[idx].startTime = currentTime;
            p[idx].completionTime = p[idx].startTime + p[idx].burstTime;
            p[idx].turnaroundTime = p[idx].completionTime - p[idx].arrivalTime;
            p[idx].waitingTime = p[idx].turnaroundTime - p[idx].burstTime;
       isCompleted[idx] = true;
            completed++;
            currentTime = p[idx].completionTime;
        } else {
            currentTime++;
        }
    }
}
