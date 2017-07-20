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

#ifndef GRADIENTFOREST_FORESTPREDICTORS_H
#define GRADIENTFOREST_FORESTPREDICTORS_H

#include "forest/ForestPredictor.h"

class ForestPredictors {
public:
  static ForestPredictor instrumental_predictor(uint num_threads,
                                                uint ci_group_size);

  static ForestPredictor quantile_predictor(uint num_threads,
                                            const std::vector<double>& quantiles);

  static ForestPredictor regression_predictor(uint num_threads);
    
  static ForestPredictor locally_linear_predictor(uint num_threads,
                                                  const Data *data,
                                                  const Data *test_data,
                                                  double lambda); 
};


#endif //GRADIENTFOREST_FORESTPREDICTORS_H
