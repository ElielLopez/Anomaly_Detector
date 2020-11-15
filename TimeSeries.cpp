#include "TimeSeries.h"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

void TimeSeries::saveData(const char *fileName) {

    ifstream fileTest(fileName);

    if (!fileTest.is_open()) {
        cout <<"NOT OPENED"<<endl;
    }
    if (fileTest.is_open()) {
        // first row- features
        getline(fileTest, line);
        stringstream ss(line);

        // every feature is saved in the vector
        while(getline(ss, colName, ',')) {
            result.push_back({colName, vector<double>{}});
        }

    }
    // the rest of the values are stored in the correct column
    while(getline(fileTest, line)) {
        stringstream ss(line);
        int index = 0;
        while(ss >> val) {

            result.at(index).second.push_back(val);
            if(ss.peek() == ',') ss.ignore();
            if(ss.peek() == '\n') ss.ignore();
            index++;
        }
    }
    fileTest.close();
}


TimeSeries::~TimeSeries() {

}