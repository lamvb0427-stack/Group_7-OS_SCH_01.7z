#include <iostream>
#include <vector>
#include "process.h"
using namespace std;
void fcfsScheduling(vector<Process>&);
int main() {
    vector<Process> processes = {
        {1, 0, 5},
        {2, 1, 3},
        {3, 2, 8},
        {4, 3, 6}
    };
    fcfsScheduling(processes);
    cout << "PID\tAT\tBT\tST\tCT\tWT\tTAT\n";
    for (auto p : processes) {
        cout << p.pid << "\t"
             << p.arrivalTime << "\t"
             << p.burstTime << "\t"
             << p.startTime << "\t"
             << p.completionTime << "\t"
             << p.waitingTime << "\t"
             << p.turnaroundTime << endl;
    }
    return 0;
}
