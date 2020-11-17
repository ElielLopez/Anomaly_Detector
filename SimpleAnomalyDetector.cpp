
#include "SimpleAnomalyDetector.h"
#include "TimeSeries.h"
#include "anomaly_detection_util.h"
#include "anomaly_detection_util.cpp"

SimpleAnomalyDetector::SimpleAnomalyDetector() {
	// TODO Auto-generated constructor stub

}

SimpleAnomalyDetector::~SimpleAnomalyDetector() {
	// TODO Auto-generated destructor stub
}


void SimpleAnomalyDetector::learnNormal(const TimeSeries& ts){

    vector<float> tmp1, tmp2;
    int size = ts.columnFeature.size();
    string col1, col2;
    float pearsonCoefficient, maxPearsonCo;

    //TimeSeries::getVal(col1,size);

    for (int i = 0; i < size; i++) {
        maxPearsonCo = 0;
        col1 = ts.columnFeature.at(i); // "this"

        for(int j = 0; j < size; j++) {

            correlatedFeatures tmpCF;
            col2 = ts.columnFeature.at(j); // "is"
            if(col1 == col2) continue;

            for(auto iterator = ts.data.begin(); iterator != ts.data.end(); iterator++) {
                tmp1.push_back(iterator->at(col1));
                tmp2.push_back(iterator->at(col2));
            }
            pearsonCoefficient = fabs(pearson(&tmp1[0], &tmp2[0], tmp1.size()));
            if(maxPearsonCo < pearsonCoefficient) {
                maxPearsonCo = pearsonCoefficient;
            }
            // TODO - get maximum corrlation
            // TODO - get rid of double values of features
            // TODO - create line and threshHold
            tmpCF.feature1 = col1;
            tmpCF.feature2 = col2;
            tmpCF.corrlation = maxPearsonCo;
            cf.push_back(tmpCF);
        }

    }

}

vector<AnomalyReport> SimpleAnomalyDetector::detect(const TimeSeries& ts){
	// TODO Auto-generated destructor stub
}

