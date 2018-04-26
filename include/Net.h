#pragma once
#include <vector>
#include <iostream>

#include "Layer.h"
#include "Common.h"

typedef std::vector<Layer> VecLayer;
typedef std::vector<Layer>::iterator VecLayerIter;

typedef std::vector<int> VecTopology;

class Net {
public:    
    Net();
    virtual ~Net();
    
    bool check();
    
    void feedForward(VecFloat & feed);

    void calc();
    
    void init(VecTopology & topology);
    void debug();
    
private:
    int mId;
    VecLayer mLayers;
};