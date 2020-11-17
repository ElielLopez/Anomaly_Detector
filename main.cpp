

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
    vector<string> namesOfFeatures;
    float testVal1;
    float testVal2;
    float testVal3;
    float testVal4;
    float testVal5;

    vector<float> v = {5, 46, 3.5, 120.0};
    TimeSeries ts("csvfile.txt");
    ts.insertValuesRow(v);
    testGetValOfFeatures1 = ts.getValues("this");
    testGetValOfFeatures2 = ts.getValues("is");
    testGetValOfFeatures3 = ts.getValues("a");
    testGetValOfFeatures4 = ts.getValues("test");
    testGetRow = ts.returnRow(3); // TODO - fix ,row not in order
    testVal1 = ts.getVal("a", 0);
    testVal2 = ts.getVal("a", 1);
    testVal3 = ts.getVal("a", 2);
    testVal4 = ts.getVal("a", 3);
    testVal5 = ts.getVal("a", 4);
    namesOfFeatures = ts.returnFeaturesNames();

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