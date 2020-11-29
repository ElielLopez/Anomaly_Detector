# Anomaly Detector

## Implementing a simple anomaly detector

### The goal is to find anomaly in a given row of data if there is one.

the simple detector have 2 stages.
1. Learn Data
2. Detect Anomaly

#### Learn Data
in this stage, we recieve a CSV file of a proper flight.
the CSV file contain features names and their values.
for every feature we will check the most correlative feature with Pearson function from the anomaly_detection_util.
afterwards, for every pair of correlative features, create the regression line from their data. in addition calculating the maximum deviation in relation of the line calculated eralier.

#### Detect Anomaly
in this stage, we recieve the data during a flight and for every point we creating from the data we measure the distance from the line we create.
if we detect a distance that is bigger from what we expected to get, we call it as anomaly and we record it.

##### this is not a generic code.
