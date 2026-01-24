#include "process.h"
#include <vector>
#include <algorithm>
using namespace std;
void SJF(vector<Process>& p) {
    int time = 0, completed = 0;
    int n = p.size();
    vector<bool> done(n, false);
    while (completed < n) {
        int idx = -1;
        int minBurst = 1e9;
        for (int i = 0; i < n; i++) {
            if (!done[i] && p[i].arrival <= time && p[i].burst < minBurst) {
                minBurst = p[i].burst;
                idx = i;
            }
        }
        if (idx == -1) {
            time++;
            continue;
        }
        p[idx].start = time;
        time += p[idx].burst;
        p[idx].completion = time;
        p[idx].turnaround = p[idx].completion - p[idx].arrival;
        p[idx].waiting = p[idx].turnaround - p[idx].burst;
        done[idx] = true;
        completed++;
    }
}
