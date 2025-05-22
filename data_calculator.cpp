#include "data_calculator.h"

double calSumForSolar(const Vector<SensorRecType>& data, SensorDataField type) {
    Vector<double> filledData = dataFieldFilter(data, type);

    double sum = 0.0;

    for (int i = 0; i < filledData.size(); i++) {
        if (filledData[i] >= 100 * SOLARconvertRate) sum += filledData[i];
    }

    return sum;
}

double calSum(const Vector<SensorRecType>& data, SensorDataField type){
    Math<double> math;

    Vector<double> filledData = dataFieldFilter(data, type);
    double sum = math.calSum(filledData);

    return sum;
}

double calAvg(const Vector<SensorRecType>& data, SensorDataField type){
    Math<double> math;

    Vector<double> filledData = dataFieldFilter(data, type);

    double avg = math.calAvg(filledData);


    return avg;
}

double calStardDeviation(const Vector<SensorRecType>& data, double &mean, SensorDataField type){
    Math<double> math;

    Vector<double> filledData = dataFieldFilter(data, type);

    double stdDevi = math.calStandardDeviationCustomParam(filledData, mean);

    return stdDevi;
}

double calsPCC(const Vector<SensorRecType>& data, SensorDataField type1, SensorDataField type2) {
    Math<double> math;

    Vector<double> extractedData1 = dataFieldFilter(data, type1);
    Vector<double> extractedData2 = dataFieldFilter(data, type2);

    double spcc = math.sPPC(extractedData1, extractedData2);

    return spcc;
}