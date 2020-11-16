#include <map>
#include <vector>

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
    void insertValue(vector<float> values);
    vector<float> getValuesOfFeatures(string feature) const;
    vector<float> returnRow(int step);
    float returnVal(int step, string feature);


    ~TimeSeries();
};

#endif /* TIMESERIES_H_ */
