#pragma once
#include <vector>
#include <iostream>

#include "Wire.h"

typedef std::vector<Wire> VecWire;
typedef std::vector<Wire>::iterator VecWireIter;

class Node {

public:    
    Node();
    virtual ~Node();
    
    bool check();

    
    inline float getOutput() {
        return mOutputVal;
    } 

    inline VecWire & getWires() {
        return mWires;
    }
    
    void setInputOrOutput(bool input, bool output);
    void setBias(float bias);
    void calc();
    void debug();
   
private:
    int mId;
    bool mInput;
    bool mOutput;

    float mOutputVal;
    float mBias;
    VecWire mWires;
};