cmake_minimum_required(VERSION 3.17)
project(Anomaly_Detector_EX2)

set(CMAKE_CXX_STANDARD 11)

add_executable(Anomaly_Detector_EX2 main.cpp timeseries.cpp SimpleAnomalyDetector.cpp anomaly_detection_util.cpp)