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

// returning a vector of values of a certain feature.
vector<float> TimeSeries::getValues(string featureName) const {

    vector<float> vec;
    int dataTableSize;

    dataTableSize = data.size();

    for(int i = 0; i < dataTableSize; i++) {
        //vec.push_back(TimeSeries::getVal(featureName, i));
        vec.push_back(getVal(featureName, i));
    }

    return vec;
}

// returning a specific value from a specific map.
float TimeSeries::getVal(string feature, int index) const {

    float val;
    map<string, float> tmpMap;

    tmpMap = data[index]; //selecting the relevant map from data table.
    return tmpMap[feature];

}

// inserting vector of values into the table according the index.
// example: insert vector {5, 46, 3.5, 120.0} into table.
void TimeSeries::insertValuesRow(vector<float> values) {
    index = 0;
    featuresAndValues fv;

    for(auto it = values.begin(); it != values.end(); it++) {
        fv.insert({columnFeature[index], *it});
        index++;
    }
    data.push_back(fv);
}

// return all the features names in a vector
vector<string> TimeSeries::returnFeaturesNames()  {
    vector<string> fNames;
    int size;

    size = columnFeature.size();

    for(int i = 0; i < size; i++ ) {
        fNames.push_back(columnFeature[i]);
    }
    return fNames;
}

// returns the vector of values of certain feature.
//    vector<map<string, float>> data;
// map<int, string> columnFeature
//vector<float> TimeSeries::getValuesOfFeatures(string feature) const{
//
//    vector<float> valuesVector;
//
//    for(auto iterator = data.begin(); iterator != data.end(); iterator++) {
//        valuesVector.push_back(iterator->at(feature));
//    }
//
//    return valuesVector;
//}

// given row- return vector
vector<float> TimeSeries::returnRow(int step) const {

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
//float TimeSeries::returnVal(int step, string feature) {
//    float val;
//    //vector<float> temp1 = returnRow(step);
//    vector<float> temp2 = getValuesOfFeatures(feature);
//
//    val = temp2.at(step -1);
//
//    return val;
//}

TimeSeries::~TimeSeries() {}