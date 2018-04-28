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