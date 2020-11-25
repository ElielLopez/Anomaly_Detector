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
    void saveData(const char* fileName);

    vector<float> getValues(string featureName) const;
    //float getVal(string feature, int index) const;
    void insertValuesRow(vector<float> values);
    vector<string> returnFeaturesNames() ;
    // TODO create insertFeatureNameIntoData - to insert feature name

    // TODO- not sure what for and also need to made in order
    vector<float> returnRow(int step) const;

    ~TimeSeries();
};

#endif /* TIMESERIES_H_ */