#pragma once
#include <vector>

#include "Layer.h"

class NN {
public:    
    NN();
    virtual ~NN();

    
private:
    std::vector<Layer> mLayers;
};