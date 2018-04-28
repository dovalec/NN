#pragma once
#include <vector>
#include <iostream>

#include "Wire.h"

typedef std::vector<Wire*> VecWire;
typedef std::vector<Wire*>::iterator VecWireIter;

class Layer;
class Node {

public:    
    Node();
    virtual ~Node();
    
    bool check();

    
    inline float getOutput() {
        return mOutputVal;
    } 

    inline float setOutput(float output) {
        mOutputVal = output;
    }

    inline VecWire & getInWires() {
        return mInWires;
    }
    
    inline Wire * getInWire(int n) {
        return mInWires[n];
    }

    inline VecWire & getOutWires() {
        return mOutWires;
    }
    
    inline Wire * getOutWire(int n) {
        return mOutWires[n];
    }

    void setBias(float bias);
    void feedForward(Layer * prevLayer);
    inline float gradient() {
        return mGradient;
    }

    inline void setGradient(float gradient) {
        mGradient = gradient;
    }

    void sumDow();
    void debug();
   
private:
    int mId;
   
    float mOutputVal;
    float mBias;
    float mDow;
    float mGradient;
    VecWire mInWires;
    VecWire mOutWires;
    
};