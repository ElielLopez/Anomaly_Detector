

#ifndef SIMPLEANOMALYDETECTOR_H_
#define SIMPLEANOMALYDETECTOR_H_

#include "anomaly_detection_util.h"
#include "AnomalyDetector.h"
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>

struct correlatedFeatures{
	string feature1,feature2;  // names of the correlated features
	float corrlation;
	Line lin_reg;
	float threshold;
};

class SimpleAnomalyDetector:public TimeSeriesAnomalyDetector{

	vector<correlatedFeatures> cf;

public:
	SimpleAnomalyDetector();
	virtual ~SimpleAnomalyDetector();

	// does not need to be depand on the o
	// rigin of the information (stream or file...)
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
