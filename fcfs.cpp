#include "process.h"
#include <vector>
using namespace std;
void FCFS(vector<Process>& p) {
    int time = 0;
    for (int i = 0; i < p.size(); i++) {
        if (time < p[i].arrival)
            time = p[i].arrival;
        p[i].start = time;
        time += p[i].burst;
        p[i].completion = time;
        p[i].turnaround = p[i].completion - p[i].arrival;
        p[i].waiting = p[i].turnaround - p[i].burst;
    }
}
