#pragma once
#include <vector>
#include <iostream>

#include "Layer.h"
#include "Common.h"

typedef std::vector<Layer*> VecLayer;
typedef std::vector<Layer*>::iterator VecLayerIter;

typedef std::vector<int> VecTopology;

class Net {
public:    
    Net();
    virtual ~Net();
    
    bool check();
    
    void feedForward(VecFloat & in);
    void backProp(VecFloat & target);
    void calcRmse(VecFloat & target);
    void calcGradients(VecFloat & target);
    void updateWeights();
    void init(VecTopology & topology);
    void debug();

    inline VecLayer & getLayers() {
        return mLayers;
    }

    inline float avgError() {
        return mAvgError;
    }
    
private:
    int mId;
    float mError;
    float mAvgError;
    float mAvgErrorFactor;

    VecLayer mLayers;
};