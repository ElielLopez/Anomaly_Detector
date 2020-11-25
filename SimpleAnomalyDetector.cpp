
#include "SimpleAnomalyDetector.h"

//SimpleAnomalyDetector::SimpleAnomalyDetector() {
//}

SimpleAnomalyDetector::~SimpleAnomalyDetector() {
	// TODO Auto-generated destructor stub
}

// for every feature we will save the most correlated feature from the
// list of feature. for example: "this" most correlated to "test" and
// "is" most correlated to "a".
void SimpleAnomalyDetector::learnNormal(const TimeSeries& ts){

    Line linearRegression;
    vector<float> tmp1, tmp2;
    //map<string,pair< string, float>> mapOfMaxF;
    string f1, f2;
    string maxCorrelatedFeature;
    float pearsonCorrelation;
    float maxPearsonCorrelation;
    float maxDeviation;
    int sizeOfDataTable = ts.columnFeature.size(); //ts.data.size();
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

            // creating Point** for linear regression
            Point* ps[sizeOfVector];
            for(int i=0;i<sizeOfVector;i++)
                ps[i]=new Point(tmp1[i],tmp2[i]);

            // correlation between "this" and "is"
            // computing the correlation between two features.
            pearsonCorrelation = pearson(&tmp1[0], &tmp2[0], sizeOfVector);
            pearsonCorrelation = fabs(pearsonCorrelation); // getting rid of the sign

            // maximizing the pearson correlation and saving the index of the most correlated feature.
            if(maxPearsonCorrelation < pearsonCorrelation) {
                maxPearsonCorrelation = pearsonCorrelation;
                maxCorrelatedFeatureIndex = j;

                // calculating the line with linear regression from previous ex.
                linearRegression = linear_reg(ps, sizeOfVector);
                maxDeviation = maximumDeviation(&tmp1[0], &tmp2[0], sizeOfVector, linearRegression);
            }
            // save the feature name
            maxCorrelatedFeature = ts.columnFeature.at(maxCorrelatedFeatureIndex); // "test"
        }

        // if the correlation is bigger then the threshold we consider this feature as
        // correlated and we can save them.
        if(m_threshold < maxPearsonCorrelation) {
            correlatedFeatures tmpCF;
            tmpCF.feature1 = f1;
            tmpCF.feature2 = maxCorrelatedFeature;
            tmpCF.corrlation = maxPearsonCorrelation;
            tmpCF.threshold = maxDeviation * (1 + minimumThreshold);
            tmpCF.lin_reg = linearRegression;
            cf.push_back(tmpCF); // inserting into the vector
            //mapOfMaxF.insert(f1,pair<string, float>(maxCorrelatedFeature, maxPearsonCorrelation)); // this, a, 0.84
        }
    }
}

vector<AnomalyReport> SimpleAnomalyDetector::detect(const TimeSeries& ts){


    vector<AnomalyReport> ar;
    vector<float> tmp1, tmp2;
    string description, f1, f2;
    float maximumDev;
    float deviationOfPoint;
    int sizeOfCF = cf.size();
    int sizeOfVector;


    for(int i = 0; i < sizeOfCF; i++) {
        f1 = cf[i].feature1;
        f2 = cf[i].feature2;
        Line line = cf[i].lin_reg;
        maximumDev = cf[i].threshold;

        tmp1 = ts.getValues(f1);
        tmp2 = ts.getValues(f2);
        sizeOfVector = tmp1.size();

        for(int j = 0; j < sizeOfVector; j++) {
            Point p(tmp1[j], tmp2[j]);
            deviationOfPoint = dev(p, line);

            if(maximumDev < deviationOfPoint) {
                description = f1 + "-" + f2;
                ar.push_back(AnomalyReport(description, j + 1));
            }
        }
        maximumDev = maximumDeviation(&tmp1[0], &tmp2[0], sizeOfVector, line);
    }

    return ar;
}

