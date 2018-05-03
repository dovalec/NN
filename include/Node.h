#pragma once
#include <vector>
#include <iostream>
#include "Common.h"

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

    inline float getWeight(int i) {
        return mWeights[i];
    }

    void initWeights(int nextLayerSize);

    inline VecFloat & getWeights() {
        return mWeights;
    }

    void setBias(float bias);
    void feedForward(Layer * prevLayer, int i);
    float activation(Layer * prevLayer, int i);
    float transfer(float activation);

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
    VecFloat mWeights;
    
};