#include "process.h"
#include <dirent.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

bool isNumber(string s) {
    for (char c : s) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

void printProcesses() {
    DIR *dir;
    struct dirent *entry;

    dir = opendir("/proc");

    if (dir == NULL) {
        cout << "Error opening /proc" << endl;
        return;
    }

    cout << "\nPID\tNAME" << endl;

    while ((entry = readdir(dir)) != NULL) {
        string pid = entry->d_name;

        if (isNumber(pid)) {
            string path = "/proc/" + pid + "/comm";

            ifstream file(path);

            if (file) {
                string name;
                getline(file, name);
                cout << pid << "\t" << name << endl;
            }
        }
    }

    closedir(dir);
}
