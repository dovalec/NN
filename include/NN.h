#pragma once
#include <vector>
#include "Layer.h"
#include "Common.h"

typedef std::vector<Layer> VecLayer;
typedef std::vector<Layer>::iterator VecLayerIter;

class NN {
public:    
    NN();
    virtual ~NN();

    void feedForward(VecFloat & feed);

    void init(int numLayers);

private:
    VecLayer mLayers;
};