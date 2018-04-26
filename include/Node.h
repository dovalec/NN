#pragma once
#include <vector>

class Wire;

typedef std::vector<Wire*> VecWire;
typedef std::vector<Wire*>::iterator VecWireIter;

class Node {

public:    
    Node();
    virtual ~Node();

    inline float getOutput() {
        return mOutput;
    } 

    void setBias(float bias);
    void clac();
   
private:
    float mOutput;
    float mBias;
    VecWire mWires;
};