

#ifndef SIMPLEANOMALYDETECTOR_H_
#define SIMPLEANOMALYDETECTOR_H_

#include "anomaly_detection_util.h"
#include "AnomalyDetector.h"
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>

struct correlatedFeatures{
    //f1 = "this" most correlated to f2 = "test"
	string feature1,feature2;  // names of the correlated features
	float corrlation;
	Line lin_reg;
	float threshold; // TODO- find the max correlation and determine if independent or not
};

class SimpleAnomalyDetector:public TimeSeriesAnomalyDetector{

	vector<correlatedFeatures> cf;

public:
    /*
     * float p_threshold, dev_thresh;
     * SimpleAnomalyDetector()p_threshold(0.9), dev_thresh(0.1){};
     * SimpleAnomalyDetector(float p_threshold, float dev_thresh(0.1):p_threshold(p_threshold), dev_thresh(dev_thresh){};
     * */

    float m_threshold;
    float minimumThreshold; //

	SimpleAnomalyDetector();
	virtual ~SimpleAnomalyDetector();

	// does not need to be depand on the
	// origin of the information (stream or file...)
	// shlav makdin
	virtual void learnNormal(const TimeSeries& ts);

	// return list of reports.
	// every anomaly report has description and time stamp (nekudat zman)
	//giloy harigot
	virtual vector<AnomalyReport> detect(const TimeSeries& ts);

	// returns list of correlated features.
	vector<correlatedFeatures> getNormalModel(){
		return cf;
	}
};

#endif /* SIMPLEANOMALYDETECTOR_H_ */
