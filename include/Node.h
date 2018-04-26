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
    
    
    void setId(int id);
    
    inline float getOutput() {
        return mOutput;
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
    bool moutput;

    float mOutput;
    float mBias;
    VecWire mWires;
};