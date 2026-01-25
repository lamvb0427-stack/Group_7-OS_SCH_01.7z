#include <iostream>
#include <vector>
using namespace std;
struct Process {
    int pid;
    int arrival;
    int burst;
    int start;
    int completion;
    int waiting;
    int turnaround;
};
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
int main() {
    vector<Process> p;
    Process p1 = {1, 0, 5, 0, 0, 0, 0};
    Process p2 = {2, 1, 3, 0, 0, 0, 0};
    Process p3 = {3, 2, 8, 0, 0, 0, 0};
    p.push_back(p1);
    p.push_back(p2);
    p.push_back(p3);
    SJF(p);
    cout << "PID\tAT\tBT\tST\tCT\tWT\tTAT\n";
    for (int i = 0; i < p.size(); i++) {
        cout << p[i].pid << "\t"
             << p[i].arrival << "\t"
             << p[i].burst << "\t"
             << p[i].start << "\t"
             << p[i].completion << "\t"
             << p[i].waiting << "\t"
             << p[i].turnaround << endl;
    }
    return 0;
}
