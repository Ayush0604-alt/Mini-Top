#include "memory.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

double getMemoryUsage() {
    ifstream file("/proc/meminfo");

    if (!file) {
        cout << "Error opening /proc/meminfo" << endl;
        return 0.0;
    }

    string line;
    long long total = 0, available = 0;

    while (getline(file, line)) {
        string key;
        long long value;
        string unit;

        stringstream s(line);
        s >> key >> value >> unit;

        if (key == "MemTotal:") {
            total = value;
        }
        else if (key == "MemAvailable:") {
            available = value;
        }

      
        if (total && available) break;
    }

    file.close();

    long long used = total - available;

    double usage = (double)used / total * 100;

    return usage;
}
