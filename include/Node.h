#pragma once
#include <vector>

#include "Wire.h"

typedef std::vector<Wire>::iterator WireIter; 

class Node {
public:    
    Node();
    virtual ~Node();

    inline float getOutput() {
        return mOutput;
    } 

    inline void clac() {
        float sum = 0;
        for ( WireIter iter = mWires.begin() ; iter != mWires.end() ; iter++)
        {
            Wire & wire = (*iter); 
            sum += wire.getWeight() * wire.getNode()->getOutput();
        }
    }
   
private:
    float mOutput;
    std::vector<Wire> mWires;
};