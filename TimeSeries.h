#include <map>
#include <vector>

#ifndef TIMESERIES_H_
#define TIMESERIES_H_

using namespace std;

typedef map<string, float> featuresAndValues;

class TimeSeries {

private:
    map<int, string> columnFeature;
    vector<map<string, float>> data;
    const char* fileName;
    string line, colName, token;
    int index;
    float val;

public:

    TimeSeries(const char* CSVfileName) {
        this->fileName = CSVfileName;
        saveData(fileName);
    }
    void saveData(const char* fileName);
    void insertValue(vector<float> values);
    vector<float> getValuesOfFeatures(string feature);
    vector<float> returnRow(int step);
    float returnVal(int step, string feature);


    ~TimeSeries();
};

#endif /* TIMESERIES_H_ */
