#pragma once

#include <iostream>

class Node;

class Wire {
public:    
    Wire();
    virtual ~Wire();
    
    bool check();
    
    void setInNode( Node * node);
    void setOutNode( Node * node);

    inline float getWeight() {
        return mWeight;
    }

    float setWeight(float weight) {
        mWeight = weight;
    }

    float setDeltaWeight(float weight) {
        mDeltaWeight = weight;
    }


    inline float getDeltaWeight() {
        return mDeltaWeight;
    }

    inline Node * getInNode() {
        return mInNode;
    }

    inline Node * getOutNode() {
        return mOutNode;
    }

    void debug();

private:
    int mId;
    float mWeight;
    float mDeltaWeight;
    
    Node * mInNode;
    Node * mOutNode;
    
};