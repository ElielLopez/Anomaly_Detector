#include <map>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>


#ifndef TIMESERIES_H_
#define TIMESERIES_H_

using namespace std;

typedef map<string, float> featuresAndValues;

class TimeSeries {

private:
    const char* fileName;
    string line, colName, token;
    int index;
    float val;

public:

    map<int, string> columnFeature;
    vector<map<string, float>> data;

    TimeSeries(const char* CSVfileName) {
        this->fileName = CSVfileName;
        saveData(fileName);
    }

    // saves the data from the csv file.
    void saveData(const char* fileName);

    // return a vector of values of a certain feature.
    vector<float> getValues(string featureName) const;

    // insert row of values into the data table.
    void insertValuesRow(vector<float> values);

    // return the features names from the csv file.
    vector<string> returnFeaturesNames() ;

    // returns a row of values given a step. this function is not in use in this particular run.
    vector<float> returnRow(int step) const;

    ~TimeSeries();
};

#endif /* TIMESERIES_H_ */
