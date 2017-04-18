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

#include "forest/ForestPredictors.h"
#include "prediction/InstrumentalPredictionStrategy.h"
#include "prediction/QuantilePredictionStrategy.h"
#include "prediction/RegressionPredictionStrategy.h"
#include "prediction/LocallyLinearPredictionStrategy.h"

ForestPredictor ForestPredictors::instrumental_predictor(uint num_threads,
                                                         uint ci_group_size) {
  std::shared_ptr<PredictionStrategy> prediction_strategy(new InstrumentalPredictionStrategy());
  return ForestPredictor(num_threads, ci_group_size, prediction_strategy);
}

ForestPredictor ForestPredictors::quantile_predictor(uint num_threads,
                                                     const std::vector<double>& quantiles) {
  std::shared_ptr<PredictionStrategy> prediction_strategy(new QuantilePredictionStrategy(quantiles));
  return ForestPredictor(num_threads, 1, prediction_strategy);
}

ForestPredictor ForestPredictors::regression_predictor(uint num_threads) {
  std::shared_ptr<PredictionStrategy> prediction_strategy(new RegressionPredictionStrategy());
  return ForestPredictor(num_threads, 1, prediction_strategy);
}

ForestPredictor ForestPredictors::locally_linear_predictor(uint num_threads,
                                                           double lambda) {
    std::shared_ptr<PredictionStrategy> prediction_strategy(new LocallyLinearPredictionStrategy(lambda));
    return ForestPredictor(num_threads, 1, prediction_strategy);
}
