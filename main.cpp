#include <iostream>
#include <vector>
#include <iomanip>
#include "process.h"
#include <algorithm>
using namespace std;
void fcfsScheduling(vector<Process>&);
void sjfScheduling(vector<Process>&);
void printTable(const vector<Process>& p) {
    cout << left << setw(10) << "PID" 
         << setw(10) << "Arrival" 
         << setw(10) << "Burst" 
         << setw(10) << "Start" 
         << setw(10) << "Finish" 
         << setw(10) << "Wait" 
         << setw(10) << "TurnAround" << endl;
    for (const auto& x : p) {
        cout << left << setw(10) << x.pid
             << setw(10) << x.arrivalTime
             << setw(10) << x.burstTime
             << setw(10) << x.startTime
             << setw(10) << x.completionTime
             << setw(10) << x.waitingTime
             << setw(10) << x.turnaroundTime << endl;
    }
}
void printGantt(const vector<Process>& p) {
    vector<Process> temp = p;
    sort(temp.begin(), temp.end(), [](Process a, Process b) {
        return a.startTime < b.startTime;
    });
    cout << "\n[ Gantt Chart ]\n";
    cout << " ";
    for (const auto& x : temp) {
        cout << "---" << x.pid << "----";
    }
    cout << "\n|";
    for (const auto& x : temp) {
        cout << "   " << x.pid << "   |";
    }
    cout << "\n ";
    for (const auto& x : temp) {
        cout << "--------";
    }
    cout << "\n";
    cout << temp[0].startTime;
    for (const auto& x : temp) {
        cout << setw(9) << x.completionTime;
    }
    cout << endl;
}
double avgWaiting(const vector<Process>& p) {
    double sum = 0;
    for (const auto& x : p) sum += x.waitingTime;
    return sum / p.size();
}
int main() {
    int n;
    cout << "Nhap so luong tien trinh: ";
    cin >> n;
    vector<Process> data(n);
    for (int i = 0; i < n; i++) {
        cout << "Nhap PID, Arrival Time, Burst Time cho tien trinh " << i + 1 << ": ";
        cin >> data[i].pid >> data[i].arrivalTime >> data[i].burstTime;
    }
    vector<Process> fcfsData = data;
    vector<Process> sjfData = data;
    fcfsScheduling(fcfsData);
    cout << "\n================= FCFS ALGORITHM =================\n";
    printTable(fcfsData);
    printGantt(fcfsData);
    cout << "\nAverage Waiting Time: " << avgWaiting(fcfsData) << endl;
    sjfScheduling(sjfData);
    cout << "\n\n================= SJF ALGORITHM (Non-Preemptive) =================\n";
    printTable(sjfData);
    printGantt(sjfData);
    cout << "\nAverage Waiting Time: " << avgWaiting(sjfData) << endl;
    return 0;
}
