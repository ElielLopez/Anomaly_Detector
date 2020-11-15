
#include "SimpleAnomalyDetector.h"
#include "anomaly_detection_util.h"

SimpleAnomalyDetector::SimpleAnomalyDetector() {
	// TODO Auto-generated constructor stub

}

SimpleAnomalyDetector::~SimpleAnomalyDetector() {
	// TODO Auto-generated destructor stub
}


void SimpleAnomalyDetector::learnNormal(const TimeSeries& ts){

    //auto temp = new correlatedFeatures;
    vector<double> tempVec1;
    vector<double> tempVec2;
    int sizeOfArray = 0;

    sizeOfArray = ts.result.size();

	for(int i = 0; i < ts.result.size() - 1; i++) {

        correlatedFeatures* cFeatures = new correlatedFeatures;
        cFeatures->feature1 = ts.result.at(i).first;
        cFeatures->feature2 = ts.result.at(i + 1).first;

        tempVec1 = ts.result.at(i).second;
        tempVec2 = ts.result.at(i + 1).second;

	    cout << cFeatures->feature1 <<" correlated to "<< cFeatures->feature2 <<"?"<< endl;
	    //cout << cFeatures->feature2 << endl;

	    cf.push_back(*cFeatures);
        //cf1->corrlation = pearson(tempVec1, tempVec2, sizeOfArray);
	}
	for(auto it = cf.begin(); it != cf.end(); it++) {
	    cout<<"Round"<<endl;
	    cout<<"inside vector cf: "<<it->feature1<<endl;
	    cout<<"inside vector cf: "<<it->feature2<<endl;
	}
}

vector<AnomalyReport> SimpleAnomalyDetector::detect(const TimeSeries& ts){
	// TODO Auto-generated destructor stub
}

