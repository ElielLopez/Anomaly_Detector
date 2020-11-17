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
    void saveData(const char* fileName); // Dont change!!

    vector<float> getValues(string featureName);
    float getVal(string feature, int index);

    void insertValuesRow(vector<float> values); // Dont change!!
    vector<string> returnFeaturesNames();
    // TODO create insertFeatureNameIntoData - to insert feature name

    vector<float> returnRow(int step);

//    vector<float> getValuesOfFeatures(string feature) const;
//    float returnVal(int step, string feature);


    ~TimeSeries();
};

#endif /* TIMESERIES_H_ */
