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
    void initWeights(int nextLayerSize);
    
    inline int getSize() {
        return mNodes.size();
    }
    
    void setBias(float bias);
    void setOutputVal(VecFloat & in);

    inline Node * getNode(int n) {
        return mNodes[n]; 
    }
    
    inline VecNode & getNodes() {
        return mNodes;
    }
    
    float sumDow(Node * node, Layer * nextLayer);
    void gradientTarget(VecFloat & target);
    void gradientHidden(Layer * nextLayer);
    void updateWeights(Layer * prevLayer);

    void feedForward(Layer * prevLayer);
    void debug();

private:
    VecNode mNodes;
    TransformFunc mTransformFunc;
    int mId;
};