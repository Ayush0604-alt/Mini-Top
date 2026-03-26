#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>
#include <vector>

#include "cpu.h"
#include "memory.h"
#include "process.h"

using namespace std;

int main() {

    while (true) {
    cout << "\033[2J\033[H";

    vector<long long> stats1 = getCPUStats();
    this_thread::sleep_for(chrono::seconds(1));
    vector<long long> stats2 = getCPUStats();

    long long total1 = stats1[0] + stats1[1] + stats1[2] + stats1[3];
    long long total2 = stats2[0] + stats2[1] + stats2[2] + stats2[3];

    long long total_diff = total2 - total1;
    long long idle_diff = stats2[3] - stats1[3];

    double cpu = 0.0;
    if (total_diff != 0) {
        cpu = (double)(total_diff - idle_diff) / total_diff * 100;
    }

    double memory = getMemoryUsage();

    cout << fixed << setprecision(2);

    cout << "===== MonHealth System Monitor =====\n\n";
    cout << "CPU Usage:    " << cpu << "%\n";
    cout << "Memory Usage: " << memory << "%\n";

    printProcesses();  

    cout.flush();

    this_thread::sleep_for(chrono::milliseconds(500));  
}

    return 0;
}
