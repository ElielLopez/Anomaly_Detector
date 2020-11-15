#include <map>
#include <vector>

#ifndef TIMESERIES_H_
#define TIMESERIES_H_

using namespace std;

// gets "trainFile1.csv"
// time series need to hold a table.
// insert and return features names, add row, load from csv file etc.
using namespace std;

class TimeSeries {

private:
    const char* fileName;
    vector<pair<string,vector<double>>> result;
    string line, colName;
    double val;
// TODO make regular constructor and create another function to save the vector
public:
    TimeSeries(const char* CSVfileName) {
        this->fileName = CSVfileName;
        saveData(fileName);
    }
    void saveData(const char* fileName);

    //void insertFeatureAndValue();
    // return row
    // given feature- return vector of values

    ~TimeSeries();
};

#endif /* TIMESERIES_H_ */
