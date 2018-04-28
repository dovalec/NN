#pragma once
#include <vector>
#include <iostream>

#include "Node.h"
#include "TransformFunc.h"
#include "Common.h"

typedef std::vector<Node*> VecNode;
typedef std::vector<Node*>::iterator VecNodeIter;

class Layer {
public:    
    Layer();
    virtual ~Layer();

    bool check();
    
    void init(int size);
    void connect(Layer * nextLayer);
    
    inline int getSize() {
        return mNodes.size();
    }
    
    void setBias(float bias);
    void setOutputVal(VecFloat & in);

    void target(VecFloat & target);

    inline Node * getNode(int n) {
        return mNodes[n]; 
    }
    
    inline VecNode & getNodes() {
        return mNodes;
    }
    
    inline VecFloat & getTarget() {
        return mTraget;
    }
    
    float sumDow(Node * node, Layer * nextLayer);
    void gradientTarget();
    void gradientHidden(Layer * nextLayer);
    void updateWeights();

    void feedForward(Layer * prevLayer);
    void debug();

private:
    VecNode mNodes;
    VecFloat mTraget;
    TransformFunc mTransformFunc;
    int mId;
};