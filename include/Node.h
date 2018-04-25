#pragma once
#include <vector>

#include "Wire.h"

class Node {
public:    
    Node();
    virtual ~Node();

    inline float getOutput() {
        return mOutput;
    } 
   
private:
    float mOutput;
    std::vector<Wire> mWire;
};