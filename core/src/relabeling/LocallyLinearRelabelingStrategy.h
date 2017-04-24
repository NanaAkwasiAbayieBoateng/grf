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



#ifndef GRADIENTFOREST_LOCALLYLINEARRELABELINGSTRATEGY_H
#define GRADIENTFOREST_LOCALLYLINEARRELABELINGSTRATEGY_H

#include <unordered_map>
#include <vector>
#include "commons/Observations.h"
#include "tree/Tree.h"
#include "relabeling/RelabelingStrategy.h"

class LocallyLinearRelabelingStrategy: public RelabelingStrategy {
public:
    LocallyLinearRelabelingStrategy();
    
    LocallyLinearRelabelingStrategy(double lambda);
    
    std::unordered_map<size_t, double> relabel_outcomes(const Observations& observations,
                                                        const std::vector<size_t>& node_sampleIDs);
    
    DISALLOW_COPY_AND_ASSIGN(LocallyLinearRelabelingStrategy);
    
private:
    double lambda;
};


#endif //GRADIENTFOREST_LOCALLYLINEARRELABELINGSTRATEGY_H

