/*-------------------------------------------------------------------------------
  This file is part of gradient-forest.

  gradient-forest is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  gradient-forest is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with gradient-forest. If not, see <http://www.gnu.org/licenses/>.
 #-------------------------------------------------------------------------------*/

#ifndef GRADIENTFOREST_QUANTILEPREDICTIONSTRATEGY_H
#define GRADIENTFOREST_QUANTILEPREDICTIONSTRATEGY_H


#include <cstddef>
#include <unordered_map>
#include "commons/Observations.h"
#include "prediction/PredictionStrategy.h"
#include "prediction/PredictionValues.h"

class QuantilePredictionStrategy: public PredictionStrategy {
public:
  QuantilePredictionStrategy(std::vector<double> quantiles);

  size_t prediction_length();
  Prediction predict(size_t sampleID,
                     const std::vector<double>& average_prediction_values,
                     const std::unordered_map<size_t, double>& weights_by_sampleID,
                     const Observations& observations,
                     const Data *data);

  Prediction predict_with_variance(size_t sampleID,
                                   const std::vector<std::vector<size_t>>& leaf_sampleIDs,
                                   const Observations& observations,
                                   uint ci_group_size);

  bool requires_leaf_sampleIDs();
  PredictionValues precompute_prediction_values(
      const std::vector<std::vector<size_t>>& leaf_sampleIDs,
      const Observations& observations);

private:
  std::vector<double> compute_quantile_cutoffs(const std::unordered_map<size_t, double>& weights_by_sampleID,
                                               std::vector<std::pair<size_t, double>>& sampleIDs_and_values);

  std::vector<double> quantiles;
};


#endif //GRADIENTFOREST_QUANTILEPREDICTIONSTRATEGY_H
