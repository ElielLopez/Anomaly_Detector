

#include <iostream>
#include <vector>
#include "AnomalyDetector.h"
#include "TimeSeries.h"
#include "TimeSeries.cpp"
#include "SimpleAnomalyDetector.h"
#include "SimpleAnomalyDetector.cpp"
#include <fstream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <math.h>

using namespace std;

int main(){

    vector<float> testGetValOfFeatures1;
    vector<float> testGetValOfFeatures2;
    vector<float> testGetValOfFeatures3;
    vector<float> testGetValOfFeatures4;
    vector<float> testGetRow;
    float testVal;

    vector<float> v = {5, 46, 3.5, 120.0};
    TimeSeries ts("csvfile.txt");
    ts.insertValue(v);
    testGetValOfFeatures1 = ts.getValuesOfFeatures("this");
    testGetValOfFeatures2 = ts.getValuesOfFeatures("is");
    testGetValOfFeatures3 = ts.getValuesOfFeatures("a");
    testGetValOfFeatures4 = ts.getValuesOfFeatures("test");
    testGetRow = ts.returnRow(3);
    testVal = ts.returnVal(2,"a");

    SimpleAnomalyDetector ad;
    ad.learnNormal(ts);
    vector<correlatedFeatures> cf=ad.getNormalModel();


//    ifstream testFile("csvfile.txt");
//    for(string line; getline(testFile, line);) {
//        cout << line<< endl;
//    }

    cout<<"done"<<endl;
    return 0;
}