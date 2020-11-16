#include "TimeSeries.h"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

void TimeSeries::saveData(const char *fileName) {

    index = 0;
    ifstream myFile(fileName);

    if(myFile.is_open()) {
        // get the first row- the features names
        getline(myFile, line);
        stringstream ss(line);

        // save the features in a map- for every index there is a permanent feature.
        // for example: index 0 will be A and every time i will look for A
        // i will look into a map with key 0
        while(getline(ss, colName, ',')) {
            columnFeature.insert({index, colName}); // {0, A}
            index++;
        }
    }

    /*
     * for the rest of the file:
     * for every value we convert it into a float and extracting the feature name
     * and inserting into the map the feature name and value
     * after i get the pairs i will insert them into the vector "data"
     * */
    while(getline(myFile, line)) {
        stringstream ss(line);
        featuresAndValues fv;
        index = 0;

        while(getline(ss, token, ',')) { // "1"
            val = stof(token);
            colName = columnFeature[index]; // colName = "A"
            fv.insert({colName, val}); // {A, 1}...{D, 426.5}
            if(ss.peek() == ',') ss.ignore();
            if(ss.peek() == '\n') ss.ignore();
            index++;
        }
        data.push_back(fv); // data: { {A, 1}...{D, 426.5}, .....,{} }
    }
    myFile.close();
}

// inserting vector of values into the table acorrding the index.
// example: insert vector {5, 46, 3.5, 120.0} into table.
void TimeSeries::insertValue(vector<float> values) {
    index = 0;
    featuresAndValues fv;

    for(auto it = values.begin(); it != values.end(); it++) {
        fv.insert({columnFeature[index], *it});
        index++;
    }
    data.push_back(fv);
}

// returns the vector of values of certain feature.
//    vector<map<string, float>> data;
// map<int, string> columnFeature
vector<float> TimeSeries::getValuesOfFeatures(string feature) {
// ({this, 1, 2, 3, 4, 5})
    vector<float> valuesVector;
    int tempIndex = 0;
    float valToInsert;

    for(auto it = columnFeature.begin(); it != columnFeature.end(); it++) {
        if(it->second == feature) {
            tempIndex = it->first;
        }
    }
// data[0] = [0]:a-1.5,[1]:is-36,[3]:test- 426.5, [4]:this-1

    for(auto iterator = data.begin(); iterator != data.end(); iterator++) {
        valuesVector.push_back(iterator->at(feature));
    }

    return valuesVector;
}

// given row- return vector
vector<float> TimeSeries::returnRow(int step) {

    vector<float> row;
   // starting from the row on the table (minus 1 because of features row)
   // inserting the values into the vector
    auto it1 = data.at(step - 1);
    for (auto it2 = it1.begin(); it2 != it1.end(); it2++) {
        row.push_back(it2->second);
    }
    return row;
}

// given row and feature- return the value
float TimeSeries::returnVal(int step, string feature) {
    float val;
    //vector<float> temp1 = returnRow(step);
    vector<float> temp2 = getValuesOfFeatures(feature);

    val = temp2.at(step -1);

    return val;
}

TimeSeries::~TimeSeries() {}