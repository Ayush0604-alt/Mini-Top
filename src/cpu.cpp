#include "cpu.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

vector<long long> getCPUStats() {
    ifstream file("/proc/stat");

    if (!file) {
        cout << "Error opening /proc/stat" << endl;
        return {};
    }

    string line;
    getline(file, line);

    stringstream s(line);

    string label;
    long long user, nice, system, idle;

    s >> label >> user >> nice >> system >> idle;

    file.close();

    return {user, nice, system, idle};
}
