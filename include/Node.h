#pragma once
#include <vector>
#include <iostream>
#include "Common.h"
#include "TransformFunc.h"

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

    inline void setWeight(int i, float weight) {
        mWeights[i] = weight;
    }

    inline void setDeltaWeight(int i, float deltaWeight) {
        mDeltaWeights[i] = deltaWeight;
    }
    
    inline float getDeltaWeight(int i) {
        return mDeltaWeights[i];
    }


    void initWeights(int nextLayerSize);

    inline VecFloat & getWeights() {
        return mWeights;
    }

    inline VecFloat & getDeltaWeights() {
        return mDeltaWeights;
    }

    void setBias(float bias);
    void feedForward(Layer * prevLayer, int i);
    float activation(Layer * prevLayer, int i);
    float activationNormal(Layer * prevLayer, int i);

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
    VecFloat mDeltaWeights;
    
    TransformFunc mTransFunc;
};