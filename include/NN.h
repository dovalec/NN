#pragma once
#include <vector>

#include "Layer.h"

class NN {
public:    
    NN();
    virtual ~NN();

    void init(int numLayers);

private:
    std::vector<Layer> mLayers;
};