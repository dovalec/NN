#pragma once

#include <iostream>

class Node;

class Wire {
public:    
    Wire();
    virtual ~Wire();
    
    bool check();
    
    void setNode( Node * pNode);

    inline float getWeight() {
        return mWeight;
    }

    inline Node * getNode() {
        return mpNode;
    }

    void debug();

private:
    int mId;
    float mWeight;
    float mDeltaWeight;
    
    Node * mpNode;
};