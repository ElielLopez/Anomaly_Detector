

#include <iostream>
#include <vector>
#include "AnomalyDetector.h"
#include "TimeSeries.h"
#include "TimeSeries.cpp"
#include "SimpleAnomalyDetector.h"
#include <fstream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <math.h>

using namespace std;

int main(){

    TimeSeries ts("csvfile.txt");
//    ifstream testFile("csvfile.txt");
//    for(string line; getline(testFile, line);) {
//        cout << line<< endl;
//    }

    cout<<"done"<<endl;
    return 0;
}