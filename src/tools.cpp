#include <stdexcept>
#include "tools.h"

namespace tools {
    Eigen::VectorXd CalculateRMSE(const std::vector<Eigen::VectorXd> &estimations,
                                  const std::vector<Eigen::VectorXd> &groundTruth) {
        
        
        if (estimations.size() == 0 || estimations.size() != groundTruth.size()) {
            throw std::invalid_argument("CalculateRMSE () - Error: Invalid input values.");
        }
        
        Eigen::VectorXd rmse(estimations[0].array().size());
        rmse.fill(0.0);
        
        for (int i = 0; i < estimations.size(); ++i) {
            Eigen::VectorXd res = estimations[i] - groundTruth[i];
            res = res.array() * res.array();
            rmse += res;
        }
        
        rmse /= estimations.size();
        rmse = rmse.array().sqrt();
        
        return rmse;
    }
    
    float CalculateNISPerformance(const std::vector<float> &nis_values,
                                  MeasurementPackage::SensorType sensorType) {
        const float NIS_RADAR_95 = 7.815;
        const float NIS_LIDAR_95 = 5.991;
        
        float limit_95 = sensorType == MeasurementPackage::RADAR ? NIS_RADAR_95 : NIS_LIDAR_95;
        
        int nis_over_95 = 0;
        for (int i = 0; i < nis_values.size(); i++) {
            if (nis_values[i] > limit_95) {
                nis_over_95++;
            }
        }
        
        return (nis_over_95 / (float) nis_values.size());
    }
}
