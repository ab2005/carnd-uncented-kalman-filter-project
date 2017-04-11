#ifndef TOOLS_H
#define TOOLS_H

#include <vector>
#include "Eigen/Dense"
#include "measurement_package.h"

namespace tools {

  /**
  * A helper method to calculate RMSE.
  */
  Eigen::VectorXd
  CalculateRMSE(const std::vector<Eigen::VectorXd> &estimations,
                const std::vector<Eigen::VectorXd> &groundTruth);

  float CalculateNISPerformance(const std::vector<float> &nis_values,
                                MeasurementPackage::SensorType sensorType);

};

#endif /* TOOLS_H */