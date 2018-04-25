#pragma once

class Node;

class Wire {
public:    
    Wire();
    virtual ~Wire();

    void setNode( Node * pNode);

    inline float getWeight() {
        return mWeight;
    }

    inline Node * getNode() {
        return mpNode;
    }


private:
    float mWeight;
    Node * mpNode;
};