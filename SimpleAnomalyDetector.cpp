
#include "SimpleAnomalyDetector.h"
#include "TimeSeries.h"
#include "TimeSeries.cpp"
#include "anomaly_detection_util.h"
#include "anomaly_detection_util.cpp"

SimpleAnomalyDetector::SimpleAnomalyDetector() {
	// TODO Auto-generated constructor stub

}

SimpleAnomalyDetector::~SimpleAnomalyDetector() {
	// TODO Auto-generated destructor stub
}

// for every feature we will save the most correlated feature from the
// list of feature. for example: "this" most correlated to "test" and
// "is" most correlated to "a".
void SimpleAnomalyDetector::learnNormal(const TimeSeries& ts){

    vector<float> tmp1, tmp2;
    string f1, f2;
    string maxCorrelatedFeature;
    float pearsonCorrelation;
    float maxPearsonCorrelation;
    int sizeOfDataTable = ts.data.size();
    int sizeOfVector = 0;
    int maxCorrelatedFeatureIndex = 0;

    // starting from the first feature, retrieving his values and the size of the container.
    for (int i = 0; i < sizeOfDataTable; i++) {
        f1 = ts.columnFeature.at(i); // f1 = "this"
        tmp1 = ts.getValues(f1);
        sizeOfVector = tmp1.size();
        pearsonCorrelation = 0;
        maxPearsonCorrelation = 0;

        // starting from the second feature, retrieving his values
        for(int j = i + 1; j < sizeOfDataTable; j++) {
            //if(i == j ) j++;
            f2 = ts.columnFeature.at(j); // "is"
            tmp2 = ts.getValues(f2);

            // correlation between "this" and "is"
            // computing the correlation between two features.
            pearsonCorrelation = pearson(&tmp1[0], &tmp2[0], sizeOfVector);
            pearsonCorrelation = fabs(pearsonCorrelation); // getting rid of the sign

            // maximizing the pearson correlation and saving the index of the most correlated feature.
            if(maxPearsonCorrelation < pearsonCorrelation) {
                maxPearsonCorrelation = pearsonCorrelation;
                maxCorrelatedFeatureIndex = j;
            }
            // save the feature name
            maxCorrelatedFeature = ts.columnFeature.at(maxCorrelatedFeatureIndex); // "test"
        }

        // if the correlation is bigger then the threshold we consider this feature as
        // correlated and we can save them.
        if(m_threshold < maxPearsonCorrelation) {
            correlatedFeatures tmpCF;
            tmpCF.feature1 = f1;
            tmpCF.feature1 = maxCorrelatedFeature;
            tmpCF.corrlation = maxPearsonCorrelation;
            //tmpCF.threshold = ...
            //tmpCF.lin_reg = ...
            cf.push_back(tmpCF); // inserting into the vector
        }
    }


}

vector<AnomalyReport> SimpleAnomalyDetector::detect(const TimeSeries& ts){
	// TODO Auto-generated destructor stub
}

