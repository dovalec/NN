#pragma once

#include <iostream>

class Node;

class Wire {
public:    
    Wire();
    virtual ~Wire();

    void setId(int id) {
        mId = id;    
    }
    
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
    Node * mpNode;
};